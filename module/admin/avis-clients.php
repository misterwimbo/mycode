<?php
require_once ($_SERVER ['DOCUMENT_ROOT'] . '/admin/functions.inc.php');
require_once ($_SERVER ['DOCUMENT_ROOT'] . '/config.inc.php');
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/param_defaut.inc.php');
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/connexion.inc.php');


/**
SECURITE
**/
loadRequire("Security");
Security::checkSession();
Security::setToken();



if (! true_user_session ()) {
	header ( "location:/admin/index.php5" );
	exit ();
}

if (isset ( $_GET ['num'] ))
	$num = intval ( $_GET ['num'] );
else {
	header ( "location:/admin/index.php" );
	exit ();
}

$USERS = info_user_session ();

if ($USERS ['type_user'] == 1 || $USERS ['type_user'] == 2 || $USERS ['type_user'] == 3 || true_droit_module_redacteur ( $USERS ['id_user'], $num )) {
} else {
	header ( "location:/admin/index.php" );
	exit ();
}

$id_du_module = 24;
// test si module activé
if (! true_exist_num_mod ( $id_du_module, $num )) {
	header ( "location:/admin/index.php" );
	exit ();
}


/**

**/



?>
<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>Gestion des commentaires</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<link rel="stylesheet" href="/admin/style.css" type="text/css" />
<link rel="stylesheet" href="avis.css" type="text/css" />
<script type="text/javascript" src="avis-script.js"></script>

<?php 
include_once($_SERVER['DOCUMENT_ROOT'].'/admin/admin_scripts.phtml'); 
?>


</head>
<body>
<input type="hidden" id="token" value="<?php echo Security::getToken();?>" />

<?php

/**

**/
 /* statut commentaires dans la bdd
 0 >> commentaire à confirmer par le client 
 1 >> commentaire confirmer par le client à confirmer par le webmaster
 2 >> commentaire en ligne
 9 >> commentaire refusé/modéré
 */

/**

**/
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/admin/menu-xhtml.php');
?>
</head>

	<body>

		<!-- 

		Par defaut se charge l'onglet 'Commentaires à valider' 
	         Changer le numero dans la fonction javascript ci dessous pour afficher un autre onglet

             onglet 1: commentaires à valider
             onglet 2: commentaires   valides
             onglet 3: commentaires   refusés

	     -->
	     
	 <script type="text/javascript">javascript:onglet(1);</script>
	 
	<center>
	<div class="bloc-design">
        <ul>
				    <li><a class = "choix" href="javascript:onglet(1);" >Commentaires &agrave; valider</a></li>
				    <li><a class = "choix" href="javascript:onglet(2);">Commentaires valides</a></li>
				    <li><a class = "choix" href="javascript:onglet(3);">Commentaires refus&eacute;s</a></li>
		</ul>
	 </center>
    </div>
    <div id="resultat">
   

    </div>


	<?php
    include_once ($_SERVER ['DOCUMENT_ROOT'] . '/admin/pied-xhtml.php');
    ?>

	</body>

</html>
