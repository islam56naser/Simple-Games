#pragma once
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include <ctime>
using namespace std;
using namespace cv;

class food
{
	
public:
	food();
	void offer();
	Point getPos();
	void adjustPos();
	bool getIsCombo();
	bool getIsOffering();
	void setIsOffering(bool flag);
	void reset();
	

private:
	Point pos;
	bool isOffering;
	bool isCombo;
	int cntr;
	int offset;
};


