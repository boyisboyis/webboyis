<?php

	$path = Etc::getpath();
	$content = new Path();
	$db = new Db();
	//$db->test();
	//echo Html::br();
	//print_r($path);
	echo Etc::passwordencode("123261129");
	echo "<br/>";
	echo Etc::genuserid();
	if(count($path)>0){
		// travals page
		if(isset($path[0]) && $path[0]=='boyisadmin'){
			if(Etc::login()){
				$content->requestPath("boyisadmin");
			}
			else{
				if(isset($path[1]) && $path[1]=="controller"){
					if(isset($path[2])){
						if($path[2]=='login'){
							$content->requestController("loginadmin");
						}
						else if($path[2]=='checklogin'){
							$content->requestController("checkloginadmin");
						}
					}
				}else{
					$content->requestPath("boyisadmin_login");
				}
			}
		}
		else if(isset($path[0]) && ($path[0]=='js' || $path[0]=='css')){
			//$content->requestpath("ext",$path[1]);
		}
		else{
			$content->requestPath();
		}
	}
	else{
		// main page
		$content->requestPath();
	}

?>