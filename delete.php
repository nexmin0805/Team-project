<?php
$conn = mysqli_connect('127.0.0.1','root','apmsetup', 'han' );


mysqli_select_db($conn, 'han'); //db이름, 식별자번호

mysqli_query($conn, "DELETE FROM phonebook WHERE idx='".$_GET['sIDX']."'");

mysqli_close($conn);
?>


<script>

window.location.href="list.php";

</script>
