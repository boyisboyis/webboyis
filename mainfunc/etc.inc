<?php

session_start();

function set_global_path(){
	$GLOBALS['basepath'] = "http://".$_SERVER['SERVER_NAME'];
	$GLOBALS['adminpath'] = "http://".$_SERVER['SERVER_NAME'].'/adminwebboyis/';
	$GLOBALS['devicetype'] = get_device();
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

?>