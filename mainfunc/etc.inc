<?php

session_start();

function set_global_path(){
	$GLOBALS['basepath'] = $_SERVER['SERVER_NAME'];
	$GLOBALS['adminpath'] = $_SERVER['SERVER_NAME'].'/administrator/';
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

function user_create($type='name'){
	if($type=='name'){
		return "Supagrid Tangsermsit";
	}
	else if($type=='email'){
		return "boyisboyis261129@gmail.com";
	}	
}

?>