
<?php
require_once ($_SERVER ['DOCUMENT_ROOT'] . '/admin/functions.inc.php');
require_once ($_SERVER ['DOCUMENT_ROOT'] . '/config.inc.php');
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/param_defaut.inc.php');
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/connexion.inc.php');

loadRequire("Security");
Security::checkSession();
Security::setToken();

/*****************
manque une securité là non ? le jeton je ne suis pas sur d'avoir bien mis la securité 
*****************/

?><input type="hidden" id="token" value="<?php echo Security::getToken();?>" />


<?php

/*******************************************************************************
Affichage des commentaires à valider   statut = 1 

le refus les passe en statut 9
l'acceptation les passe en statut 2
possibilité davoir des infos sur le posteur ;Nom,Mail,IP

les commenatires qui n'ont pas étés validés par email n'apparaissent pas

********************************************************************************/



$num = 24;
$sql_to_validate_comment      = "SELECT * FROM avis_clients WHERE statut = 1 ORDER BY date_publication DESC  " ;
$req_to_validate_comment      = mysqli_query ( DataBase::getInstance(), $sql_to_validate_comment );
$nb_commentaires_a_valider    = mysqli_num_rows ( $req_to_validate_comment );


include('print_etoile.php');


echo '<br>
	  <div class="bloc-design">
	  <div class="bloc-design-header ui-widget-header ui-corner-all">
	  <div class="bloc900hauttitre"><div class="titrebloc">
	  <center>COMMENTAIRES  &nbsp; &Agrave; &nbsp; VALIDER</center>
	  </div></div></div>
	  <div class="bloc-design-content ui-widget ui-widget-content">
		';



if ($nb_commentaires_a_valider > 0) {
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
		';
	



	while ( $tab_comment = mysqli_fetch_array ( $req_to_validate_comment ) ) {
		$nom             = $tab_comment ['nom'];
		$date            = $tab_comment ['date_publication'];
		$commentaire     = $tab_comment ['commentaire'];
		$email           = $tab_comment ['email'];
		$id              = $tab_comment ['id'];
		$note            = $tab_comment ['note'];

		
	
		echo '<tr id="' . $nom . '">';
	    echo '<td align="center">';
	    echo'<div class = "rslt_menu">'.$nom.'</div>';
	    echo' &nbsp;</td>';

		echo '<td align="center">';
		echo'<div class = "rslt_menu">'.$commentaire.'</div>';
	    echo' &nbsp;</td>';

		echo '<td align="center">';
        echo'<div class = "rslt_menu">'.$date.'</div>';
	    echo' &nbsp;</td>';

		echo '<td align="center">';
        echo print_etoile($note);
		echo' &nbsp;</td>';

		

		
	
		/* dans la fonction javascript : 9 = refuser         2 = valider */
		echo '
	  <td align="center">

		  <a href="javascript:edit_statut('.$id.',9,'.$indice.')">
		  <div class="ico_supprimer" title="Refuser"></div>
		  </a> 

		  <a href="javascript:edit_statut('.$id.',2,'.$indice.')">
		  <div class="ico_valider" title="Valider"></div>
		  </a>

		  <a href="javascript:full_view('.$id.','.$indice.')">
		  <div class="ico_voir" title="Informations"></div>
		  </a>

	  </td></tr> ';

	}
	
	echo '<tbody>
		  </table></div>';
	
} else {//si aucun commentaires
	echo '<div  style="width :100%; float:left;">Aucun commentaires &agrave; afficher</div>';
}


	

    echo '
    </div>
    <div class="bloc-design-footer ui-widget-header ui-corner-all"><div id="titre_pied_page_g"></span></div>
	</div></div>';

	echo '<div id = "infos_commentaire"></div>';




?>

