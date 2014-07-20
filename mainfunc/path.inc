<?php

	function go_path($path){
		if($path=="" || $path=="/"){
			header("Location:http://localhost/webboyis/");
		}
		else{
			header("Location:".$path);
		}
	}

	function get_path_file($path){
		if(!isset($path[0])){
			return "/";
		}
		else{
			if($path[0]=='content'){
				return "content";
			}
			else if($path[0]=='adminwebboyis'){
				return "adminauto";
			}
		}
		return "404";
	}

?>