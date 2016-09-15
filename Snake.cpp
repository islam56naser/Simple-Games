#include "Snake.h"

Snake::Snake(){
	this->heading = 'l';
	this->points = 0;
	this->snakeBody.resize(15);
	this->snakeBody[0] = Point(400, 100);
	this->snakeLength = 15;
	for (int i = 1; i < this->snakeBody.size(); i++){
		this->snakeBody[i] = Point(400 + i * (8), 100);
	}
}


void Snake::reset(){
	this->heading = 'l';
	this->points = 0;
	this->snakeBody.resize(15);
	this->snakeBody[0] = Point(400, 100);
	this->snakeLength = 15;
	for (int i = 1; i < this->snakeBody.size(); i++){
		this->snakeBody[i] = Point(400 + i *(8), 100);
	}
}

int Snake::getPoints(){
	return this->points;
}

void Snake::incPoints(short p){
	this->points += p;
}


void Snake::setHeading(char c){
	if (c == 'w' && this->heading != 'd' )      this->heading = 'u';
	else if (c == 's' && this->heading != 'u')  this->heading = 'd';
	else if (c == 'a' && this->heading != 'r')  this->heading = 'l';
	else if (c == 'd' && this->heading != 'l' ) this->heading = 'r';	
}


void Snake::grow(int N){
	int oldLen = this->snakeBody.size();
	this->snakeLength = oldLen + N;
	this->snakeBody.resize(this->snakeLength);
	for (int i = oldLen; i < this->snakeBody.size(); i++){
		this->snakeBody[i] = this->snakeBody[oldLen - 1];
	}

}


Point* Snake::getSnakeBody(){
	
	return this->snakeBody.data();
}

int Snake::getSnakeLength(){
	return this->snakeLength;
}

void Snake::move(){

	for (int i = this->snakeBody.size() - 1; i > 0; i--){
		this->snakeBody[i] = this->snakeBody[i - 1];

	}
	

	switch (this->heading){
	case 'l':
		
		this->snakeBody[0].x -= 8;
		break;

	case 'r':
		this->snakeBody[0].x += 8;
		break;
	case 'u':
		this->snakeBody[0].y -= 8;
		break;
	case'd':
		this->snakeBody[0].y += 8;
		break;
	}
}

char Snake::getHeading(){
	return this->heading;
}



