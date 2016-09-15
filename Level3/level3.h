#pragma once
#include<opencv2\highgui.hpp>
#include "opencv2\imgproc.hpp"


using namespace cv;
using namespace std;


bool playLevel3(int* points);
void initLevel3Variables();
static Mat ROI, monsters[3], monster_mask, monster_Dead, monster_Dead_mask, Original, temp3, mask, imgroi;
static VideoCapture cap;
static Point monsterPos;
static int LowH, HighH, LowS, HighS, LowV, HighV, monsterNom;
static bool isDead;
static Scalar color;