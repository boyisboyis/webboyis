<?php

session_start();

function set_global_path(){
	$GLOBALS['basepath'] = "http://".$_SERVER['SERVER_NAME'];
	$GLOBALS['adminpath'] = "http://".$_SERVER['SERVER_NAME'].'/adminwebboyis/';
	$GLOBALS['devicetype'] = get_device();
	$GLOBALS['language'] = 'th';
}

function get_device(){
	require_once('othermainfunc/mobile_detect/Mobile_Detect.php');
	$detect = new Mobile_Detect;
	$device = 'desktop';
	if ( $detect->isMobile() ) {
		$device = 'mobile';
	}

// Any tablet device.
	if( $detect->isTablet() ){
		$device = 'tablet';
	}

// Exclude tablets.
	if( $detect->isMobile() && !$detect->isTablet() ){
		$device = 'mobile';
	}

// Check for a specific platform with the help of the magic methods:
	// if( $detect->isiOS() ){

	// }

	// if( $detect->isAndroidOS() ){

	// }
	return $device;
}

function check_username_code($username){

}

function user_create($type='name'){
	if($type=='name'){
		return "Supagrid Tangsermsit";
	}
	else if($type=='email'){
		return "boyisboyis261129@gmail.com";
	}	
}

function code_str($str){
	$code = "";
	$md5 = md5($str);
	$length = strlen($md5);
    for ($i = 0; $i < $length; $i++) 
    { 
    	if(is_numeric($md5[$i])){
    		$code .= chr($md5[$i]+97);
    	}
    	else{
    		$code .= ord($md5[$i]) - 97;
    	}    	
    }
    $code = md5(base64_encode($code));
    return $code;
}

function decode_str($code){
	$md5 = "";
	$length = strlen($code);
	for ($i = 0; $i < $length; $i++) {
		if(is_numeric($code[$i])){
			$md5 .= chr($code[$i]+97);
		}
		else{
			$md5 .= ord($code[$i])-97;
		}
	}
	return $md5;
}

function check_md5($code1,$code2){
	if($code1==$code2){
		return true;
	}
	return false;
}

function get_text($key){
	require_once("language/th.lang");
	if(isset($lang[$key])){
		return $lang[$key];
	}
	return ""; 
}

function create_file_json($arr, $path, $name){
	$file = fopen($path.$name.".json","w");
	if (flock($file,LOCK_EX)){
		fwrite($file,json_encode($arr));
	  // release lock
	  	flock($file,LOCK_UN);
		fclose($file);
	  	return "{'status' : 'complete','message' : 'write complete'}";
	}
	else{
		fclose($file);
		return "{'status' : 'error', 'code' : 1, 'message' : 'locking error'}";
	}	
}

function write_file(){
	
}

function gen_json_pattern($arr = array()){
	if(is_array($arr) && count($arr) > 0){
		//echo json_encode($arr);
		create_file_json($arr, "data/","menuleft");
	}
}

function get_json_data($path, $file){
	if(file_exists($path.$file)){
		return file_get_contents($path.$file);
	}
	return "";
}

function con_json_to_array($json){
	$arr = json_decode($json, true);
	if(is_null($arr)){
		return "";
	}
	return $arr;
}

function get_language_arr(){
	return array("th", "en");
}


?>