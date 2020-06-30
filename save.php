 <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	
	<?php 

	$conn = mysqli_connect("127.0.0.1", "root", "apmsetup", "han");

	$select_query = "insert into  phonebook('name', 'tel')values('".$_POST['name']."', '".$_POST['tel']."')";
	
	
	$result = mysqli_query($conn , $select_query );


    ?>
