#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;

class Enrol	//用户注册 
{
	public:
		void setName()			//设置用户名 
		{
			cin >> m_sName;
		}
		void setAccount();		//设置账号
		void setPassword();		//设置密码	
		bool judge(string s);	//判断密码是否至少包含数字和字母
	private:
		string m_sName;
		string m_sAccount;
		string m_sPassword;
		bool isLetter(char c)	//判断字符是否为字母 
		{
			return (('a'<=c && c<='z')||('A'<=c && c<='Z')); 
		}; 
		bool isDigital(char c)	//判断字符是否为数字
		{
 			return ('0'<=c && c<='9');
		};
};

class Enter	//用户登录 
{
	public:
		void cinAccount()		//输入账号 
		{
			cin >> m_sAccount;
		}
		void cinPassword();		//输入密码
	private:
		string m_sAccount;
		string m_sPassword;                 
};

class Menu	//用户界面层 
{
	public:
	void interface();			//显示登录界面
	void enrolPrompt()			//提示注册 
	{
		cout << endl << "Please enrol:" << endl;
	}
	void enterPrompt()			//提示登录 
	{
		cout << endl << "Please enter :" << endl;
	}
	void namePrompt()			//提示输入用户名 
	{
		cout << endl << "Name :";
	}
	void accountPrompt()		//提示输入账号 
	{
		cout << endl << "Account :";
	}
	void passwordPrompt()		//提示输入密码 
	{
		cout << "Password :";
	}
};

class User	//业务逻辑层 
{
	public:
		Enrol enrol;//用户注册
		Enter enter;//用户登录 
};

class File	//数据操纵层 
{
	public:
		bool isMatch(bool flagMatch,string m_sAccount)				//判断账户名是否重复
		{
			string name,account,password;
			ifstream f("D:\\usersInformation.txt");					//打开内容只读文件
			while(f >> name >> account >> password)					//判断账户名是否重复
			{
				if(m_sAccount == account){
					flagMatch = true;
					break;
				}
			}
			return flagMatch;
		}
		void writeInfo(string name,string account,string password)	//注册信息写入文件
		{
			ofstream f("D:\\usersInformation.txt",ios::app);		//打开内容可追加文件
			f << name << " " << account << " " << password << endl;	//注册信息写入文件 
			f.close();
		}
		void matchInfo(bool flagMatch,string m_sAccount,string m_sPassword)	//信息匹配则登陆成功
		{
			string name,account,password;
			ifstream f("D:\\usersInformation.txt");							//打开内容只读文件
			while(f >> name >> account >> password)							//判断用户名及密码是否都正确
			{	 
				if(m_sAccount==account && m_sPassword==password){
					flagMatch = true;
					cout << endl << "欢迎您，" << name << endl;
				}
			}	 
			if(flagMatch == false)	 
				cout << endl << "User name does not exist or password error." << endl;
			f.close();
		}
};

void Menu::interface()			//显示登录界面 
{
	cout << "                                                             \n";
  	cout << "          +++++++++++++++++++++++++++++++++++++++++++++++++++\n";
  	cout << endl;
  	cout << "          +         User Registration and Login System      +\n";
  	cout << "          +                                                 +\n";
  	cout << "          +               1 --- Please enrol                +\n";
  	cout << "          +               2 --- Please enter                +\n";
  	cout << "          +               0 --- Exit  system                +\n";
  	cout << endl;
  	cout << "          +++++++++++++++++++++++++++++++++++++++++++++++++++\n";
  	cout << endl;
  	cout << "      Please enter options(0-2): ";
}
		
void Enrol::setAccount()		//设置账号
{	
	File file;
	bool flagMatch = false;
			
	//判断账户名是否重复 
	cin >> m_sAccount;
	flagMatch = file.isMatch(flagMatch,m_sAccount);
	
	if(flagMatch == true){
		cout << endl << "User name has existed." << endl;
		cout << endl << "Account :";
		setAccount();
	}				 
}
		
void Enrol::setPassword()		//设置密码 
{			
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
			
		File file;			
		if(m_sPassword == matchPassword)//判断第二次密码输入是否正确
		{
			cout << endl << "Successful registration!" << endl;		
			file.writeInfo(m_sName,m_sAccount,m_sPassword);
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
}
		 
bool Enrol::judge(string s)		//判断密码是否至少包含数字和字母
{ 
	bool flagLetter,flagDigital;
	flagLetter = flagDigital = 0;
			
 	for (int i=0;i<s.length();i++){
		if(isLetter(s[i])) flagLetter = 1;
		if(isDigital(s[i])) flagDigital = 1;
	}
 	if(flagLetter && flagDigital) return 1;
 	else return 0;
}

void Enter::cinPassword()		//输入密码 
{ 
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
	 
	File file;
	file.matchInfo(flagMatch,m_sAccount,m_sPassword);	//信息匹配则登陆成功 
}
		
int main(void){
	while(1){
		int iSelect;
		Menu menu;
		User user;
		
		menu.interface();	//显示登录界面
  		cin >> iSelect;		//选择菜单选项 
		switch(iSelect){
  			case 1:{
				menu.enrolPrompt();			//提示注册
				menu.namePrompt();			//提示输入用户名
				user.enrol.setName();		//设置用户名
				menu.accountPrompt();		//提示输入账号
				user.enrol.setAccount();	//设置账号
				menu.passwordPrompt();		//提示输入密码
				user.enrol.setPassword();	//设置密码	
				break;
			} 	
  			case 2:{ 
				menu.enterPrompt();			//提示登录 
				menu.accountPrompt();		//提示输入账号
				user.enter.cinAccount();	//输入账号 
				menu.passwordPrompt();		//提示输入密码
				user.enter.cinPassword();	//输入密码
				break;
			} 	
			case 0:
				return 0;    
		}
	}
	return 0;
}
