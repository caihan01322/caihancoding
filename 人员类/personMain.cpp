#include "person.h"
#include <iostream>
using namespace std;

int main(void){
	Person person;
	person.setTheName();
	person.setSex();
	person.setBirthPlace();
	person.setBirthDate();
	person.setRace();
	person.setIdCardNumber();
	person.setDadName();
	person.setMomName();
	person.setBloodType();
	person.showInfo();
	return 0;
}
