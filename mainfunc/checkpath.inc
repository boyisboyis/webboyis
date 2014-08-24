<?php

	function check_path($path){

		$path_get = get_path_file($path);
		if($path_get=="" || $path_get=='/'){
			include('home.php');
		}
		else if($path_get=="content"){
			include('content/show_topic.php');
		}
		else if($path_get=='adminauto'){
			include('administrator/view.php');
		}
		else if($path_get=='admincss'){
			include('administrator/css/admin_main.css');
		}
		else if($path_get=='adminlogin'){
			include('administrator/func/controller/min/admin_login.min.js');
		}
		else if($path_get=='controllerloginadmin'){
			include('administrator/controller/login.php');
		}
		else if($path_get=='parserruleswysi'){
			include("administrator/ext/wysihtml5/parser_rules/advanced.js");
		}
		else if($path_get == 'wysihtml5'){
			include("administrator/ext/wysihtml5/dist/wysihtml5-0.3.0.min.js");
		}
		else if($path_get == 'wysihtml5css'){
			include("administrator/css/wysihtml5.css");
		}
		else if($path_get == 'wysihtml5editorcss'){
			include("administrator/css/editor.css");
		}
		else if($path_get == "wysihtml5barimg"){
			header('Content-type:image/png');
			echo readfile("administrator/ext/wysihtml5/website/img/spr_toolbar_icons_r1.png");
			/*$file_info = apache_lookup_uri("administrator/ext/wysihtml5/website/img/spr_toolbar_icons_r1.png");
			header('content-type: ' . $file_info -> content_type);
			virtual("administrator/ext/wysihtml5/website/img/spr_toolbar_icons_r1.png");*/
			//file_get_contents("administrator/ext/wysihtml5/website/img/spr_toolbar_icons_r1.png");
		}
		else if($path_get=='404'){
			include('errormessages/404.php');
		}
		else{
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