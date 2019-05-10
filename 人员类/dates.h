#ifndef DATES_H
#define DATES_H

#include <iostream>
using namespace std;

const static int d[]={31,31,28,31,30,31,30,31,31,30,31,30,31};

class Dates{
	private:
		int m_iYear;
		int m_iMonth;
		int m_iDate;
		bool m_bFlag;
	public:
		Dates(){
			m_iYear = 2000;
			m_iMonth = 1;
			m_iDate = 1;
			m_bFlag = false;
		}
		int maxDay(int y,int m);
		int getYear() const;
		int getMonth() const;
		int getDay() const;
		bool getFlag() const;
		void showDates() const;
		void operator = (string dates);
};

#endif
