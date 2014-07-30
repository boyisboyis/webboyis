
$(document).ready(function(){

	$(window).on("keypress", function(e){
		var keycode = e.charCode;
		if(keycode==13){
			check_login();
		}
	});

	$("#submit-form").on('click', function(){
		check_login();
	});	
});


function check_login(){
	var username = $("#username").val();
	var password = $("#password").val();
	if($.trim(username)==""){
		$("#login-error").html("Please input username");
	}
	else if($.trim(password)==""){
		$("#login-error").html("Please input password");
	}
	else{
		login_admin(username, password);	
	}	
}

function login_admin(username, password){
	$.ajax({
		method : "POST",
		url : "adminwebboyis/controller/login.php",
		data : {
			"username" : username,
			"password" : password
		},
		success: function(response){
			if($.trim(response)=='ok'){
				location.reload();
			}
			else{
				$("#login-error").html(response);
			}
		}
	});
}