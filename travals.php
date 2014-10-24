<?php

	$path = Etc::getpath();
	$content = new Path();
	$db = new Db();
	//$db->test();
	//echo Html::br();
	if(count($path)>0){
		// travals page
		if(isset($path[0]) && $path[0]=='boyisadmin'){
			$content->requestpath("boyisadmin");
		}
		else{
			$content->requestpath();
		}
	}
	else{
		// main page
		$content->requestpath();
	}

?>