<?php

	function get_path_include($path){
		if(!isset($path[0])){
			return "";
		}
		else{
			if($path[0]=='index.php'){
				return $path[0];
			}
			else if($path[0]=='content'){
				return $path[0];
			}
		}
	}

?>