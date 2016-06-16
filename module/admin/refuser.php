<?php
require_once ($_SERVER ['DOCUMENT_ROOT'] . '/admin/functions.inc.php');
require_once ($_SERVER ['DOCUMENT_ROOT'] . '/config.inc.php');
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/param_defaut.inc.php');
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/connexion.inc.php');

loadRequire("Security");
Security::checkSession();
Security::setToken();
?>
<input type="hidden" id="token" value="<?php echo Security::getToken();?>" />
 <?php

/*******************************************************************************
Affichage des commentaires refusés   statut = 9

l'acceptation  les passe en statut 2
possibilité d'effacer le commentaire
possibilité davoir des infos sur le posteur ;Nom,Mail,IP


les commenatires qui n'ont pas étés validés par email n'apparaissent pas

********************************************************************************/


$sql_refuse_comment           = "SELECT * FROM avis_clients WHERE statut = 9 ORDER BY date_publication DESC  " ;
$req_refuse_comment           =  mysqli_query ( DataBase::getInstance(), $sql_refuse_comment );
$nb_commentaires_refuse       =  mysqli_num_rows ( $req_refuse_comment );

include('print_etoile.php');

echo '<br>
	  <div class="bloc-design">
	  <div class="bloc-design-header ui-widget-header ui-corner-all">
	  <div class="bloc900hauttitre"><div class="titrebloc">
	  <center>COMMENTAIRES REFUS&Eacute;S</center>
	  </div></div></div>
	  <div class="bloc-design-content ui-widget ui-widget-content">
		';



if ($nb_commentaires_refuse   > 0) {
	echo '<div  style="clear:both;">
		  <table  cellspacing="0" cellpadding="0" width="100%" style="border:1px solid #EFA335;">
		  <thead>  
		  <tr class="nodrag">';

	echo '<td width="210" align="center" style="border:1px solid #EFA335;">
	      <div class = "header_menu">Nom</div></td>';

	echo '<td width="650" align="center" style="border:1px solid #EFA335;">
	      <div class = "header_menu">Commentaire</div></td>';

	echo '<td width="210" align="center" style="border:1px solid #EFA335;">
	     <div class = "header_menu">Date</div></td>';

	echo '<td width="210" align="center" style="border:1px solid #EFA335;">
	      <div class = "header_menu">Note</div></td>';

	echo '<td align="center" width="95px" style="font-size: 95%; border:1px solid #EFA335;">
	      <div class = "header_menu">Action</div></td>
		  </tr>
		  </thead>  
		  <tbody>';
	



	while ( $tab_comment = mysqli_fetch_array ( $req_refuse_comment  ) ) {
		$nom             = $tab_comment ['nom'];
		$date            = $tab_comment ['date_publication'];
		$commentaire     = $tab_comment ['commentaire'];
		$email           = $tab_comment ['email'];
		$id              = $tab_comment ['id'];
		$note            = $tab_comment ['note'];

		
		
		echo '<tr id="' . $nom . '">';
	    echo '<td align="center">';
	    echo' <div class = "rslt_menu">'.$nom.'</div>';
	    echo' &nbsp;</td>';

		echo '<td align="center">';
		echo' <div class = "rslt_menu">'.$commentaire.'</div>';
	    echo' &nbsp;</td>';

		echo '<td align="center">';
        echo' <div class = "rslt_menu">'.$date.'</div>';
	    echo' &nbsp;</td>';

		echo '<td align="center">';
        echo  print_etoile($note);
		echo' &nbsp;</td>';

		
		
		echo '
	         <td align="center">
		     <a href="javascript:ShowCustomDialog('.$id.');">

		    

	         <div class="ico_nettoyer" title="effacer d&eacute;finitivement"></div>
		     </a> 


		     <a href="javascript:edit_statut('.$id.',2,'.$indice.')">
			 <div class="ico_valider" title="Valider"></div>
		     </a>

		     <a href="javascript:full_view('.$id.','.$indice.')">
			 <div class="ico_voir" title="Informations"></div>
		     </a>

	         </td>
             </tr> ';

	}
	
	echo '<tbody>
				</table></div>';
	
} else {//si aucun commentaire refusé
	echo '<div  style="width :100%; float:left;">Aucun commentaires &agrave; afficher</div>';
}


	

    echo '
         </div>
	     <div class="bloc-design-footer ui-widget-header ui-corner-all"><div id="titre_pied_page_g"></span></div>
	     </div></div>';

	echo '
	     <div id = "infos_commentaire"></div>';


?>