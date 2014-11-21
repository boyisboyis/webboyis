<?php

	class Direction{

		public function travel_admin($controller, $path){
			if(isset($path[0]) && $path[0]=='boyisadmin'){
				if(Etc::login()){
					$controller->requestPath("boyisadmin");
				}
				else{
					if(isset($path[1]) && $path[1]=="controller"){
						if(isset($path[2])){
							if($path[2]=='login'){
								$controller->requestController("loginadmin");
							}
							else if($path[2]=='checklogin'){
								$controller->requestController("checkloginadmin");
							}
						}
					}else{
						$controller->requestPath("boyisadmin_login");
					}
				}
			}
		}

		public function travel_component($controller, $path){
			
		}

	}

?>