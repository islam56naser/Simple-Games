#pragma once
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include "Button.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"

using namespace cv;

void showMenu();
void updateIsLevel(bool* isLevel,int points);
void updateIsPlaying(bool* isPlaying);
