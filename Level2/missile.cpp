#include "missile.h"


int missile::offset = 0;

missile::missile()
{
	this->pos = Point(0, 0);
	this->isAttacking = false;

}


void missile::reset(){
	this->pos = Point(0, 0);
	this->isAttacking = false;
}

void missile::launch(int dist){
		srand(time(0) * offset);
		int row = -100 + rand()% 70 ;
		int col = (5 + rand()% 88) * dist ;
		this->pos = Point(col, row);
		offset += 5;
}



void missile::attack(){
	this->pos.y += 6;
}


Point missile::getPos(){
	return this->pos;
}

void missile::setIsAttacking(bool flag){
	this->isAttacking = flag;
}

bool missile::getIsAttaking(){
	return this->isAttacking;

}
missile::~missile()
{

}
