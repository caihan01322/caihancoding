//定义当前年月日,星期数组
var d = new Date();
var currentYear = d.getFullYear();  
var currentMonth =  d.getMonth();
var currentDate = d.getDate();
var weekArray = ['周日' ,'周一', '周二', '周三', '周四', '周五', '周六' ];

//显示当前年月
var time = currentYear + " 年 " + add0(currentMonth+1) + " 月 ";
document.getElementById('time').innerHTML=time;

//月不足位补零
function add0(data) {
    if (data>= 0 && data <= 9)
         data = "0" + data;
    return data;
}

//判断是否闰年
function leapYear(year) {
    if(year%4==0 && year%100!=0 || year%400==0) 
        return 29;
    else return 28;
}

//打印当前日历
var firstDay = (new Date(currentYear,currentMonth, 1)).getDay();
var monthDays = [31, leapYear(currentYear), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
var rows =  Math.ceil((monthDays[currentMonth] + firstDay) / 7);   //行数算法
var dateTable = document.getElementById("dateTable");

for(var i=0 ; i<rows ; i++){ 
    var tr = document.createElement("tr");
    for(var k=0 ; k<7; k++){  
        var date = i*7+k-firstDay+1;    //日期算法  
        var td = document.createElement("td");
        if(date>0 && date<=monthDays[currentMonth])
            td.innerText = date;
        else td.innerText = "*";
        if(date == currentDate) 
            td.setAttribute("bgColor","pink");
        tr.appendChild(td);
    }
    dateTable.appendChild(tr);
}
if(rows==5){
    var tr = document.createElement("tr");
    for(var k=0 ; k<7; k++){
        var td = document.createElement("td");
        tr.appendChild(td);
        td.innerText = "*";
        dateTable.appendChild(tr);
    }
}

//跳转指定年月
function createTable(){
    var year = document.getElementById("year").value;
    var month = document.getElementById("month").value - 1;
    var firstDay = (new Date(year, month, 1)).getDay();
    var monthDays = [31, leapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    var rows =  Math.ceil((monthDays[month] + firstDay) / 7);   //行数算法
    var dateTable = document.getElementById("dateTable");

    if(year>=0 && year%1==0 && month+1>=1 && month+1<=12){
        table.removeChild(dateTable);
    var time = year + " 年 " + add0(month+1) + " 月 ";
    document.getElementById('time').innerHTML=time;
    var newDateTable = document.createElement("tbody");
    newDateTable.id = "dateTable";
    document.getElementById("table").appendChild(newDateTable);
    for(var i=0 ; i<rows ; i++){ 
        var tr = document.createElement("tr");
        for(var k=0 ; k<7; k++){  
            var date = i*7+k-firstDay+1;    //日期算法 
            var td = document.createElement("td");
            if(date>0 && date<=monthDays[month])
                td.innerText = date;
            else td.innerText = "*";
            if(year==currentYear && month==currentMonth && date==currentDate)
                td.setAttribute("bgColor","pink");
            tr.appendChild(td);}
        newDateTable.appendChild(tr);}
    if(rows==5){
        var tr = document.createElement("tr");
        for(var k=0 ; k<7; k++){
            var td = document.createElement("td");
            tr.appendChild(td);
            td.innerText = "*";
            newDateTable.appendChild(tr);}
        }
    document.getElementById("year").value = document.getElementById("month").value = "";      
    }

    else{
        alert("输入不合法，请重新输入！");
        document.getElementById("year").value = "";
        document.getElementById("month").value = "";}

    $(document).ready(function(){
        $("td").click(function(){
            var tdDate = this.innerText;    //this的使用
            var tdDay = (new Date(year,month,tdDate)).getDay();
            var tdDateStr = (new Date(year,month,tdDate)).toISOString();
            var memo = localStorage.getItem(tdDateStr);
            if(tdDate!=0)
              alert("日期：" + year + "年" + (month+1) + "月" + tdDate + "日 "
              + "星期：" + weekArray[tdDay] + "\n备忘录：" + memo);
        });
    });
}

//获取日期信息
$(document).ready(function(){
    $("td").click(function(){
      var tdDate = this.innerText;    //this的使用
      var tdDay = (new Date(currentYear,currentMonth,tdDate)).getDay();
      var tdDateStr = (new Date(currentYear,currentMonth,tdDate)).toISOString();
      var memo = localStorage.getItem(tdDateStr);
      if(tdDate!=0&&tdDate!="*")
        alert("日期：" + currentYear + "年" + (currentMonth+1) + "月" + tdDate + "日 "
        + "星期：" + weekArray[tdDay] + "\n备忘录：" + memo);
    });
});

//保存备忘录信息
function memo(){    
var memoYear = document.getElementById("memoYear").value; 
var memoMonth = document.getElementById("memoMonth").value;
var memoDate = document.getElementById("memoDate").value;
var monthDays = [31, leapYear(memoYear), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
var memoDateStr = (new Date(memoYear,memoMonth-1,memoDate)).toISOString();
var info = document.getElementById("info").value;

if(memoYear>=0 && memoYear%1==0 && memoMonth>=1 && memoMonth<=12 && memoDate>=1 && 
memoDate<=monthDays[memoMonth-1] && memoYear!="" && memoMonth!="" && memoDate!="" && info!=""){
localStorage.setItem(memoDateStr,info);
alert("日期：" + memoYear + "年" + memoMonth + "月" + memoDate + "日 "
+ "\n内容：" + info + "\n备忘录保存成功！");
document.getElementById("memoYear").value=document.getElementById("memoMonth").value=
document.getElementById("memoDate").value=document.getElementById("info").value="";}
};

//删除备忘录信息
function clean(){
    var clearYear = document.getElementById("clearYear").value; 
    var clearMonth = document.getElementById("clearMonth").value;
    var clearDate = document.getElementById("clearDate").value;
    var monthDays = [31, leapYear(clearYear), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    var clearDateStr = (new Date(clearYear,clearMonth-1,clearDate)).toISOString();

    if(clearYear>=0 && clearYear%1==0 && clearMonth>=1 && clearMonth<=12 && clearDate>=1 &&
    clearDate<=monthDays[clearMonth-1] && clearYear!="" && clearMonth!="" && clearDate!="" && clearMemo!=""){
    var clearMemo = localStorage.getItem(clearDateStr);
    var ok = confirm("你要删除内容为：" + clearMemo + "\n是否确认删除？");
    if(ok){
        localStorage.removeItem(clearDateStr);
        alert("删除成功！");}
    document.getElementById("clearYear").value=document.getElementById("clearMonth").value=
    document.getElementById("clearDate").value="";}
}