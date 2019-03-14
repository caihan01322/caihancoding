//创建一个假想并且不实用的密码类Password。
#include <iostream>
#include <cctype>
#include <string>
using namespace std; 

class Password {
public:
    Password(){
		pwd = "Abcd1234";
	}
	Password(string _s){
		if(_s.size()>=8 && _s.size()<=32 && judge(_s))
			pwd = _s;
		else pwd = "Abcd1234";
	}
	Password(const Password &password){
		pwd = password.pwd;
	}
	void chgPWD(){
		pwd = "Abcd1234";
	}
	void chgPWD(string _s){
		if(_s.size()>=8 && _s.size()<=32 && judge(_s))
			pwd = _s;
	}	
    friend ostream& operator<<(ostream& stream,Password s){
	  stream << "(" << s.pwd << ")" <<endl;
 	  return stream;  	
	}
	bool operator==(const Password& s){
		if(s.pwd==pwd)
			return true;
		else return false;
	}
	bool operator!=(const Password& s){
		if(s.pwd!=pwd)
			return true;
		else return false;
	}
	bool judge(string s);
	private:
    	string pwd;  //密码(该行不允许修改)                          
};    

bool Password::judge(string s){ 
	bool flagLower,flagUpper,flagDigit;
	flagLower = flagUpper = flagDigit = false;
 	for (int i=0;i<s.length();i++){
		if(islower(s[i])) flagLower = true;
		if(isupper(s[i])) flagUpper = true;
		if(isdigit(s[i])) flagDigit = true;
	}
 	if(flagLower && flagUpper && flagDigit) 
		return true;
 	else return false;
}	

int main() {
    Password s1; //s1被设置为默认密码：Abcd1234
    cout<<s1<<endl<<endl;
   
    //密码长度必须在8～32之间，否则密码被置为默认密码：Abcd1234
    Password s2("123456");
    Password s3("ABCDEFGabcdefg01234567890123456789");
    cout<<s2<<','<<s3<<endl<<endl;
   
    //密码必须包含大写字母，小写字母和数字三者。
    //否则密码被置为默认密码：Abcd1234
    Password s4("ABCD1234");
    Password s5("abcde12345");
    cout<<s4<<','<<s5<<endl<<endl;
   
    //密码长度在8～32之间，包含大写字母，小写字母和数字三者。
    //正确构造用户所需要的密码。
    Password s6("Wch54321");
    Password s7("ABCDEFG0123456789abcdefg01234567");
    cout<<s6<<','<<s7<<endl<<endl;
   
    //拷贝构造
    Password s8(s1);
    Password s9=s6;
    cout<<s8<<','<<s9<<endl<<endl;
   
    //赋值运算
    s2=s8=s6=s6;
    cout<<s2<<','<<s8<<','<<s6<<endl;
    s3=s4=s5=s6;
    cout<<s3<<','<<s4<<','<<s5<<endl<<endl;
   
    //将密码修改为默认密码：Abcd1234
    s2.chgPWD(); //s2被设置为默认密码：Abcd1234
    s3.chgPWD("Abcd1234");
    cout<<s2<<','<<s3<<endl<<endl;
   
    //密码长度必须在8～32之间，否则保持密码不变。
    s4.chgPWD("123456");
    s5.chgPWD("ABCDEFGabcdefg01234567890123456789");
    cout<<s4<<','<<s5<<endl<<endl;
   
    //密码长度在8～32之间，包含大写字母，小写字母和数字三者。
    //正确修改为用户所需要修改的密码。
    s4.chgPWD("Wch88888");
    s5.chgPWD("abcde0123456789ABCDEFG0123456789");
    cout<<s4<<','<<s5<<endl<<endl;

    //密码必须包含大写字母，小写字母和数字三者。
    //否则保持密码不变。
    s4.chgPWD("ABCD1234");
    s5.chgPWD("abcde12345");
    cout<<s4<<','<<s5<<endl<<endl;

    //输出所有已经构造的密码
    cout<<"s1:"<<s1<<',';    cout<<"s2:"<<s2<<',';    cout<<"s3:"<<s3<<endl;
    cout<<"s4:"<<s4<<',';    cout<<"s5:"<<s5<<',';    cout<<"s6:"<<s6<<endl;
    cout<<"s7:"<<s7<<',';    cout<<"s8:"<<s8<<',';    cout<<"s9:"<<s9<<endl<<endl;

    //密码比较==和!=
    cout<<"s1==s2:"<<(s1==s2?"TRUE":"FALSE")<<',';
    cout<<"s1==s4:"<<(s1==s4?"TRUE":"FALSE")<<endl;
    cout<<"s1!=s2:"<<(s1!=s2?"TRUE":"FALSE")<<',';
    cout<<"s1!=s4:"<<(s1!=s4?"TRUE":"FALSE")<<endl;

    return 0;
}
/*
(Abcd1234)

(Abcd1234),(Abcd1234)

(Abcd1234),(Abcd1234)

(Wch54321),(ABCDEFG0123456789abcdefg01234567)

(Abcd1234),(Wch54321)

(Wch54321),(Wch54321),(Wch54321)
(Wch54321),(Wch54321),(Wch54321)

(Abcd1234),(Abcd1234)

(Wch54321),(Wch54321)

(Wch88888),(abcde0123456789ABCDEFG0123456789)

(Wch88888),(abcde0123456789ABCDEFG0123456789)

s1:(Abcd1234),s2:(Abcd1234),s3:(Abcd1234)
s4:(Wch88888),s5:(abcde0123456789ABCDEFG0123456789),s6:(Wch54321)
s7:(ABCDEFG0123456789abcdefg01234567),s8:(Wch54321),s9:(Wch54321)

s1==s2:TRUE,s1==s4:FALSE
s1!=s2:FALSE,s1!=s4:TRUE
*/ 
