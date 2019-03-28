#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;

class Enrol{
	public:
		void setName(){
			cin >> m_sName;
		}
		
		void setAccount(){
			ifstream f("D:\\usersInformation.txt");
			string name,account,password;
			bool flagMatch = false;
			
			//判断账户名是否重复 
			cin >> m_sAccount;
			while(f >> name >> account >> password){
				if(m_sAccount == account){
					flagMatch = true;
					break;
				}
			}
			if(flagMatch == true){
				cout << endl << "User name has existed." << endl;
				cout << endl << "Account :";
				setAccount();
			}
				 
		}
		
		void setPassword(){
			ofstream f("D:\\usersInformation.txt",ios::app);
			
			//重复设置密码时把两个接收字符初始化			
			char ch,chMatch;
			ch = chMatch = '\0';

			//重复设置密码时把两个密码初始化
			string matchPassword;
			m_sPassword = matchPassword = "";	 
			
			int i = 0;
 			while((ch=getch())!=13)//输入字符为回车时结束输入密码
			{
				if(ch == 8)//实现删除功能
				{
					if(i > 0){
						cout << ch << " " << ch;
						m_sPassword.erase(m_sPassword.end() - 1);
						i--;
					}
				}
				else{ 
  					if(ch != 32)//不接收空格字符 
					{
						m_sPassword += ch;
  						cout << "*";
  						i++;
					}
  				}		
			}
			cout << endl;
			
			//密码的长度不少于6位且至少包含数字和字母 
			if(m_sPassword.size()>=6 && judge(m_sPassword)){
				cout << "Please reconfirm your password:";
				
				int j = 0; 
				while((chMatch=getch())!=13)//输入字符为回车时结束输入密码
				{
 					if(chMatch == 8)//实现删除功能
					{
						if(j > 0){
							cout << chMatch << " " << chMatch;
							matchPassword.erase(matchPassword.end() - 1);
							j--;
						}
					}
					else{
						if(chMatch != 32)//不接收空格字符 
						{
  							matchPassword += chMatch;
  							cout << "*";
  							j++;
						}
					}
				}
				cout << endl;
					
				//判断第二次密码输入是否正确 
				if(m_sPassword == matchPassword){
					cout << endl << "Successful registration!" << endl;
					f << m_sName << " " << m_sAccount << " " << m_sPassword << endl;
				}
				else{
					cout << endl << "The second password input is incorrect!" << endl;
					cout << endl << "Password :";
					setPassword();
				}
			}
			
			else{
				cout << endl << "Your password is less than 6 bits in length, " << endl;
				cout << "or does not containletters and numbers at least." << endl;
				cout << "Please reset it!" << endl;
				cout << endl << "Password :";
				setPassword();	 
			}
			f.close();
		}
		
		//判断密码是否至少包含数字和字母 
		bool judge(string s){ 
			bool flagLetter,flagDigital;
			flagLetter = flagDigital = 0;
			
 			for (int i=0;i<s.length();i++){
				if(isLetter(s[i])) flagLetter = 1;
				if(isDigital(s[i])) flagDigital = 1;
			}
 			if(flagLetter && flagDigital) return 1;
 			else return 0;
		}
		
	private:
		string m_sName;
		string m_sAccount;
		string m_sPassword;
		
		bool isLetter(char c){
			return (('a'<=c && c<='z')||('A'<=c && c<='Z')); 
		}; 
		bool isDigital(char c){
 			return ('0'<=c && c<='9');
		};
};

class Enter{
	public:
		void cinAccount(){
			cin >> m_sAccount;
		}
		
		void cinPassword(){
			ifstream f("D:\\usersInformation.txt");
			string name,account,password;
			bool flagMatch = false;
			char ch;
			int k = 0;
			
 			while((ch=getch())!=13)//输入字符为回车时结束输入密码
			{
				if(ch == 8)//实现删除功能
				{
					if(k > 0){
						cout << ch << " " << ch;
						m_sPassword.erase(m_sPassword.end() - 1);
						k--;
					}
				}
				else{ 
  					if(ch != 32)//不接收空格字符 
					{
						m_sPassword += ch;
  						cout << "*";
  						k++;
					}
  				}		
			}
			cout << endl;
			
			//判断用户名及密码是否都正确 
			while(f >> name >> account >> password){ 
				if(m_sAccount==account && m_sPassword==password){
					flagMatch = true;
					cout << endl << "欢迎您，" << name << endl;
				}
			}	 
			if(flagMatch == false)	 
				cout << endl << "User name does not exist or password error." << endl;
			f.close();
	
		}
		
	private:
		string m_sAccount;
		string m_sPassword;                 
};

void interface(){
	cout << "                                                             \n";
  	cout << "          +++++++++++++++++++++++++++++++++++++++++++++++++++\n";
  	cout << endl;
  	cout << "          +         User Registration and Login System      +\n";
  	cout << "          +                                                 +\n";
  	cout << "          +               1 --- Please enrol                +\n";
  	cout << "          +               2 --- Please enter                +\n";
  	cout << "          +               0 --- Exit system                 +\n";
  	cout << endl;
  	cout << "          +++++++++++++++++++++++++++++++++++++++++++++++++++\n";
  	cout << endl;
  	cout << "      Please enter options(0-2): ";
}

int main(void){
	while(1){
		interface();
  		int iSelect;
  		cin >> iSelect;
		switch(iSelect){
  			case 1:{
			  	Enrol enrol;
				cout << endl << "Please enrol:" << endl;
				cout << endl << "Name :";
				enrol.setName();
				cout << "Account :";
				enrol.setAccount();
				cout << "Password :";
				enrol.setPassword();	
				break;
			} 	
  			case 2:{
				Enter enter; 
				cout << endl << "Please enter :" << endl;
				cout << endl << "Account :";
				enter.cinAccount(); 
				cout << "Password :";
				enter.cinPassword();  
				break;
			} 	
			case 0:
				return 0;    
		}
	}
	return 0;
}
