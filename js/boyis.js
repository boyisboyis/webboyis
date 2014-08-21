$(document).ready(function(){
	$(".nav-toggle").on("click", function(){
		$(this).siblings().filter('.nav-menu').show();
	});
});
