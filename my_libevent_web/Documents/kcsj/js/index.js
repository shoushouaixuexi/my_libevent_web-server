var now = 0;
var sum = 4;
var timer =null;
var ali = list.getElementsByTagName('li');
function $(id){return document.getElementById(id);}
function lunbo(){
	if(now == sum-1){
		now =0;
	}
	else{
		now++;
	}
	$("pic").src = "img/lunbo"+now+".jpg";
	tab();
}
function restart(){
	init();
}
function pause(){
	clearInterval(timer);
	}
function init(){
	timer = setInterval('lunbo()',2000);//两秒触发一次
}
function tab(){
	for(var i =0;i<ali.length;i++){//清空所有按钮选中样式以及图片显示样式
		ali[i].className=" ";
	}
	ali[now].className="active";
}