#include "nations.h"

#include <iostream>
using namespace std;

void Nations::getNationTable(){
	fstream file("nationCodeName.txt");	//打开内容只读文件
	if(!file.good()){
        cout << "\a存放民族代码、名称对照表的文件不存在！" << endl;
        exit(-1);
    }
    int n = 0;
    while (file >> code[n] >> name[n]) n++;
    file.close();
}
void Nations::showNationTable(){
	for (int i=0;i<MAX_NATION_NUM;i++){
		if(code[i]<10) 
			cout << "[0" << code[i] << "]" << left << setw(10) << name[i];
		else 
			cout << "[" << code[i] << "]" << " " << name[i] << " ";
		if(i%8 == 0 && i!=0) cout << endl; 
	}
}
string Nations::getNation(){
	while(1){
		char theCode = getchar(); 
		if(theCode!='\n'){
        	ungetc(theCode,stdin);   //不是<回车>，将按键退回输入缓冲区
        	scanf("%d",&theCode);
        	while (getchar()!='\n') continue;	//跳过本行剩余的其他字符和<回车>键
    	}
    	else{
			theCode = 1;	//用户直接按<回车>，得到默认值：汉族(1)
			cout << endl << "你输入的民族为：[1]汉族" << endl; 
			return name[0];
		}           
    	for(int i=0;i<MAX_NATION_NUM;i++){
			if(theCode == code[i]) return name[i];
		}
		system("cls"); //清屏
		showNationTable(); 
		cout << endl << "\a输入的民族代码有误，请重新输入：";	
	}
}
