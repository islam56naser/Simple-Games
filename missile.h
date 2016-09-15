#pragma once
#include "opencv2\highgui.hpp"
#include <ctime>
using namespace cv;

class missile
{
public:
	missile();
	~missile();
	void launch(int dist);
	void attack();
	Point getPos();
	void reset();
	bool getIsAttaking();
	void setIsAttacking(bool flag);

private:
	Point pos;
	bool isAttacking;
	static int offset;
};

