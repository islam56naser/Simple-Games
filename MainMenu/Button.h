#pragma once
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include <vector>
#include <iostream>
using namespace std;
using namespace cv;

class Button
{
public:
	Button();
	Button(Mat img, String winName, Rect rect, String text, Scalar color, bool active);
	~Button();
	void drawButton();
	bool getIsPressed();
	void setActive(bool active);
	static void myMouseCallBack(int event, int x, int y, int flags, void* param);
	void setIsPressed(bool flag);
private:
    Mat img;
    Rect rect;
	String text;
	String winName;
	bool active;
	bool isPressed;
	static int cntr;
	static vector<Button*> buttons;
	Scalar color;
};

