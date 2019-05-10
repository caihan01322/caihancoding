#include "dates.h"

int Dates::maxDay(int y,int m){
	if(m==2 && ((y%4==0 && y%100!=0) || (y%400==0)))
		return d[m]+1; 
	else  return d[m];
}

int Dates::getYear() const{
	return m_iYear;
}

int Dates::getMonth() const{
	return m_iMonth;
}

int Dates::getDay() const{
	return m_iDate;
}

bool Dates::getFlag() const{
	return m_bFlag;
}

void Dates::showDates() const{
	cout << m_iYear << "." << m_iMonth << "."<< m_iDate;
}

void Dates::operator = (string dates){
	int y, m, d;
	int a, b, c;
	a = sscanf(dates.c_str(), "%d.%d.%d", &y, &m, &d);
			
	if (a == 3){
		if(y>0 && m>=1 && m<=12 && d>=1 && d<=maxDay(y,m)){
			m_iYear = y;
			m_iMonth = m;
			m_iDate = d;
			m_bFlag = true;
		}
	}
}
