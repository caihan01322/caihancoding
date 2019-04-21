#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>
#include <map>
using namespace std;

class Create	//文章生成类 
{
public:
	Create();	//文章内容存入文件 
	~Create();	//清除文件的文章内容 
	void setStartVerb();	//设置启动词 
	void createArtcle();	//生成一篇新的文章
	void showArticle();		//显示生成的文章 
private:
	string m_strStartVerb;	//启动词
	string m_strArticle;	//新文章
};
Create::Create()	//文章内容存入文件
{
	ofstream f("D:\\article.txt",ios::app);
	//文章A存入文件 
	f << "冬色爷爷送走了大地的严寒，春姑娘踏着轻盈的脚步来到了人间。春天的景色十分美丽，就像一幅栩栩如生的画。";
	f << "春天的阳光格外明媚，春姑娘展开了笑脸，太阳，红红的光束射过来，那温柔地抚摸你，像年轻的母亲的手。";
	f << "随着春姑娘轻快的步伐，青青的小草，破土而出，偷偷的从土里钻出来，嫩嫩的，绿绿的。在公园里，到处都可以看见这一些生命力顽强的小草。";
	f << "在这一个温暖的季节里，在树林里，许多的树木都开满了鲜艳的花朵；大家都不肯相让，红的、黄的、白的、紫的，各种各样的花真像一个美丽的大花坛。许许多多的蝴蝶和蜜蜂都闻到了花的香味，都不约而同地飞来采蜜，在半空中飞来飞去。";
	f << "在树林里，许多的小鸟在自由自在欢乐地飞翔着，高兴起来，便唱出清脆悦耳的曲子，和煦的春光吹拂着小河，河水忽然被一阵悦耳、动听的笛声所牵动，放眼望去，一群顽皮的小孩子正用垂柳的茎做柳笛呢！他们吹出了心里的幸福和快乐。";
	f << "春天的雨是柔和的，只见春雨在竹枝、竹叶上跳动着。那雨时而直线滑落，时而随风飘洒，留下如烟、如雾、如纱、如丝的倩影，飞溅的雨花仿佛是琴铉上跳动的音符，奏出优美的旋律。";
	f << "天空上，怎么是五颜六色的，使人眼花缭乱？啊，原来孩子们在放风筝呀。在蓝天白云的照耀下，各种各样的风筝在自由自在地飘舞着，飞升着，多么使人心旷神怡的景象啊！";
	f << "春天的一切，都显得那样的生机勃勃。";
	f << "啊，春天真美啊！让我们用心去感受大自然的美景吧。";
	//文章B存入文件 
	f << "春天好美丽喔！花红，草绿，大树也发芽了。我听到孩子们的笑声，我感觉到天空春雨绵绵，我听到小鸟啾啾的唱着歌，我看到圆滚滚温暖的太阳，我听到微风的呼唤声。";
	f << "春天帅哥飞来了！春天帅哥飞来了！花朵小姐打扮得浓妆艳抹。哇！大家都惊叹不已！大树爷爷穿上春天帅哥送的新衣裳，快乐得哈哈大笑。小鸟和流水，高兴得一边唱歌一边伴奏。春天在哪儿？春天在哪儿？嫩芽忙着探出头来，在春风中玩着捉迷藏。大家都兴高采烈，欢迎春天帅哥的飞来。";
	f << "春天来了！小花抬起头来，享受着温暖的阳光，小草换上绿衣裳，好开心。小鸟唱着悦耳的歌，让我们心情好愉快。孩子们在草原上奔跑、游戏。春天，春天在哪儿？原来，春天在美丽的大自然里，春天在孩子们的笑声中。春天在芬芳的花香里，花香透露了春天清爽的气息，美丽的花儿，在春天绽放。"; 
	f << "春天在哪儿？春天在碧绿的草原里，小草欣欣向荣，株株绿得可爱。春天在哪儿？春天在蝴蝶艳丽的翅膀里。";
	//文章C存入文件
	f << "春天来了，万物都苏醒了。春天迈着轻盈的脚步，悄然无息地来了。";
	f << "看，她来到了池塘边，一棵棵柳树长了出来，它们摇摆着细嫩的腰肢，在阳光下翩翩起舞。看，她来到了花园里，一朵朵花儿长了出来，它们争奇斗艳、竞相开放。看，她来到了树林旁，一棵棵大树长了出来，它们挺拔高大、粗壮结实。看，她来到了大山上，路边的小草、山上的树木、田里的禾苗都长得绿油油的，就像给大地穿了一件绿色的外衣。"; 
	f << "春天的太阳，明亮、温暖；春天的风儿，凉爽、柔和。在春天里，勤劳的小蜜蜂忙着采蜜、美丽的小蜻蜓忙着捉虫。还有那些可爱的小鸟们，在枝头上欢快地歌唱，好像在迎接春天的到来。";
	f.close();
}
Create::~Create()	//清除文件的文章内容
{
	ofstream f("D:\\article.txt",ios::trunc);
	f.close();
}
void Create::setStartVerb()		//设置启动词
{
	cout << "请输入启动词（默认为\"春天\"）：";
	cin >> m_strStartVerb;
}
void Create::createArtcle()		//生成一篇新的文章
{
	//统计文章字符数（不含'\0'） 
	ifstream f("D:\\article.txt");
	string s;
	f >> s;
	int len = s.length();
	f.close();
	
	//把 “汉字或标点符号 ”独立来 
	FILE *fp = fopen("D:\\article.txt","r");
	char cha[len/2*3];
	int cout = 0;
	for(int i=0;i<len/2*3-1;i++){
		if(i % 3 == 2)	
			cha[i] = '\0';
		else	
			cha[i] = getc(fp);
		cout++;
	}
	cha[cout] = '\0';
	fclose(fp);
	
	//生成 “汉字或标点符号 ”数组 
	char *q = cha;
	char p[2];
	vector<string> ch(len/2);
	vector<string> verb(len/2-1);
	for(int i = 0;i < len/2;i++)//本应该用len
	{
		strcpy(p,q);
		q += 3;
		ch[i] = (string) p;
	}
	for(int i = 0;i < s.length()/2-1;i++)
	{
		verb[i] = ch[i] + ch[i+1];
	}
	
	//将启动词存入文章 
	map<int,int> mapPrefix;
	string prefixVerb;
	int n = 0;
	for(int i = 0;i < len/2-1;i++){
		if(m_strStartVerb == verb[i]){
			mapPrefix.insert(pair<int,int>(n,i));
			n++;
		}
	}
	srand(int(time(0)));
	int x = (rand()%mapPrefix.size());
	map<int,int>::iterator it;
	it = mapPrefix.find(x);
	m_strArticle += m_strStartVerb;
	prefixVerb = verb[(it->second)+1];
	mapPrefix.clear();
	
	//利用启动词生成新文章 
	int k=0;
	while(k<148){
		int n = 0;
		for(int i = 0;i < len/2-1;i++){
			if(prefixVerb == verb[i]){
				mapPrefix.insert(pair<int,int>(n,i));
				n++;
			}
		}
		srand(int(time(0)));
		int x = (rand()%mapPrefix.size());
		map<int,int>::iterator it;
		it = mapPrefix.find(x);
		m_strArticle += ch[(it->second)+1];
		prefixVerb = verb[(it->second)+1];
		mapPrefix.clear();
		k++;
	}
	/*map<int,string> mapSuffix;
	while(it != mapSuffix.end()){
    	it->first;
    	it->second;
    	it ++;
	}*/
}
void Create::showArticle()		//显示生成的文章
{
	cout << endl << "生成的文章（150字）：" << endl;
	cout << m_strArticle; 
}
int main(void) {
	Create create;
	create.setStartVerb();		//设置启动词
	create.createArtcle();		//生成一篇新的文章
	create.showArticle();		//显示生成的文章
	return 0;
}
