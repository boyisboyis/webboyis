<?php

	function style_construct($head,$body){
		$str = "<!DOCTYPE html>";
		$str .= "<html>";
		$str .= "<head>";
		$str .= web_meta_tags();
		$str .= link_style('css/main.css');
		$str .= web_script();
		$str .= "</head>";
		$str .= "<body>";
		$str .= $body;
		$str .= "</body>";
		$str .= "</html>";
		return $str;
	}

	function style_header(){
		$str = "<div id='header-wrap'>";
		$str .= "<div id='menu-min' class='nav'>";
		$str .= "<button class='nav-toggle'>";
		$str .= "<span class='icon-nav'></span>";
		$str .= "<span class='icon-nav'></span>";
		$str .= "<span class='icon-nav'></span>";
		$str .= "</button>";
		$str .= style_content_menu_left();
		$str .= "</div>";
/*		$str .= "<div id='menu-min-select'>";
		
		$str .= "</div>";*/
		$str .= "<div id='h-box'>";
		$str .= "<div id='h-box-logo'>";
		$str .= "</div>";
		$str .= "<div  id='h-box-title'>";
		$str .= "<h2>BOYIS</h2>";
		$str .= "</div>";
		$str .= "<div  id='h-box-description'>";
		$str .= "<span>description</span>";
		$str .= "</div>";
		$str .= "</div>";
		$str .= "</div>";
		return $str;
	}

	function style_footer(){
		$str = "<div id='footer-wrap'>";
		$str .= "</div>";
		return $str;
	}

	function style_mainweb($content){
		$str = "<div id='wrapper' class='style-mainweb'>";
		$str .= style_header();
		$str .= "<div id='content-wrap'>";
		$str .= "<div id='content-menu' class='grid-col'>";
		$str .= "<div id='content-menu-left' class='col-2'>";
		$str .= style_content_menu_left();
		$str .= "</div>";
		$str .= "<div id='content-menu-center' class='col-10'>";
		$str .= $content;
		$str .= "</div>";
		/*$str .= "<div id='content-menu-right'>";
		$str .= "</div>";*/
		$str .= "</div>";
		$str .= "</div>";
		$str .= style_footer();
		$str .= "</div>";
		return $str;
	}

	function style_content_menu_left(){
		$data_m_left = get_json_data("data/", "menuleft.json");
		$data = con_json_to_array($data_m_left);
		$data_use = $data[$GLOBALS['language']]['left'];
		$n = count($data_use);
		$str = "";
		$str .= "<ul class='list-main nav-menu'>";
		for($i=0;$i<$n;$i++){
			$str .= "<li class='list-h'><a href='".$data_use[$i]['link']."'>".$data_use[$i]['name']."</a></li>";
			if(isset($data_use[$i]['parent'])){
				$data_parent = $data_use[$i]['parent'];
				$o = count($data_parent);
				$str .= "<ul class='list-parent'>";
				for($j=0;$j<$o;$j++){
					$str .= "<li class='list-p'><a href='".$data_parent[$j]['link']."'>".$data_parent[$j]['name']."</a></li>";
				}
				$str .= "</ul>";
			}
		}
		$str .= "</ul>";
		return $str;
	}

	function web_meta_tags(){
		$str = "";
		$str .= meta_tags(
			array(
				"name" => "viewport",
				"content" => "'width=device-width, initial-scale=1, maximum-scale=1'"
			)
		).
		meta_tags(
			array(
				"http-equiv" => "content-type",
				"content" => "text/html",
				"charset" => "utf-8"
			)
		);
		//<meta http-equiv="content-type" content="text/html; charset=utf-8">
		return $str;
	}

	function web_script(){
		$str = "";
		$str .= javascript_tags("js/ext/min/jquery.min.js");
		$str .= javascript_tags("js/min/boyis.min.js");
		return $str;
	}

?>