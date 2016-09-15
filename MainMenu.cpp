#include "MainMenu.h"

Mat img = imread("mainBg.png");
String winName = "Main Menu";
int height = 80;
int width = 540;
Rect btn1 = Rect(400, 200, width, height);
Rect btn2 = Rect(400, 350, width, height);
Rect btn3 = Rect(400, 500, width, height);
Button button1(img, winName, btn1, "Snake", Scalar(255,16,18), true);
Button button2(img, winName, btn2, "Sky storm", Scalar(255, 16, 18), false);
Button button3(img, winName, btn3, "Camera", Scalar(255, 16, 18), false);
bool buttonFlags[3];

void showMenu(){
	imshow("Main Menu", img);
	button1.drawButton();
	button2.drawButton();
	button3.drawButton();
}

void updateIsLevel(bool* isLevel,int points){
	if (points >= 50){
		isLevel[1] = true;
		button2.setActive(true);
	}
	if (points >= 100){
		isLevel[2] = true;
		button3.setActive(true);
	}

}

void updateIsPlaying(bool* isPlaying){
	if (button1.getIsPressed()){
		isPlaying[0] = true;
		isPlaying[1] = false;
		isPlaying[2] = false;
		button1.setIsPressed(false);
	}
	else if (button2.getIsPressed()){
		isPlaying[1] = true;
		isPlaying[0] = false;
		isPlaying[2] = false;
		button2.setIsPressed(false);
	}
	else if (button3.getIsPressed()){
		isPlaying[2] = true;
		isPlaying[0] = false;
		isPlaying[1] = false;
		button3.setIsPressed(false);
	}

}


