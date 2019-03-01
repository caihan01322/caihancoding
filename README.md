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

//当前月天数[+第一天星期数(0-7:日-六)=填满第一行],取整后为日期行数

//Math.ceil()返回值是大于等于 x，并且与它最接近的整数。

var dateTable = document.getElementById("dateTable");

for(var i=0 ; i<rows ; i++){

    var tr = document.createElement("tr");
    
    for(var k=0 ; k<7; k++){
    
        var date = i*7+k-firstDay+1;    //日期算法
        
        //日期数=到日期前一个的总格数-填满第一行的格数+1
