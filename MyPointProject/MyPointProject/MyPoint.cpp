#include <iostream>
#include <math.h> 
using namespace std;
class MyPoint
{
public:
	MyPoint();
	~MyPoint();
	MyPoint(int x, int y)
	{
		mPosX = x;
		mPosY = y;
	}
	void Display() {
		cout << "Pos X :" << mPosX<<endl;
		cout << "Pos Y :" << mPosY << endl;
	}
	float Distance(MyPoint p) {
		float result;
		result=sqrt((p.mPosX-mPosX)* (p.mPosX - mPosX)+(p.mPosY-mPosY));
		return result;
	}
	void setX(int x)
	{
		mPosX = x;
	}
	int getX()
	{
		return mPosX;
	}
	void setY(int y)
	{
		mPosY = y;
	}
	int getY()
	{
		return mPosY;
	}

private:
	int mPosX;
	int mPosY;
};

MyPoint::MyPoint()
{
}

MyPoint::~MyPoint()
{
}
int main() {
	// use for test
	MyPoint* point = new MyPoint(1, 2);
	MyPoint* point2 = new MyPoint(2, 2);
	cout << point->Distance(*point2);
	return 0;
}