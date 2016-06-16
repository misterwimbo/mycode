<script type="text/javascript" src="avis-script.js"></script>

<?php

require_once ($_SERVER ['DOCUMENT_ROOT'] . '/admin/functions.inc.php');
require_once ($_SERVER ['DOCUMENT_ROOT'] . '/config.inc.php');
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/param_defaut.inc.php');
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/connexion.inc.php');

loadRequire("Security");
Security::checkSession();
Security::setToken();




$action = $_POST['action'];

$data = "";
switch($action){
	case "load":
	$onglet =  intval($_POST['onglet']);
	$data = loadOnglet($onglet);
	break;

	case "valid" :
	$onglet =  intval($_POST['onglet']);
	$id =  intval($_POST['id']);

	

	$data = loadOnglet($onglet);

	break;
}

echo $data;

function loadOnglet($indice){
  

  if($indice == 1)
  	include('a_valider.php'); 
  
 if($indice == 2)
  	 include('deja_valider.php'); 

  if($indice == 3)
  	 include('refuser.php'); 

	
}