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
				if(isset($path[1]) && $path[1]=='css'){
					if(isset($path[2]) && $path[2]=='admin_main.css'){
						return "admincss";
					}					
				}
				else if(isset($path[1]) && $path[1]=='javascript'){
					if(isset($path[2]) && $path[2]=='admin_login.js'){
						return "adminlogin";
					}	
				}
				else if(isset($path[1]) && $path[1]=='controller'){
					if(isset($path[2]) && $path[2]=='login.php'){
						return "controllerloginadmin";
					}
				}
				return "adminauto";
			}
		}
		return "404";
	}

?>