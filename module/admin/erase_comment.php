<?php
require_once ($_SERVER ['DOCUMENT_ROOT'] . '/admin/functions.inc.php');
require_once ($_SERVER ['DOCUMENT_ROOT'] . '/config.inc.php');
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/param_defaut.inc.php');
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/connexion.inc.php');


loadRequire("Security");
Security::checkSession();
Security::setToken();

/* je reste persuadé qu'effacer un commentaire doit faire parti des options ;) */





if (isset($_POST['id']) && isset($_POST['onglet']))
{

$id          = intval($_POST['id']);
$onglet      = intval($_POST['onglet']);


?>
<style type="text/css">

/*cache le bouton close il provoqué un probleme 'esthétique' */
     /*.ui-dialog-titlebar-close {
    visibility: hidden; 
     }*/

      

      .ui-dialog .ui-dialog-title {
      text-align: center;
      width: 100%;
      }



</style>


<?php

/**
requete sql effacement du commentaire
**/

$sql_erase_comment           = "DELETE FROM avis_clients  WHERE id = $id" ;
$req_erase_comment           = mysqli_query ( DataBase::getInstance(), $sql_erase_comment);

 if(!$req_erase_comment) 
             echo '<br/>'.mysqli_error(DataBase::getInstance ()).'<br/>'.$_erase_comment;

/**

**/

echo"<script>valid($id,$onglet)</script>";

}



