<?php
	
	print_r($_SESSION);
	unset($_SESSION["member"],$_SESSION["admin"]);
	if(!Etc::login() || !Etc::loginadmin()){
		echo "test";
	}

?>

<!DOCTYPE html>
<html>
	<head>
		<title>Admin Page:BoyI's</title>
	</head>
	<body>
		
	</body>
</html>