#ifndef NATIONS_H
#define NATIONS_H

#define MAX_NATION_NUM 56+2

#include <iostream>
#include <fstream> 
#include <stdlib.h> //函数system需要
using namespace std;

class Nations{
	private:
		int code[MAX_NATION_NUM];
		string name[MAX_NATION_NUM];
	public:
		void getNationTable();
		void showNationTable();
		string getNation();
};

#endif
