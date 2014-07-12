<?php

	function go_path($path){
		if($path=="" || $path=="/"){
			header("Location:http://localhost/webboyis/");
		}
		else{
			header("Location:".$path);
		}
	}

	function go_include_path($path){
		if($path=='content'){
			include("show_topic.php");
			exit();
		}
	}

?>