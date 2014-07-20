<?php

	function check_path($path){
		$path_get = get_path_file($path);
		if($path_get=="" || $path_get=='/'){
			include('home.php');
		}
		else if($path_get=="content"){
			include('content/show_topic.php');
		}
		else if($path_get=='404'){
			include('errormessages/404.php');
		}
	}

	function get_path(){
		$path = "";
		if(dirname(!empty($_SERVER['REQUEST_URI']))){
			$path = $_SERVER['REQUEST_URI'];
		}
		else if(!empty($_SERVER['PHP_SELF'])){
			$path = $_SERVER['PHP_SELF'];
		}
		else{
			$path = str_replace('\\','/',__FILE__);
		}
		$pathexe = explode('/', $path);
		$newpath = array();
		$n = 0;
		foreach ($pathexe as $key => $value) {
			if($value!=''){
				$newpath[$n++] = $value;
			}
		}
		return $newpath;
	}

?>