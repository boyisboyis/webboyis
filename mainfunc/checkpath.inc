<?php

	function check_path($path){
		$path_get = get_path_include($path);
		print_r($path_get);
		if($path_get=='index.php'){
			//go_path('');
		}
		elseif($path_get=='content'){
			//go_include_path('show_topic.php');
		}
		else{
			not_found();
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
			if($value!='' && $value!='webboyis'){
				$newpath[$n++] = $value;
			}
		}
		return $newpath;
	}

?>