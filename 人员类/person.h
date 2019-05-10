#ifndef PERSON_H
#define PERSON_H

#define ID_CARD_LEN 18

#include "dates.h"
#include <iostream>
#include <fstream>
#include <string>	//函数substr需要 
#include <conio.h>	//函数getch需要 
using namespace std;

class Person{
	private:
		string theName;
		string sex;
		string birthPlace;
		string birthDate;
		Dates dates;
		string race;
		string idCardNumber;
		string momName;
		string dadName;
		string bloodType;
		bool judgeChinese(string name);
		string setName();
		bool judgeLegal(string idCardNumber);
		char createCheckDigit(string idCardNumber);
	public:
		void setTheName();
		void setSex();
		void setBirthPlace();
		void setBirthDate();
		void setRace();
		void setIdCardNumber();
		void setMomName();
		void setDadName();
		void setBloodType();
		void showInfo() const;		
};

#endif
