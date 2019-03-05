# caihancoding

“日历”笔记：

1、

/*定义双休日字体色*/

tr>td, tr>td+td+td+td+td+td+td{

    color:#B3222B;

}

/*1、将所有td设置为红色；2、将周六设置为红色*/

/*定义工作日字体色*/

tr>td+td{

    color:#333333;

}

/*1、将除第一列外所有td设置为红色；2、因css优先级最后一列无法覆盖*/

/* > :子选择器；+ :相邻选择器,前者兄，后者弟。*/

2、

var firstDay = (new Date(currentYear,currentMonth, 1)).getDay();

var monthDays = [31, leapYear(currentYear), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

var rows =  Math.ceil((monthDays[currentMonth] + firstDay) / 7);   //行数算法

//当前月天数[+第一天星期数(0-7:日-六)=填满第一行],/7再取整后为日期行数

//Math.ceil()返回值是大于等于 x，并且与它最接近的整数。

var dateTable = document.getElementById("dateTable");

for(var i=0 ; i<rows ; i++){

    var tr = document.createElement("tr");
    
    for(var k=0 ; k<7; k++){
    
        var date = i*7+k-firstDay+1;    //日期算法
        
        //日期数=到日期前一个的总格数-填满第一行的格数+1
         
3、$(document).ready(function(){

$('#dateTable tr').each(function(i){

    $(this).children('td').each(function(j){
    
    var dateStr1 = (new Date(currentYear,currentMonth,(i*7+j-firstDay+1))).toISOString();
    
    var tdMemo1 = localStorage.getItem(dateStr1);
    
    if(tdMemo1!=null) $(this).css("text-decoration","underline");})
    
})

});

each() 方法规定为每个匹配元素规定运行的函数。

语法：$(selector).each(function(index,element))

参数：function(index,element)	

描述：必需。为每个匹配元素规定运行的函数。

（ index - 选择器的 index 位置

element - 当前的元素（也可使用 "this" 选择器））

Eg. $('div').each(function (i){

  //i就是索引值
  
  //this 表示获取遍历每一个dom对象
  
});

“聊天机器人”笔记：

1、$("#cheat").keyup(function(){

    if(event.keyCode == 13){

    $("#button").click();

}

});

/*当按钮被松开时，发生 keyup 事件。

语法：$(selector).keyup()*/

/*(event.keyCode == 13)：键码13为回车

irFirefox2.0中不支持 window.event.keyCode,

但是我们可以用event.which代替。

但是为了使其能更具有普遍的兼容性，最好用event.keyCode|| event.which.*/

2、$("#list").scrollTop($("#list")[0].scrollHeight);

/*scrollTop() 方法返回或设置匹配元素的滚动条的垂直位置。

scroll top offset 指的是滚动条相对于其顶部的偏移。

如果该方法未设置参数，则返回以像素计的相对滚动条顶部的偏移。

语法：$(selector).scrollTop(offset)

参数	  描述

offset	可选。规定相对滚动条顶部的偏移，以像素计。*/

/*scrollHeight: 获取对象的滚动高度。

scrollWidth:获取对象的滚动宽度。

一定要写$("#list")[0].scrollHeight;而不是$("#list").scrollHeight;*/
