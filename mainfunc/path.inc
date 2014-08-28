<?php

	function go_path($path){
		if($path=="" || $path=="/"){
			header("Location:http://localhost/");
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
					else if(isset($path[2]) && $path[2]=='editorcss'){
						return "editorcss";
					}				
				}
				else if(isset($path[1]) && $path[1]=='javascript'){
					if(isset($path[2]) && $path[2]=='admin_login.js'){
						return "adminlogin";
					}
					else if(isset($path[2]) && $path[2]=='editor'){
						return 'texteditor';
					}	
				}
				else if(isset($path[1]) && $path[1]=='controller'){
					if(isset($path[2]) && $path[2]=='login'){
						return "controllerloginadmin";
					}
				}
				else if(isset($path[1]) && $path[1]=='img'){
					if(isset($path[2]) && $path[2]=='editorimg'){
						return "editorimg";
					}
				}
				return "adminauto";
			}
		}
		return "404";
	}

?>