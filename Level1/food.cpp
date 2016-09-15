#include "food.h"

food::food(){
	this->pos = Point(100, 100);
	this->cntr = 0;
	this->isOffering = false;
	this->isCombo = false;

}

void food::reset(){
	this->pos = Point(100, 100);
	this->cntr = 0;
	this->isOffering = false;
	this->isCombo = false;
	this->offset = 0;
}

void food::offer(){
	srand(time(0)* offset);
	this->offset += 10;
	this->pos.x = (70 + rand() % 610);
	this->pos.y = (50 + rand() % 440);
	this->cntr++;
	if (cntr % 5 == 0){
		this->isCombo = true;
	} 
	else{
		this->isCombo = false;
	}


}

bool food::getIsCombo(){
	return this->isCombo;
}

void food::setIsOffering(bool flag){

	this->isOffering = flag;
}


bool food::getIsOffering(){
	return this->isOffering;
}

void food::adjustPos(){
	this->pos.x = 70 + rand() % 610;
	this->pos.y = 50 + rand() % 440;

}


Point food::getPos(){

	return this->pos;
}