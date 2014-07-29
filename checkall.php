<?php

	include("mainfunc/include.php");
	set_global_path();
	GLOBAL $connection_db;
	init_db();
	$get_path = get_path();
	check_path($get_path);
	close_db();
	//echo $_SERVER['DOCUMENT_ROOT'];
	//echo '<br>';
	//check_path(dirname(__FILE__)); 
?>