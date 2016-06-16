<?php

?>
<style type="text/css">

.etoile
{
	color:orange;
	padding-top: 12px;


}


</style>
<?php



function print_etoile($aff_etoile){

echo '<div class = "etoile">';
for($i = 0 ; $i < 5 ; $i++){


	if($aff_etoile > 0.5)
		echo '<i class="fa fa-star" aria-hidden="true"></i>';
	else if($aff_etoile <= 0)
		echo '<i class="fa fa-star-o" aria-hidden="true"></i>';
	else if($aff_etoile <= 0.5)
		echo '<i class="fa fa-star-half-o" aria-hidden="true"></i>';
	

	$aff_etoile--;
}
echo '</div>';

}


?>