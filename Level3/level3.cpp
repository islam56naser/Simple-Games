#include "level3.h"


void initLevel3Variables(){
	monsters[0] = imread("monster1.png"); 
	monsters[1] = imread("monster2.png");
	monsters[2] = imread("monster1.png");
	monster_mask = imread("monster1.png", 0);
	monster_Dead = imread("monsterdead.png");
	monster_Dead_mask = imread("monsterdead.png", 0);
	monsterPos = Point(10, 10);
	cap = VideoCapture(0);
	LowH = 0;
	HighH = 7;
	LowS = 201;
	HighS = 255;
	LowV = 30;
	HighV = 255;
	monsterNom = 0;
	isDead = false;
}




bool playLevel3(int* points){
	bool flag = true;
	if (*points >= 150){
		destroyWindow("Camera");
		destroyWindow("mask");
		destroyWindow("controller");
		flag = false;
		*points = 100;
	}
	else{
		flag = true;
		namedWindow("Camera");
		namedWindow("mask");
		namedWindow("controller",1);
		createTrackbar("LowH", "controller", &LowH, 255);
		createTrackbar("HighH", "controller", &HighH, 255);
		createTrackbar("LowS", "controller", &LowS, 255);
		createTrackbar("HighS", "controller", &HighS, 255);
		createTrackbar("LowV", "controller", &LowV, 255);
		createTrackbar("HighV", "controller", &HighV, 255);
	    flag = cap.read(Original);
		flip(Original, Original, 1);
		medianBlur(Original, temp3, 3);
		cvtColor(temp3, temp3, COLOR_BGR2HSV);
		inRange(temp3, Scalar(LowH, LowS, LowV), Scalar(HighH, HighS, HighV), mask);
		if (isDead){
			monsterNom = rand() % 3;
			monsterPos.x = 10 * (1 + rand() % 58);
			monsterPos.y = 10 * (1 + rand() % 41);
			isDead = false;
		}
		color = mask.at<uchar>(Point(monsterPos.x + 25, monsterPos.y + 25));
		if (color.val[0] == 255){
			*points += 5;
			imgroi = Original(Rect(monsterPos.x, monsterPos.y, 50, 50));
			monster_Dead.copyTo(imgroi, monster_Dead_mask);
			isDead = true;
		}
		else {
			imgroi = Original(Rect(monsterPos.x, monsterPos.y, 50, 50));
			monsters[monsterNom].copyTo(imgroi, monster_mask);
		}
		erode(mask, mask, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(mask, mask, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(mask, mask, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(mask, mask, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		putText(Original,to_string(*points), Point(580, 450), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(0), 2);
		imshow("Camera", Original);
		imshow("mask", mask);



	}
	return flag;
}
