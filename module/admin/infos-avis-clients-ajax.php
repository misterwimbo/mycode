<?php

require_once ($_SERVER ['DOCUMENT_ROOT'] . '/admin/functions.inc.php');
require_once ($_SERVER ['DOCUMENT_ROOT'] . '/config.inc.php');
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/param_defaut.inc.php');
include_once ($_SERVER ['DOCUMENT_ROOT'] . '/connexion.inc.php');

include('print_etoile.php');



$infos_avis = array();
if (isset($_POST['id']) )
{
	$id     = intval($_POST['id']);



            
			$query = "SELECT * FROM avis_clients";
			$result = mysqli_query (DataBase::getInstance (), $query );

			
            
			while($infos = mysqli_fetch_array($result)){

				if($infos['id'] == $id)
				{
                    array_push($infos_avis,$infos);
				}
			
			}


?>



<style type="text/css">
     
     label[for="infos_avis"]
     {
     	float:left;
     	display:inline-block;
     	width: 10%;

     }

     #infos_avis
     {
       
       font-size:1.1em;
     }

    

    /*cache le bouton close il provoqué un probleme 'esthétique' */
     .ui-dialog-titlebar-close {
    visibility: hidden; 
     }

      .ui-dialog {

        font-size : 18px;
        font-family:  cursive;
        padding-top: 10px;
       
      }

      .ui-dialog .ui-dialog-title {
      text-align: center;
      width: 100%;
      }



     


</style>

<div id="infos_avis"  style="display:none;">

    

  
        
       
            <br><br>
        	<label for  = "infos_avis"><b>nom:</b></label>
        	<?php echo $infos_avis[0]['nom']; ?><br><br>

        	<label for  = "infos_avis"><b>email:</b></label>
        	<?php echo $infos_avis[0]['email']; ?><br><br>

        	<label for  = "infos_avis"><b>ip:</b></label>
        	<?php echo $infos_avis[0]['IP']; ?><br><br>

        	
        	
        
</div>

<script type="text/javascript">


$("#infos_avis").dialog({

	title: "Informations sur le posteur",
    modal: true,
    draggable: false,
    resizable: false,
    position: { my: 'top', at: 'top+350' },
    show: 'clip',
    hide: 'clip',
    width: 400,
   

 
   
});

//fermer  la boite de dialogue en cliquant à coter

$(document).ready(function()
{
    $(document.body).on("click", ".ui-widget-overlay", function()
    {
        $.each($(".ui-dialog"), function()
        {
            var $dialog;
            $dialog = $(this).children(".ui-dialog-content");
            if($dialog.dialog("option", "modal"))
            {
                $dialog.dialog("close");
            }
        });
    });;
});



</script>





<?php
}
?>
