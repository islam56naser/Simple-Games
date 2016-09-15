#include "Ship.h"


Ship::Ship()
{
	this->pos = Point(150, 537);
}

void Ship::reset(){
	this->pos = Point(150, 537);
}


Point Ship::getPos(){

	return this->pos;
}


void Ship::move(char c){
	if (c == 'a'){
		this->pos.x -= 8;
	}
	else if (c == 'd'){
		this->pos.x += 8;
	}
}

Ship::~Ship()
{
}
