
$(document).ready(function(){

	$("#submit-form").on('click', function(){
		check_login();
	});	
});


function check_login(){
	var username = $("#username").val();
	var password = $("#password").val();
	console.log(username+ " : "+password);
	$.ajax({
		method : "POST",
		url : "adminwebboyis/controller/login.php",
		data : {
			"username" : username,
			"password" : password
		},
		success: function(response){
			console.log(response);
		}
	});
}