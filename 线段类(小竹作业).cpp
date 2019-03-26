#include<iostream>
#include<cmath>
using namespace std;

class Coordinate{
public:
	int x,y;
	Coordinate(int x,int y){
		this->x=x;
		this->y=y;
	}
};

class Line{
private:
    Coordinate coorL;
    Coordinate coorR;
    int width,color;
public:
    Line(int xLeft, int yLeft, int xRight, int yRight, int width = 1, int color = 0);
//  Line(const Line &aLine);
    void setWidth(int newWidth) { width = newWidth; }
    void setColor(int newColor) { color = newColor; }
    int getWidth() { return width; }
    int getColor() { return color; }
    double getLength();
    void move(int xLeft, int yLeft, int xRight, int yRight);//未实现 
    void draw();//未实现 
    bool isIntersect(Line aL0ine);
    bool isParallel(Line aLine);
};

Line::Line(int xLeft, int yLeft, int xRight, int yRight, int width, int color):
coorL(xLeft,yLeft),coorR(xRight,yRight){
	this->width=width;
	this->color=color;
}
/*Line::Line(const Line& aLine){
	aLine.width=width;
	aLine.color=color;
	aLine.coorL.x=coorL.x;
	aLine.coorL.y=coorL.y;
	aLine.coorR.x=coorR.x;
	aLine.coorR.y=coorR.y;
}*/
double Line::getLength()
{
    return sqrt(pow((coorL.x-coorR.x),2)+pow((coorL.y-coorR.y),2));
} 
bool Line::isIntersect(Line aL0ine){
	if(isParallel(aL0ine))
		return false;
	else return true;
}       
bool Line::isParallel(Line aLine)
{
	float myRatio = (coorL.y-coorR.y) / (coorL.x-coorR.x);
	float ratio = (aLine.coorL.y- aLine.coorR.y) / (aLine.coorL.x- aLine.coorR.x);
    return (abs(myRatio-ratio)<=1.0e-6);
}

int main(void){
	int a_x1,a_y1,a_x2,a_y2;
	int b_x1,b_y1,b_x2,b_y2;
	int a_width,a_color;
	int b_width,b_color;
	
	cout << "input line_a(x1,y1):" << endl;
	cout << "x1:";
	cin >> a_x1;
	cout << "y1:";
	cin >> a_y1;
	cout << "input line_a(x2,y2):" << endl;
	cout << "x2:";
	cin >> a_x2;
	cout << "y2:";
	cin >> a_y2;
	Line a(a_x1,a_y1,a_x2,a_y2); 
	cout << "input line_b(x1,y1):" << endl;
	cout << "x1:";
	cin >> b_x1;
	cout << "y1:";
	cin >> b_y1;
	cout << "input line_b(x2,y2):" << endl;
	cout << "x2:";
	cin >> b_x2;
	cout << "y2:";
	cin >> b_y2;
	Line b(b_x1,b_y1,b_x2,b_y2);
	
	cout << endl << "set line_a color:";
	cin >> a_color;
	cout << "set line_b color:";
	cin >> b_color;
	cout << "set line_a width:";
	cin >> a_width;
	cout << "set line_b width:";
	cin >> b_width;
	a.setColor(a_color);
	a.setWidth(b_color);
	b.setColor(a_width);
	b.setWidth(b_width);
	
	cout << endl << "copy line_a to line_c ..." << endl;
	Line c(a);
	cout << "copy success!" << endl;
	
	cout << endl << "line_a color is:" << a.getColor() << endl;
	cout << "line_b color is:" << b.getColor() << endl;
	cout << "line_a width is:" << a.getWidth() << endl;
	cout << "line_b width is:" << b.getWidth() << endl;
	cout << "line_a length is:" << a.getLength() << endl;
	cout << "line_b length is:" << b.getLength() << endl << endl;
	
	cout << "line_c color is:" << c.getColor() << endl;
	cout << "line_c width is:" << a.getWidth() << endl;
	cout << "line_c length is:" << a.getLength() << endl;
	
	if(b.isIntersect(a)) cout << "line_a and line_b are intersect" << endl;
		else cout <<  "line_a and line_b are not intersect" << endl;
	if(b.isParallel(a)) cout << "line_a and line_b are parallel";
		else cout <<  "line_a and line_b are not parallel";
		
	return 0;
}
