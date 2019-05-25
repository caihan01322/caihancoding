#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

string setStr()						//输入内容 
{
	char str[10];
	cin.getline(str,10);
	while(cin.fail()){
		cout << endl << "\a输入过长，请重新输入：";
		cin.clear();	//将流中的所有状态值都重设为有效值
		cin.sync();		//清空流 
		cin.getline(str,10);
	}
	return (string)str;
}

class Blackjack{
	private:
		int pok[53];     	//扑克牌
 		int pokValue[53]; 	//扑克值
		string pokName[53]; //扑克名
 
		int money;	//玩家金额 
		int bet;	//玩家赌注 
		int defBet;	//默认赌注
		
		int computerPok[10];	//庄家手牌
		int playerPok[10];		//玩家手牌
		int computerPokNum;		//庄家牌数
		int playerPokNum;		//玩家牌数
		int computerPokSum;		//庄家总点数
		int playerPokSum;		//玩家总点数
		
		bool aGameOver;				//一局是否结束
		bool outcome;				//胜负结果
		bool judge(string bet);		//判断输入金额是否为数字
	public:
		Blackjack();		//初始化扑克等 
		void inputBet();	//输入所下赌注
		void getPok();		//继续要牌
		void endGetPok();	//停止要牌
		void init();		//初始化牌数等
		int getMoney() const;		//查询余额
		bool getAGameOver() const;	//返回一局是否结束
		bool getOutcome() const;	//返回胜负结果
};
bool Blackjack::judge(string bet)	//判断输入金额是否为数字 
{
	for(int i=0;i<bet.length();i++)
		if(!isdigit(bet[i])) return false;
	return true;
}
Blackjack::Blackjack()				//初始化扑克等
{
 	for(int i=1;i<=13;i++)	//扑克牌初始化 
	{                         
  		pok[i+13*0]=i;           
  		pok[i+13*1]=i;        
 		pok[i+13*2]=i;        
  		pok[i+13*3]=i;        
 	}
 	for(int i=1;i<=52;i++)	//扑克值初始化
	{
  		if(pok[i]<=10)  pokValue[i]=pok[i];
  		else            pokValue[i]=10;
 	}
	for(int i=0;i<4;i++)	//扑克名初始化 
	{
  		pokName[1+13*i]="A";
  		pokName[2+13*i]="2";
  		pokName[3+13*i]="3";
  		pokName[4+13*i]="4";
  		pokName[5+13*i]="5";
  		pokName[6+13*i]="6";
  		pokName[7+13*i]="7";
  		pokName[8+13*i]="8";
  		pokName[9+13*i]="9";
  		pokName[10+13*i]="10";
  		pokName[11+13*i]="J";
  		pokName[12+13*i]="Q";
 		pokName[13+13*i]="K";
 	}
	
	money = 100;	//初始金额
	defBet = 10;	//默认赌注
	
	computerPokNum = 0;		//庄家初始牌数
	playerPokNum = 0;		//玩家初始牌数
	
	computerPokSum = 0;		//庄家初始总点数
	playerPokSum = 0;		//玩家初始总点数
	
	aGameOver = false;		//初始化为游戏未结束
	outcome = false;		//初始化胜负结果
}
void Blackjack::inputBet()			//输入所下赌注
{
	int iBet; 
	string sBet;
	string select;
	if(money - defBet >= 0){
		cout << endl << "你现在有" << money << "元,是否下注默认金额？（Y/N）：";
		select = setStr();
	}
	else select = "N";
	while(select != "Y" && select != "y" && select != "N" && select != "n"){
		cout << endl <<"\a输入有误，请重新输入（Y/N）：";
		select = setStr();
	} 
	if(select == "Y" || select == "y"){
		bet = defBet;
		cout << endl << "已下" << defBet << "元赌注,新一局开始。" << endl;
	}
	if(select == "N" || select == "n"){
		cout << endl << "你现在有" << money << "元,请输入所下赌注(整数)：";
		sBet = setStr();
		iBet = atoi(sBet.substr(0,sBet.length()).c_str());
		while(!judge(sBet) || iBet == 0 || iBet > money){
			cout << "\a输入有误，请重新输入：";
			sBet = setStr();
			iBet = atoi(sBet.substr(0,sBet.length()).c_str());
		}
		bet = iBet;
		cout << endl << "已下" << bet << "元赌注,新一局开始。" << endl;
	}
}
void Blackjack::getPok()			//继续要牌
{
	srand((unsigned int)(time(NULL)));
	
	int numOfA = 0;					//牌A数
	
	if(playerPokNum == 0){
		computerPok[0] = rand() % 52 +1;
		computerPok[1] = rand() % 52 +1;
		playerPok[0] = rand() % 52 +1;
		playerPok[1] = rand() % 52 +1;
		computerPokNum = computerPokNum + 2;
		playerPokNum = playerPokNum + 2;
		cout << endl << "玩家的手牌为：" << pokName[playerPok[0]] << " " << pokName[playerPok[1]] << endl;
		cout << "庄家的明牌为：" << pokName[computerPok[0]] << endl;
		
		//如果玩家拿到的前两张牌是一张A和一张10点牌，就拥有黑杰克(Blackjack);此时，如果庄家没有黑杰克，玩家就能赢得2倍的分数(1赔2)
		if ( ((pokName[playerPok[0]] == "A" && pokName[playerPok[1]] == "10")||(pokName[playerPok[0]] == "10" && pokName[playerPok[1]] == "A")) && 
		(!((pokName[computerPok[0]] == "A" && pokName[computerPok[1]] == "10")||(pokName[computerPok[0]] == "10" && pokName[computerPok[1]] == "A"))) ){
			money = money + bet * 2;
			aGameOver = true;
			outcome = true;
		}
		//如果庄家和玩家都是黑杰克，那么本局平局，游戏继续
		else if( ((pokName[playerPok[0]] == "A" && pokName[playerPok[1]] == "10")||(pokName[playerPok[0]] == "10" && pokName[playerPok[1]] == "A")) && 
		((pokName[computerPok[0]] == "A" && pokName[computerPok[1]] == "10")||(pokName[computerPok[0]] == "10" && pokName[computerPok[1]] == "A")) ){
			cout << "庄家的暗牌为：" << pokName[computerPok[1]] << endl;
			aGameOver = true;
			outcome = true;
		}
		//如果庄家的明牌有一张A，则玩家可以考虑买不买保险，金额是赌筹的一半。如果庄家是blackjack，那么玩家拿回保险金并且直接获胜;
		//如果庄家没有blackjack则玩家输掉保险继续游戏。如果玩家不买保险而庄家是blackjack，那么那么本局平局，游戏继续
		else if(pokName[computerPok[0]] == "A"){
			string select;
			cout << endl << "是否买保险？（Y/N）：";
			select = setStr();
			while(select != "Y" && select != "y" && select != "N" && select != "n"){
				cout << "\a输入有误，请重新输入（Y/N）：";
				select = setStr();
			}
			if(select == "Y" || select == "y"){
				money = money - bet / 2;
				if(pokName[computerPok[1]] == "10"){
					cout << "庄家的暗牌为：" << pokName[computerPok[1]] << endl;
					money = money + bet / 2 + bet;
					aGameOver = true;
					outcome = true;
				} 
				else{
					cout << endl << "庄家没有黑杰克！" << endl;
					aGameOver = false;
				}
			}
			if(select == "N" || select == "n" ){
				if(pokName[computerPok[1]] == "10"){
					cout << "庄家的暗牌为：" << pokName[computerPok[1]] << endl;
					aGameOver = true;
					outcome = true;
				}
			} 
		}
		for(int i=0;i<computerPokNum;i++){
			if(pokName[computerPok[i]] == "A"){
				computerPokSum = computerPokSum + pokValue[computerPok[i]] + 9;
				numOfA++;
			}
			else computerPokSum = computerPokSum + pokValue[computerPok[i]];
		}
	}
	else{	
		playerPok[playerPokNum] = rand() % 52 + 1;
		playerPokNum++;
		if(computerPokSum <= 17){
			computerPok[computerPokNum] = rand() % 52 + 1;
			if(pokName[computerPok[computerPokNum]] == "A") 
				computerPokSum = computerPokSum + pokValue[computerPok[computerPokNum]] + 9;
			else computerPokSum = computerPokSum + pokValue[computerPok[computerPokNum]];
			if(computerPokSum > 21){
				if(pokName[computerPok[computerPokNum]] == "A") computerPokSum = computerPokSum - 9;
				else{
					while(numOfA > 0){
						computerPokSum = computerPokSum - 9;
						numOfA--;
						if(computerPokSum <= 21) break;
					}
				}
			}
			computerPokNum++;
		}
	}
	
	int playerSum = 0,n = 0;
	for(int i=0;i<playerPokNum;i++){
		if(pokName[playerPok[i]] == "A"){
			playerSum = playerSum + pokValue[playerPok[i]] + 9;
			n++;
		}
		else playerSum = playerSum + pokValue[playerPok[i]];
		if(playerSum > 21){
			while(n > 0){
				playerSum = playerSum - 9;
				n--;
				if(playerSum <= 21) break;
			}
		}
	}
	playerPokSum = playerSum;
	
	if(playerPokSum > 21){
		cout << endl << "玩家的手牌为：";
		for(int i=0;i<playerPokNum;i++){
			cout << pokName[playerPok[i]] << " ";
		}
		cout << endl;
		cout << endl << "Bust!玩家爆掉了,本局游戏结束！"  << endl;
		money = money - bet;
		aGameOver = true;
		outcome = false;
	}
	
	if(aGameOver == false && playerPokNum > 2){
		cout << endl << "玩家的手牌为：";
		for(int i=0;i<playerPokNum;i++){
			cout << pokName[playerPok[i]] << " ";
		}
	}
}
void Blackjack::endGetPok()			//停止要牌
{
	srand((unsigned int)(time(NULL)));
	
	while(computerPokSum <= 17){
		computerPok[computerPokNum] = rand() % 52 + 1;
		computerPokSum = computerPokSum + pokValue[computerPok[computerPokNum]];
		computerPokNum++;
	}
	
	cout << endl << "玩家的手牌为：";
	for(int i=0;i<playerPokNum;i++){
		cout << pokName[playerPok[i]] << " ";
	}
	cout << endl << "庄家的手牌为：";
	for(int i=0;i<computerPokNum;i++){
		cout << pokName[computerPok[i]] << " ";
	}
	cout << endl;
	
	if(playerPokSum > 21){
		cout << endl << "Bust!玩家爆掉了,本局游戏结束！"  << endl;
		money = money - bet;
		outcome = false;
	}
	else if(computerPokSum > 21){
		cout << endl << "Bust!庄家爆掉了,本局游戏结束！" << endl;
		money = money + bet;
		aGameOver = true;
		outcome = true;
	}
	else if(playerPokSum > computerPokSum){
		cout << endl << "玩家点数(" << playerPokSum << ")大于庄家点数(" << computerPokSum << ")" << "玩家赢了！" << endl;
		money = money + bet;
		outcome = true;
	}
	else if(playerPokSum < computerPokSum){
		cout << endl << "玩家点数(" << playerPokSum << ")小于庄家点数(" << computerPokSum << ")" << "玩家输了！" << endl;
		money = money - bet;
		outcome = false;
	}
	else{
		cout << endl << "玩家点数(" << playerPokSum << ")等于庄家点数(" << computerPokSum << ")" << "本局平局！" << endl;
		outcome = true;
	}
	aGameOver = true;
}
void Blackjack::init()				//初始化牌数等
{
	computerPokNum = 0;		//庄家初始牌数
	playerPokNum = 0;		//玩家初始牌数
	
	computerPokSum = 0;		//庄家初始总点数
	playerPokSum = 0;		//玩家初始总点数
	
	aGameOver = false;		//初始化为游戏未结束
	outcome = false;		//初始化胜负结果
}
int Blackjack::getMoney() const			//查询余额
{
	return money;
}
bool Blackjack::getAGameOver() const		//一局是否结束
{
	return aGameOver;
}
bool Blackjack::getOutcome() const		//返回胜负结果
{
	return outcome;
}

