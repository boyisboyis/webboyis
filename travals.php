<?php

	$db = new DB($host, $db_name, $db_username, $db_password);
	unset($host, $db_name, $db_username, $db_password);
	$content = new Path();
	$direction = new Direction();
	$path = $content->getpath();
	$array = array(
		"boyisadmin" => "travel_admin",
		"js" => "travel_component",
		"css" => "travel_component"
	);
	if(count($path) > 0 && isset($array[$path[0]])){
		$direction->$array[$path[0]]($content, $path);
	}
	else{
		$content->requestPath();
	}
	die();

?>