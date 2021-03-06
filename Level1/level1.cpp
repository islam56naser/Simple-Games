#include "level1.h"
	
void initLevel1Variables(){
	 arena = imread("bg.png");
	 head[0] = imread("snk_h_l.png");
	 head[1] = imread("snk_h_r.png");
	 head[2] = imread("snk_h_u.png");
	 head[3] = imread("snk_h_d.png");
	 head_mask[0] = imread("snk_h_l.png", 0);
	 head_mask[1] = imread("snk_h_r.png", 0);
	 head_mask[2] = imread("snk_h_u.png", 0);
	 head_mask[3] = imread("snk_h_d.png", 0);
	 body = imread("snk_body.png");
	 body_mask = imread("snk_body.png", 0);
	 chicken = imread("chicken.png");
	 chicken_mask = imread("chicken.png", 0);
	 chicken_gold = imread("chicken_gold.png");
	 brick = imread("Brick.png");
	 brick_mask = imread("Brick.png", 0);
	 for (size_t i = 0; i < 8; i++)
	 {
		 int x = 100 + rand() % 500;
		 int y = 150 + rand() % 300;
		 brks[i] = Rect(x, y, 32, 32);

	 }
}

void resetLevel1(){
	mySnake.reset();
	hen.reset();
	srand(time(0));
	for (int i = 0; i < 8; i++){
		int x = 100 + rand() % 500;
		int y = 150 + rand() % 300;
		brks[i] = Rect(x, y, 32, 32);
	}
}

bool playLevel1(char c,int* points){
	bool flag = true;
	*points = mySnake.getPoints();
	if (mySnake.getPoints() >= 50 || c == 'q' ){
		destroyWindow("Snake");
		resetLevel1();
		flag = false;

	}
	else
	{
		flag = true;
		arena.copyTo(temp);
		Point* snakeBody = mySnake.getSnakeBody();
		int length = mySnake.getSnakeLength();
		drawSnake(snakeBody, length, mySnake.getHeading());
		drawBricks();
		showPoints();
		mySnake.setHeading(c);
		mySnake.move();
		if (isOut(snakeBody) || isHit(snakeBody) || isEatingMySelf(snakeBody, length)){
			waitKey(0);
			resetLevel1();
		}
		else
		{
			if (hen.getIsOffering() == false){
				hen.offer();
				hen.setIsOffering(true);

				while (wrongHenPos(hen.getPos(), snakeBody, length)){
					hen.adjustPos();
				}

			}

			else{
				drawHen(hen.getPos(), hen.getIsCombo());
				if (henEaten(hen.getPos(), snakeBody)){
					hen.setIsOffering(false);
					mySnake.incPoints(5);
					mySnake.grow(7);
				}

			}
			

		}
		namedWindow("Snake");
		imshow("Snake", temp);
	}
		
	return flag;
	
	
}

void drawSnake(Point* snakeBody,int length,char h){
	Mat ROI;


	for (int i = 1; i < length; i++){
		ROI = temp(Rect(snakeBody[i].x, snakeBody[i].y, 25, 25));
		body.copyTo(ROI, body_mask);
	}

	if (h == 'l'){
	    ROI = temp(Rect(snakeBody[0].x, snakeBody[0].y, 40, 25));
		head[0].copyTo(ROI, head_mask[0]);
	}
	else if (h == 'r'){
		ROI = temp(Rect(snakeBody[0].x, snakeBody[0].y, 40, 25));
		head[1].copyTo(ROI, head_mask[1]);
		
	}
	else if (h == 'u'){
		ROI = temp(Rect(snakeBody[0].x, snakeBody[0].y, 25, 40));
		head[2].copyTo(ROI, head_mask[2]);
		
	}
	else if (h == 'd'){
		ROI = temp(Rect(snakeBody[0].x, snakeBody[0].y, 25, 40));
		head[3].copyTo(ROI, head_mask[3]);
	}


	
	
}

void drawBricks(){
	for (int i = 0; i < 8; i++ ){
		
		
		Mat ROI = temp(brks[i]);
		brick.copyTo(ROI);
	}

}

bool isOut(Point* snakeBody){
	return (!Rect(Point(42, 34), Point(715, 523)).contains(snakeBody[0]));
}

bool isHit(Point* snakeBody){
	for (int i = 0; i < 8; i++){
		if (brks[i].contains(snakeBody[0]) ||
			brks[i].contains(Point(snakeBody[0].x + 25, snakeBody[0].y))
			|| brks[i].contains(Point(snakeBody[0].x, snakeBody[0].y + 25))
			|| brks[i].contains(Point(snakeBody[0].x + 25, snakeBody[0].y + 25)))
		{
			return true;
		}
	}
	return false;

}

bool isEatingMySelf(Point* snakeBody, int length){
	for (int i = 2; i < length; i++){
		if (snakeBody[0].inside(Rect(snakeBody[i].x, snakeBody[i].y, 8, 8)))
			return true;
	}

	return false;
}


void drawHen(Point pos,bool isCombo){
	Mat ROI = temp(Rect(pos.x, pos.y, 34, 50));
	if (isCombo){
		chicken_gold.copyTo(ROI, chicken_mask);
	}
	else{
		chicken.copyTo(ROI, chicken_mask);
	}
}

bool wrongHenPos(Point pos, Point* snakeBody, int length){
	for (int i = 2; i < length; i++){
		Rect snakeBlock = Rect(snakeBody[i].x, snakeBody[i].y, 25, 25);
		if (snakeBlock.contains(pos) || snakeBlock.contains(Point(pos.x + 34, pos.y))
			|| snakeBlock.contains(Point(pos.x + 34, pos.y + 50))
			|| snakeBlock.contains(Point(pos.x, pos.y + 50))
			|| snakeBlock.contains(Point(pos.x + 17, pos.y + 25)))
		{
			return true;
		}

	}
	for (int  i = 0; i < 8; i++){
		if (brks[i].contains(pos) ||
			brks[i].contains(Point(pos.x + 34, pos.y))
			|| brks[i].contains(Point(pos.x + 34, pos.y + 50))
			|| brks[i].contains(Point(pos.x, pos.y + 50))
			|| brks[i].contains(Point(pos.x + 17, pos.y + 25)))
		{
			return true;
		}
	}

	return false;

}


bool henEaten(Point pos, Point* snakeBody){
	Rect prey = Rect(pos.x, pos.y, 34, 50);
	if (prey.contains(snakeBody[0]) ||
		prey.contains(Point(snakeBody[0].x + 25, snakeBody[0].y))
		|| prey.contains(Point(snakeBody[0].x + 25, snakeBody[0].y + 25))
		|| prey.contains(Point(snakeBody[0].x, snakeBody[0].y + 25))){
		return true;
	}
	return false;
}

void showPoints(){
	putText(temp, to_string(mySnake.getPoints()) + "/50", Point(650, 50),
		CV_FONT_HERSHEY_COMPLEX_SMALL, 2, Scalar(242,61,10), 2);
}     