int main(void){
	Blackjack blackjack;
	while(1){
		cout << "欢迎玩黑杰克(21点)游戏！" << endl;
		blackjack.inputBet();	//输入所下赌注
		
		bool flag = false;
		int initMoney = blackjack.getMoney();
		
		blackjack.getPok();
		
		while(flag || !blackjack.getAGameOver()){
			cout << endl << endl << "1.要牌 2.不要牌 >> 请选择：";
			string sChoice;
			int iChoice;
			sChoice = setStr();
			iChoice = atoi(sChoice.substr(0,sChoice.length()).c_str()); 
			switch(iChoice){
				case 1:
					blackjack.getPok();
					if(blackjack.getAGameOver() == true) flag = false;
					else flag = true;					
					break;
				case 2:
					blackjack.endGetPok();
					flag = false;
					break;
				default:
					cout << endl << "\a输入有误，请重新输入。";
			}
		}
		if(blackjack.getMoney() <= 0){
			cout << endl << "玩家账户余额不足，游戏结束！" << endl;
			return 0;
		}
		
		if(blackjack.getOutcome()) 
			cout << endl << "你赢了" << blackjack.getMoney() - initMoney << "元。" << endl; 
		else  
			cout << endl << "你输了" << initMoney - blackjack.getMoney() << "元。" << endl; 
		
		cout << endl << "本局游戏结束，是否退出游戏？（Y/N）：";
		string select;
		select = setStr();
		while(select != "Y" && select != "y" && select != "N" && select != "n"){
			cout << "\a输入有误，请重新输入（Y/N）：";
			select = setStr();
		}
		
		if(select == "Y" || select == "y") return 0;
		if(select == "N" || select == "n") {
			blackjack.init();
			system("cls"); //清屏
		}
	}
}
