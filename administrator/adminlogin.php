<?php
	
	$html = new Html();
	$basepath = Path::getbasepath();
	//echo Path::getbasepath();

?>

<!DOCTYPE html>
<html>
	<head>
		<title>Login Admin</title>
		<?php
			echo $html->script_tag($basepath."/js/ext/angular.min.js", true);
			echo $html->link_tag($basepath."/css/min/main.css");
			echo $html->link_tag($basepath."/css/min/mainadmin.css");
		?>
	</head>
	<body>
		<div id="wrapper">
			
		</div>
	</body>
</html>