#pragma once
#include"opencv2\highgui.hpp"
using namespace cv;

class Ship
{
public:
	Ship();
	~Ship();
	void move(char c);
	Point getPos();
	void reset();
private:
	Point pos;
};

