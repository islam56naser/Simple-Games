#include "level2.h"

void initLevel2Variables(){

	ship_s[0] = imread("straight_small.png"); 
	ship_s[1] = imread("right_small.png");
    ship_s[2] = imread("left_small.png");
	ship_s_mask[0] = imread("straight_small_mask.png");
	ship_s_mask[1] = imread("right_small_mask.png");
	ship_s_mask[2] = imread("left_small_mask.png");
	missiles[0] = imread("rocket_small.png"); 
	missiles[1] = imread("rocket_small_phase2.png");
	missiles_mask[0] = imread("rocket_small.png", 0);
	missiles_mask[1] = imread("rocket_small_phase2.png", 0);
	boom = imread("damage.png");
	boom_mask = imread("damage.png", 0);
	warZone = imread("bg3.png");
	cntr = 0;
	step = 2;
	startY = 1243;
	dir = 1;
	steady_count = 0;
	T = 30000;
	start = clock();

}



void resetLevel2(){
	enigma.reset();
	for (int i = 0; i < 5; i++){
		bwazik[i].reset();
	}
	startY = 1243;
	T = 30000;
}

void showTime(){
	if (T/1000 >= 10){
		putText(temp2, "00:" + to_string((T / 1000)), Point(370, 30),
			CV_FONT_HERSHEY_COMPLEX_SMALL, 2, Scalar(242, 61, 10), 2);
	}
	else{
		putText(temp2, "00:0" + to_string((T / 1000)), Point(370, 30),
			CV_FONT_HERSHEY_COMPLEX_SMALL, 2, Scalar(242, 61, 10), 2);
	}
	
}

bool isOut2(Point pos){
	bool flag = (!Rect(Point(9, 0), Point(495, 667)).contains(pos));
	return flag;
}

bool isHit2(){
	Point shipPos = enigma.getPos();
	Rect shield = Rect(shipPos.x + 15, shipPos.y, 50, 110);
	for (int i = 0; i < 5; i++){
		Point bazokapos = bwazik[i].getPos();
		if (shield.contains(Point(bazokapos.x + 10 , bazokapos.y + 60)) ||
			shield.contains(Point(bazokapos.x + 25 , bazokapos.y + 60))){
			return true;
		}

	}
	return false;
}

void drawShip(char c){
	Point shipPos = enigma.getPos();
	Mat ROI = temp2(Rect(shipPos.x, shipPos.y, 62, 110));
	switch (c){
	case 'a':
		ship_s[2].copyTo(ROI, ship_s_mask[2]);
		dir = 2;
		break;
	case 'd':
		ship_s[1].copyTo(ROI, ship_s_mask[1]);
		dir = 4;
		break;
	default:
		if (dir == 2 && (steady_count < 3)){
			ship_s[2].copyTo(ROI, ship_s_mask[2]);
			steady_count++;
			break;
		}
		else if (dir == 4 && (steady_count < 3)){
			ship_s[1].copyTo(ROI, ship_s_mask[1]);
			steady_count++;
			break;
		}
		else{
			dir = 1;
			steady_count = 0;
			ship_s[0].copyTo(ROI, ship_s_mask[0]);
			break;
		}
		
	}

}


void moveShip( char c){
	Point shipPos = enigma.getPos();
	if (isOut2(shipPos)){
		drawShip(0);
		enigma.move('d');
	}
	else if(isOut2(Point(shipPos.x + 62,shipPos.y))){
		enigma.move('a');
		drawShip(0);
		
	}
	else
	{
		enigma.move(c);
		drawShip(c);
	}

}

void drawMissile(Point pos){
	if (pos.y > 0){
		Mat ROI = temp2(Rect(pos.x, pos.y, 35, 70));
		cntr++;
		if (cntr % 3 == 0){
			missiles[0].copyTo(ROI, missiles_mask[0]);
		}
		else
		{
			missiles[1].copyTo(ROI, missiles_mask[1]);
		}

	}	   
}

void explode(){
	Point shipPos = enigma.getPos();
	Mat ROI = temp2(Rect(shipPos.x, shipPos.y, 62, 110));
	boom.copyTo(ROI, boom_mask);
}


bool playLevel2(char c, int* points){
	bool flag = true;
	if (*points >= 100 || c == 'q'){
		destroyWindow("Sky storm");
		resetLevel2();
		flag = false;

	}
	else{
		flag = true;
		frame = warZone(Rect(0, startY, 500, 687));
		frame.copyTo(temp2);
		namedWindow("Sky storm");
		if (isHit2()){
			drawShip(c);
			explode();

			imshow("Sky storm", temp2);
			waitKey(0);
			resetLevel2();
		}
		else{
			showTime();
			moveShip(c);
			for (int i = 0; i < 5; i++){
				if (!bwazik[i].getIsAttaking()){
					bwazik[i].setIsAttacking(true);
					bwazik[i].launch(i+1);
					
				}
			}
			for (int i = 0; i < 5; i++){
				bwazik[i].attack();
				Point pos = bwazik[i].getPos();
				if (isOut2(Point(pos.x, pos.y + 80))){
					bwazik[i].setIsAttacking(false);
				}
				else{
					drawMissile(pos);
				}
			}
			startY -= 5;
			if (startY < 0){
				startY = 1743;
			}
			imshow("Sky storm", temp2);
		}
		
		//
		T -= 30;
		if (T <= 0){
			*points = 100;
		}
	}
	return flag;
	
}
	
