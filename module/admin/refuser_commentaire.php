<?php
require_once ($_SERVER ['DOCUMENT_ROOT'] . '/admin/functions.inc.php');
require_once ($_SERVER ['DOCUMENT_ROOT'] . '/config.inc.php');
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/param_defaut.inc.php');
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/connexion.inc.php');


loadRequire("Security");
Security::checkSession();
Security::setToken();




if (isset($_POST['id']))
	header ( "location:/admin/index.php" );


$id = intval($_POST['id']);


/**
requete sql refus du commentaire
**/

$sql_validate_comment      = "UPDATE avis_clients SET statut = 9 WHERE id = $id" ;
$req_validate_comment      = mysqli_query ( DataBase::getInstance(), $sql_validate_comment );

 if(!$req_validate_comment) 
             echo '<br/>'.mysqli_error(DataBase::getInstance ()).'<br/>'.$sql_validate_comment;

/**

**/