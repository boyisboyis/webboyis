<?php

	if(!isset($_GET['mode']) || trim($_GET['mode'])==""){
		go_path($GLOBALS['adminpath']);
	}
	$mode = trim($_GET['mode']);
	if($mode=="add"){
		addmenu();
	}
	else if($mode=='gen'){
		gen_addmenu();
	}

	function addmenu(){
		if(!isset($_POST['menuname_th'])){
			go_path($GLOBALS['adminpath']);
		}
		if(!isset($_POST['menuname_en'])){
			go_path($GLOBALS['adminpath']);
		}
		if(!isset($_POST['menuposition'])){
			go_path($GLOBALS['adminpath']);
		}
		if(!isset($_POST['menuparent'])){
			go_path($GLOBALS['adminpath']);
		}

		$menuname_th = trim($_POST['menuname_th']);
		$menuname_en = trim($_POST['menuname_en']);
		$menuposition = trim($_POST['menuposition']);
		$menuparent = trim($_POST['menuparent']);


		$sql = "SELECT count(*) FROM menu WHERE position='".$menuposition."' AND parentid=".$menuparent;
		$seq = sql_getone($sql);
		$sql = "INSERT INTO menu (position, seq, parentid) VALUES ('{$menuposition}', $seq , {$menuparent})";
		$result = sql_simple($sql);
		$sql = "SELECT * FROM menu WHERE position='".$menuposition."' AND seq=$seq AND parentid=".$menuparent;
		$result = sql_getall($sql);
		$sql = "INSERT INTO translate_menu (menuid, menu_th, menu_en) VALUES ({$result[0]['menuid']}, '{$menuname_th}', '{$menuname_en}')";
		$result = sql_simple($sql);

		go_path("?menus=addmenu");
	}

	function gen_addmenu(){
		$sql = "SELECT * FROM menu, translate_menu WHERE menu.menuid=translate_menu.menuid AND menu.parentid=0 ORDER BY menu.seq";
		$topmenu = sql_getall($sql);
		$data = array("th" => array(),"en" => array());
		$n = count($topmenu);

		for($i=0; $i<$n; $i++){
			$sql = "SELECT * FROM menu, translate_menu WHERE menu.menuid=translate_menu.menuid AND menu.parentid=".$topmenu[$i]['menuid']."";
			$parentmenu = sql_getall($sql);
			foreach ($data as $key => $value) {
				$topdata = array(
					"name" => $topmenu[$i]['menu_'.$key],
					"link" => "#"
				);
				$n_parentmenu = count($parentmenu);
				if($n_parentmenu > 0){
					for($j=0;$j<$n_parentmenu;$j++){
						$parentdata =array(
							"name" => $parentmenu[$j]['menu_'.$key],
							"link" => "#"
						);
						$topdata['parent'][] = $parentdata;
					}
				}
				$data[$key][$topmenu[$i]['position']][] = $topdata;
			}
		}
		/*echo "<br><br>";
		echo "<pre>";
		print_r($data);
		echo "</pre>";*/
		gen_json_pattern($data);
	}

?>