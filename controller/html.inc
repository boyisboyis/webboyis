<?php

	class Html{

		function br(){
			return "<br/>";
		}

		function script_tag($link, $async=false){
			$a = ($async==true)?"async=async":"";
			return "<script type=\"text/javascript\" src=".$link." ".$a."></script>";
		}

		function link_tag($link){
			return "<link rel=\"stylesheet\" type=\"text/css\" href=".$link.">";
		}

	}

?>