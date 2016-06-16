<?php
require_once ($_SERVER ['DOCUMENT_ROOT'] . '/admin/functions.inc.php');
require_once ($_SERVER ['DOCUMENT_ROOT'] . '/config.inc.php');
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/param_defaut.inc.php');
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/connexion.inc.php');


loadRequire("Security");
Security::checkSession();
Security::setToken();




if (isset($_POST['id']) && isset($_POST['statut']) && isset($_POST['onglet']))
{
	$id     = intval($_POST['id']);
	$statut = intval($_POST['statut']);
	$onglet = intval($_POST['onglet']);




	/**
	requete sql validation du commentaire.... ou pas :)
	**/

	$sql_edit_statut           = "UPDATE avis_clients SET statut = $statut WHERE id = $id" ;
	$req_edit_statut           = mysqli_query ( DataBase::getInstance(), $sql_edit_statut );

	 if(!$req_edit_statut) 
	             echo '<br/>'.mysqli_error(DataBase::getInstance ()).'<br/>'.$sql_edit_statut;



	/**

	**/

	echo"<script>valid($id,$onglet)</script>";
}





?>