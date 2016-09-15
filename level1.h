#pragma once
#include "snake.h"
#include "food.h"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp" 
using namespace cv;


bool playLevel1(char c,int* points);
void resetLevel1();
void drawSnake(Point* snakeBody, int length,char h);
void drawBricks();
bool isOut(Point* snakeBody);
bool isHit(Point* snakeBody);
bool isEatingMySelf(Point* snakeBody, int length);
void drawHen(Point pos,bool isCombo);
bool wrongHenPos(Point pos, Point* snakebody, int length);
bool henEaten(Point pos, Point* snakeBody);
void showPoints();
static food hen;
static Snake mySnake;
static Mat arena, temp, head[4], head_mask[4], body, body_mask, chicken, chicken_mask, chicken_gold, brick, brick_mask;
static Rect brks[8];
void initLevel1Variables();