$(document).ready(function(){
	$(window).resize(function(){
		var w_w = $(window).width();
		var w_h = $(window).height();
		nav_resize();
		function nav_resize(){
			if(w_w >= 960){
				$("#menu-min .list-main").hide();
			}
		}
	});
});