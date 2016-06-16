/*charge l'onglet */
   function onglet(onglet){

	$.ajax({
	   		type: "POST",			   		
	   		url: "avis-clients-ajax.php",	
	   		data : {
	   		action : "load",
	   		token : $("#token").val(),					
			onglet : onglet
			},
			success :  function ( data ) {
				$("#resultat").html(data);
			}  		
	   	});


}



	function edit_statut(id,statut,onglet){
		$.ajax({
	   		type: "POST",			   		
	   		url: "edit_statut.php",	
	   		data : {
	   		token : $("#token").val(),	
	   		onglet:onglet,
	   		statut: statut,					
			id : id
			},
			success :  function ( data ) {
				console.log(data)
				$("#resultat").html(data);
		 
			}  		
	   	});
		
	}




    function erase_comment(id,onglet){
		$.ajax({
	   		type: "POST",			   		
	   		url: "erase_comment.php",	
	   		data : {					
			id : id,
			token : $("#token").val(),
			onglet : onglet
			},
			success :  function ( data ) {
				console.log(data)
				$("#resultat").html(data);
			}  		
	   	});
		
	}


	function valid(id,onglet){
	$.ajax({
	   		type: "POST",			   		
	   		url: "avis-clients-ajax.php",	
	   		data : {
	   		action : "valid",
	   		token : $("#token").val(),
	   		id : id,				
			onglet : onglet
			},
			success :  function ( data ) {
				$("#resultat").html(data);
			}  		
	   	});



}


function full_view(id,onglet){
  

$.ajax({
	   		type: "POST",			   		
	   		url: "infos-avis-clients-ajax.php",	
	   		data : {
	   		action : "valid",
	   		
	   		id : id,
	   		onglet : onglet			
			
			},
			success :  function ( data ) {

             
            $("#infos_commentaire").html(data);

}  		
	   	});


	
}







/*impossible de mettre 'close' in ne ferme pas la boite de dialogue...???? j'ai mis destroy ça fonctionne avec 
erase_comment(id,3); <<< le 3 correspond à l'onglet ici 'COMMENTAIRES REFUSES' */


function ShowCustomDialog(id)
			{
                
			  ShowDialogBox(id,'Effacer ce commentaire ?','<br> Voulez effacer ce commentaire DEFINITIVEMENT ? <br>','Oui','Non');
			}

            function ShowDialogBox(id,title, content, btn1text, btn2text) {
                var btn1;
                var btn2;

               
                //$("#infos_commentaire").html(content);

                $("#infos_commentaire").dialog({
                	id : id,
                    resizable: false,
                    title: title,
                    modal: true,
                    width: '400px',
                    height: 'auto',
                    show: 'clip',
                    hide: 'clip',

                    buttons: [
                                    {
                                        text: btn1text,
                                        "class": btn1,
                                        click: function () {
                                                                                    
                                            $("#infos_commentaire").dialog('destroy');
                                              erase_comment(id,3);

                                        }
                                    },
                                    {
                                        text: btn2text,
                                        "class": btn2,
                                        click: function () {
                                           $("#infos_commentaire").dialog('destroy');
                                           
                                           
                                            
                                        }
                                    }
                                ]
                });
            }







