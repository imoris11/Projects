<?php
//Conection to the database using mysqli as the plugin
$dbhost = "chiefobitv.db.6471559.hostedresource.com";
$dbuser = "chiefobitv";
$dbname = "chiefobitv";
$dbpass = "Hndimkoh@1";
$connection = mysqli_connect($dbhost, $dbuser, $dbpass,$dbname);
if(mysqli_connect_errno()){
	die("Database connection failed: ". mysqli_connect_error(). "(".mysqli_connect_errno().")");
}
?>