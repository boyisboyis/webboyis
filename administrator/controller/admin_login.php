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
    $sql = "SELECT auth FROM user WHERE username='".$username."' AND password='".Etc::passwordencode($password)."'";
    $result = DB::get_all($sql);
    if($result=="" || empty($result)){
        echo json_encode(array("status" => "error", "desc" => "username or password is wrong!"));
    }
    else{
        $data = Etc::getAuth($result[0]["auth"]);
        if(isset($data["admin"]) && $data["admin"]==1){
            $_SESSION['member'] = true;
            $_SESSION["admin"] = true;
            echo json_encode(array("status" => "success", "url" => Path::getbasepath()."/boyisadmin"));
        }
        else{
            echo json_encode(array("status" => "error", "desc" => "This username can't access admin page"));
        }
    }
?>