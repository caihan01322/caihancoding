#include <iostream>
#include <cctype>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;

class Menu;
string cinEncrypt(char ch,string password);	//输入密文密码

class Enrol	//用户注册 
{
	public:
		Menu *menu;
		void setName();			//设置用户名 
		void setAccount();		//设置账号
		void setPassword();		//设置密码	
		bool judge(string s);	//判断密码是否至少包含数字和字母
	private:
		string m_sName;
		string m_sAccount;
		string m_sPassword;
};

class Enter	//用户登录 
{
	public:
		Menu *menu;
		void cinAccount();		//输入账号 
		void cinPassword();		//输入密码
	private:
		string m_sAccount;
		string m_sPassword;                 
};

class Menu	//用户界面层 
{
	public:
		void interface();			//显示登录界面
		void enrolPrompt();			//提示注册 
		void enterPrompt();			//提示登录 
		void namePrompt();			//提示输入用户名 
		void accountPrompt();		//提示输入账号 
		void passwordPrompt();		//提示输入密码
		void accountExistedPrompt();		//提示账号已存在 
		void reconfirmPasswordPrompt();		//提示进行密码确认 
		void registerSuccessPrompt();		//提示注册成功 
		void secPasswordUnmatchPrompt();	//提示确认密码失败 
		void resetPasswordPrompt();			//提示重新设置密码 
		void welcomePrompt();				//提示欢迎用户 
		void matchInfoErrorPrompt();		//提示输入信息不正确 
};

class User	//业务逻辑层 
{
	public:
		Enrol enrol;	//用户注册
		Enter enter;	//用户登录 
};

class File	//数据操纵层 
{
	public:
		Menu *menu;
		bool isMatch(bool flag,string m_sAccount);							//判断账户名是否重复
		void writeInfo(string name,string account,string password);			//注册信息写入文件
		void matchInfo(bool flag,string m_sAccount,string m_sPassword);		//信息匹配则登陆成功
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

void Menu::enrolPrompt()		//提示注册 
{
	cout << endl << "Please enrol:" << endl;
}

void Menu::enterPrompt()		//提示登录 
{
	cout << endl << "Please enter :" << endl;
}

void Menu::namePrompt()			//提示输入用户名 
{
	cout << endl << "Name :";
}

void Menu::accountPrompt()		//提示输入账号 
{
	cout << endl << "Account :";
}

void Menu::passwordPrompt()		//提示输入密码 
{
	cout << endl << "Password :";
}

void Menu::accountExistedPrompt()		//提示账号已存在
{
	cout << endl << "Account has existed." << endl;
}
 
void Menu::reconfirmPasswordPrompt()	//提示进行密码确认
{
	cout << "Please reconfirm your password:";
}
 
void Menu::registerSuccessPrompt()		//提示注册成功
{
	cout << endl << "Successful registration!" << endl;	
}

void Menu::secPasswordUnmatchPrompt()	//提示确认密码失败 
{
	cout << endl << "The second password input is incorrect!" << endl;	
}

void Menu::resetPasswordPrompt()		//提示重新设置密码 
{
	cout << endl << "Your password is less than 6 bits in length, " << endl;
	cout << "or does not containletters and numbers at least." << endl;
	cout << "Please reset it!" << endl;
}

void Menu::welcomePrompt()				//提示欢迎用户
{
	cout << endl << "欢迎您，";
}

void Menu::matchInfoErrorPrompt()		//提示输入信息不正确 
{
	cout << endl << "Account does not exist or password error." << endl;
}
 
void Enrol::setName()			//设置用户名 
{
	cin >> m_sName;
}
		
void Enrol::setAccount()		//设置账号
{	
	File file;
	bool flag = false;
			
	//判断账户名是否重复 
	cin >> m_sAccount;
	flag = file.isMatch(flag,m_sAccount);
	
	if(flag == true){
		menu->accountExistedPrompt();
		menu->accountPrompt();
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
	
	m_sPassword = cinEncrypt(ch,m_sPassword);	//输入密文密码
	cout << endl;
			
	//密码的长度不少于6位且至少包含数字和字母 
	if(m_sPassword.size()>=6 && judge(m_sPassword)){
		menu->reconfirmPasswordPrompt();
		
		matchPassword = cinEncrypt(chMatch,matchPassword);	//输入密文密码
		cout << endl;
			
		File file;			
		if(m_sPassword == matchPassword)	//判断第二次密码输入是否正确
		{
			menu->registerSuccessPrompt();		
			file.writeInfo(m_sName,m_sAccount,m_sPassword);
		}
		else{
			menu->secPasswordUnmatchPrompt();
			menu->passwordPrompt();
			setPassword();
		}
	}
			
	else{
		menu->resetPasswordPrompt();
		menu->passwordPrompt();
		setPassword();	 
	}
}
		 
bool Enrol::judge(string s)		//判断密码是否至少包含数字和字母
{ 
	bool fAlpha,fDigit;
	fAlpha = fDigit = false;
			
 	for (int i=0;i<s.length();i++){
		if(isalpha(s[i])) fAlpha = true;
		if(isdigit(s[i])) fDigit = true;
	}
 	if(fAlpha && fDigit) return true;
 	else return 0;
}

void Enter::cinAccount()		//输入账号 
{
	cin >> m_sAccount;
}

void Enter::cinPassword()		//输入密码 
{ 
	bool flag = false;
	char ch;
	
	m_sPassword = cinEncrypt(ch,m_sPassword);		//输入密文密码
	cout << endl;
	 
	File file;
	file.matchInfo(flag,m_sAccount,m_sPassword);	//信息匹配则登陆成功 
}

bool File::isMatch(bool flag,string m_sAccount)							//判断账户名是否重复
{
	string name,account,password;
	ifstream f("D:\\usersInformation.txt");		//打开内容只读文件
	while(f >> name >> account >> password)		//判断账户名是否重复
	{
		if(m_sAccount == account){
			flag = true;
			break;
		}
	}
	return flag;
}

void File::writeInfo(string name,string account,string password)		//注册信息写入文件
{
	ofstream f("D:\\usersInformation.txt",ios::app);			//打开内容可追加文件
	f << name << " " << account << " " << password << endl;		//注册信息写入文件 
	f.close();
}

void File::matchInfo(bool flag,string m_sAccount,string m_sPassword)	//信息匹配则登陆成功
{
	string name,account,password;
	ifstream f("D:\\usersInformation.txt");		//打开内容只读文件
	while(f >> name >> account >> password)		//判断用户名及密码是否都正确
	{	 
		if(m_sAccount==account && m_sPassword==password){
			flag = true;
			menu->welcomePrompt();
			cout << name << endl;
		}
	}	 
	if(flag == false)	 
		menu->matchInfoErrorPrompt();
	f.close();
}

string cinEncrypt(char ch,string password) 								//输入密文密码 
{
	int i = 0;
 	while((ch=getch())!=13)	//输入字符为回车时结束输入密码
	{
		if(ch == 8) //实现删除功能
		{
			if(i > 0){
				cout << ch << " " << ch;
				password.erase(password.end() - 1);
				i--;
			}
		}
		else{ 
  			if(ch != 32) //不接收空格字符 
			{
				password += ch;
  				cout << "*";
  				i++;
			}
  		}		
	}
	return password;
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
