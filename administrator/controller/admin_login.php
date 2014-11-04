<?php

	header('Content-Type: application/json');

	$postdata = file_get_contents("php://input");
    $request = json_decode($postdata);
    @$username = $request->username;
    @$password = $request->password;
    if($username==""){
    	echo json_encode(array("status" => "error", "desc" => "username empty"));
    	die();
    }
    if($password==""){
    	echo json_encode(array("status" => "error", "desc" => "password empty"));
    	die();
    }
    echo json_encode(array("status" => "success"));
   /* echo $username;
    echo $password;
	//$username = $_POST['username'];
	echo '[{"Name":"test"}]';*/

?>