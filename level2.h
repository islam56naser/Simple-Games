#pragma once
#include "opencv2\imgproc.hpp" 
#include "opencv2\highgui.hpp"
#include "Ship.h"
#include "missile.h"
#include <iostream>


using namespace cv;

using namespace std;

bool playLevel2(char c, int* points);
void resetLevel2();
bool isOut2(Point pos);
bool isHit2();
void showTime();
void drawShip(char c);
void moveShip(char c);
void drawMissile(Point pos);
void explode();
void initLevel2Variables();
static Mat ship_s[3], ship_s_mask[3], missiles[2], missiles_mask[2], boom, boom_mask, warZone, frame, temp2;
static Ship enigma;
static missile bwazik[5];
static int cntr, step, startY, dir, steady_count, T;
static clock_t start;