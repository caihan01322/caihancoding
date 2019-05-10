#include "person.h"
#include "nation.h"
#include "dates.h"

void Person::setTheName(){
	cout << "请输入姓名(形式为汉字)：";
	theName = setName();
	cout << "\n请按任意键继续...";
	getch(); 
    system("cls"); //清屏
}
void Person::setSex(){
	cout << "请输入性别(格式为\"男\"或\"女\")：";
	cin >> sex; 
	while(sex!="男"&&sex!="女"){
		system("cls"); //清屏
		sex = "";
		cout << "\a输入的性别有误，请重新输入：";
		cin >> sex;
	}
	while(getchar()!='\n') continue;
	cout << "\n请按任意键继续...";
	getch(); 
    system("cls"); //清屏
}
void Person::setBirthPlace(){
	cout << "请输入出生地：";
	cin >> birthPlace;
	cout << "\n请按任意键继续...";
	getch(); 
    system("cls"); //清屏
}
void Person::setBirthDate(){
	cout << "请输入出生日期(格式为\"xxxx.xx.xx\")：";
	cin >> birthDate;
	dates = birthDate;
	while(!dates.getFlag()){
		system("cls"); //清屏
		cout << "\a输入的日期有误，请重新输入：";
		dates = birthDate = ""; 
		cin >> birthDate;
		dates = birthDate;
	}
	cout << "\n请按任意键继续...";
	getch();
    system("cls"); //清屏
}
void Person::setRace(){
	cin.get(); 
	
	struct Nation nation[MAX_NATION_NUM];
    
    //将存放民族代码、名称对照表的文件读入数组nation中
    //n=民族代码、名称对照表的记录条数
    int n=getNationTable(nation);
    
    //用户输入(选择)民族(代码)
    //index=用户输入的民族代码在民族表中对应的下标
    int index=getIndexOfChoice(nation,n);
    
    printf("你刚输入的民族是：[%02d]",nation[index].code);
    printf("%s\n",nation[index].name);
    
    race = nation[index].name;
    cout << "\n请按任意键继续...";
	getch(); 
    system("cls"); //清屏
}
void Person::setIdCardNumber(){
	cout << "请输入公民身份证件编号：";
	while(1){
		bool flag;
		cin >> idCardNumber;
		if(idCardNumber.length() != ID_CARD_LEN){
			system("cls"); //清屏			
			cout << "\a输入的公民身份证件编号有误，请重新输入：";			
			continue;
		}
		else flag = judgeLegal(idCardNumber);
		if(flag) break;
		else {
			system("cls"); //清屏			
			cout << "\a输入的公民身份证件编号有误，请重新输入：";
			continue;
		}
	}
	cout << "\n请按任意键继续...";
	getch();
    system("cls"); //清屏
}
void Person::setDadName(){
	cin.get();
	
	cout << "请输入父姓名(形式为汉字)：";
	dadName = setName();
	while(this->dadName == this->theName){
		system("cls"); //清屏
		this->dadName = "";
		cout << "\a姓名重复，请重新输入：";
		dadName = setName();
	}
	cout << "\n请按任意键继续...";
	getch(); 
    system("cls"); //清屏
}
void Person::setMomName(){
	cout << "请输入母姓名(形式为汉字)：";
	momName = setName();
	while(this->momName == this->dadName || this->momName == this->theName){
		system("cls"); //清屏
		this->momName = "";
		cout << "\a姓名重复，请重新输入：";
		momName = setName();
	}
	cout << "\n请按任意键继续...";
	getch(); 
    system("cls"); //清屏
}
void Person::setBloodType(){
	enum bloodTypes {a,b,ab,o,other};
	int bloodCode = -1;
	bool isFlag = false;
	cout << "[0]A型 [1]B型 [2]AB型 [3]O型 [4]其他" << endl; 
	cout << "请输入血型代码和<回车>：";
	while(1){
		bloodCode=getchar();
		if (bloodCode!='\n') {
			ungetc(bloodCode,stdin);			//不是<回车>，将按键退回输入缓冲区
			scanf("%d",&bloodCode);
			while (getchar()!='\n') continue;	//跳过本行剩余的其他字符和<回车>键
		}
		switch(bloodCode){
			case a:{
				bloodType = "A型";
				isFlag = true;
				break;
			}
			case b:{
				bloodType = "B型";
				isFlag = true;
				break;
			}
			case ab:{
				bloodType = "AB型";
				isFlag = true;
				break;
			}
			case o:{
				bloodType = "O型";
				isFlag = true;
				break;
			}
			case other:{
				bloodType = "其他";
				isFlag = true;
				break;
			}
			default:{
				isFlag = false;
				system("cls"); //清屏
				cout << "[0]A型 [1]B型 [2]AB型 [3]O型 [4]其他" << endl; 
				cout << "\a输入错误，请重新输入血型代码和<回车>：";
				break;
			}
		}
		if(isFlag) break;
	}
	cout << "\n请按任意键继续...";
	getch(); 
    system("cls"); //清屏
}
void Person::showInfo() const{
	cout << "人员信息如下：" << endl; 
	cout << "姓名：" << theName << endl;
	cout << "性别：" << sex << endl;
	cout << "出生地：" << birthPlace << endl;
	cout << "出生日期：" << birthDate << endl;
	cout << "民族：" << race << endl;
	cout << "公民身份证件编号：" << idCardNumber << endl;
	cout << "父姓名：" << dadName << endl;
	cout << "母姓名：" << momName << endl;
	cout << "血型：" << bloodType << endl;
}
bool Person::judgeChinese(string name){
	for(int i=0; i<name.length(); i++)
	{
		if(name[i]>0 && name[i]<255)//扩充的ASCII字符范围为0-255,如是,处理一个字节
		{
			return false;
		}
		else//<0,>255的是汉字,处理两个字节
		{
			++i;
		}
	}
	return true;
}
string Person::setName(){
	char _name[40];
	string name;
	cin.getline(_name,40);
	while(cin.fail()){
		system("cls"); //清屏
		cout << "\a输入的姓名过长，请重新输入：";
		cin.clear();	//将流中的所有状态值都重设为有效值
		cin.sync();		//清空流 
		cin.getline(_name,40);
	}
	name = (string)_name;
	while(name.length()<4 || !judgeChinese(name)){
		system("cls"); //清屏
		name = "";
		cout << "\a输入的姓名错误，请重新输入：";
		cin.sync();
		cin.getline(_name,40);
		while(cin.fail()){
			system("cls"); //清屏
			cout << "\a输入的姓名过长，请重新输入：";
			cin.clear();	//将流中的所有状态值都重设为有效值
			cin.sync();		//清空流 
			cin.getline(_name,40);
		}
		name = (string)_name;
	}
	return name;
}
char Person::createCheckDigit(string idCardNumber){
	int sum = 0;
	for(int i=0;i<ID_CARD_LEN-1;i++){
		switch(i){
			case 0:{
				sum += (idCardNumber[i]-'0') * 7;
				break;
			}
			case 1:{
				sum += (idCardNumber[i]-'0') * 9;
				break;
			}
			case 2:{
				sum += (idCardNumber[i]-'0') * 10;
				break;
			}
			case 3:{
				sum += (idCardNumber[i]-'0') * 5;
				break;
			}
			case 4:{
				sum += (idCardNumber[i]-'0') * 8;
				break;
			}
			case 5:{
				sum += (idCardNumber[i]-'0') * 4;
				break;
			}
			case 6:{
				sum += (idCardNumber[i]-'0') * 2;
				break;
			}
			case 7:{
				sum += (idCardNumber[i]-'0') * 1;
				break;
			}
			case 8:{
				sum += (idCardNumber[i]-'0') * 6;
				break;
			}
			case 9:{
				sum += (idCardNumber[i]-'0') * 3;
				break;
			}
			case 10:{
				sum += (idCardNumber[i]-'0') * 7;
				break;
			}
			case 11:{
				sum += (idCardNumber[i]-'0') * 9;
				break;
			}
			case 12:{
				sum += (idCardNumber[i]-'0') * 10;
				break;
			}
			case 13:{
				sum += (idCardNumber[i]-'0') * 5;
				break;
			}
			case 14:{
				sum += (idCardNumber[i]-'0') * 8;
				break;
			}
			case 15:{
				sum += (idCardNumber[i]-'0') * 4;
				break;
			}
			case 16:{
				sum += (idCardNumber[i]-'0') * 2;
				break;
			}
		} 
	}
	char checkDigit;
	switch(sum%11){
		case 0:{
			checkDigit = '1';
			break;
		}
		case 1:{
			checkDigit = '0';
			break;
		}
		case 2:{
			checkDigit = 'X';
			break;
		}
		case 3:{
			checkDigit = '9';
			break;
		}
		case 4:{
			checkDigit = '8';
			break;
		}
		case 5:{
			checkDigit = '7';
			break;
		}
		case 6:{
			checkDigit = '6';
			break;
		}
		case 7:{
			checkDigit = '5';
			break;
		}
		case 8:{
			checkDigit = '4';
			break;
		}
		case 9:{
			checkDigit = '3';
			break;
		}
		case 10:{
			checkDigit = '2';
			break;
		}
	}
	return checkDigit;
}
bool Person::judgeLegal(string idCardNumber){
	if(!isdigit(idCardNumber[ID_CARD_LEN-1]) && idCardNumber[ID_CARD_LEN-1]!='X')
		return false;
	for (int i=0;i<ID_CARD_LEN-1;i++)
		if(!isdigit(idCardNumber[i]))
			return false;
	
	fstream f("AdministrativeDivision.txt");	//打开内容只读文件
	if(!f.good()){
        cout << "\a存放行政区划的文件不存在！" << endl;
        exit(-1);
    }
    int adminDivCode;
	string oppositeArea;
    bool isMatch = false;
	while(f >> adminDivCode >> oppositeArea){
		if(adminDivCode == atoi(idCardNumber.substr(0,6).c_str())){ 
			isMatch = true;
			break;
		}	
	}
	if(!isMatch) return false;

	if(dates.getYear() 	!= atoi(idCardNumber.substr(6,4).c_str()))	return false;
	if(dates.getMonth()	!= atoi(idCardNumber.substr(10,2).c_str())) return false;
	if(dates.getDay() 	!= atoi(idCardNumber.substr(12,2).c_str())) return false;
	
	if(sex == "男") if(atoi(idCardNumber.substr(14,3).c_str())%2 == 0) return false;
	if(sex == "女") if(atoi(idCardNumber.substr(14,3).c_str())%2 == 1) return false;
	
	if(createCheckDigit(idCardNumber) != idCardNumber[ID_CARD_LEN-1]) return false;
	return true;
}
