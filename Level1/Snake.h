#pragma once
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;
using namespace cv;


class Snake
{
public:
	Snake();

	void setHeading(char h);
	Point* getSnakeBody();
	int getPoints();
	void incPoints(short p);
	void reset();
	void move();
	void grow(int N);
	int getSnakeLength();
	char getHeading();
	
	
private:


	char heading;
	vector<Point> snakeBody;
	short points;
	Point pos;
	int snakeLength;
	

};



