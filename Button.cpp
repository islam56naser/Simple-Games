#include "Button.h"

int Button::cntr = 0;
vector<Button*> Button::buttons;
Button::Button(Mat img, String winName, Rect rect, String text,Scalar color, bool active)
{
	this->img = img;
	this->rect = rect;
	this->text = text;
	this->winName = winName;
	this->color = color;
	this->active = active;
	this->isPressed = false;
	cntr++;
	buttons.resize(cntr);
	buttons[cntr - 1] = this;
	namedWindow(winName, 0);
	setMouseCallback(winName, &Button::myMouseCallBack);


}

Button::Button()
{
	this->img = Mat();
	this->rect = Rect();
	this->text = "";
	this->winName = "";
	this->color = Scalar();
	this->active = false;
	this->isPressed = false;
	//cntr++;
	//buttons.resize(cntr);
	//buttons[cntr - 1] = this;
	//namedWindow(winName, 0);
	//setMouseCallback(winName, &Button::myMouseCallBack);


}

void Button::drawButton(){

	rectangle(img,rect, color,CV_FILLED);
	putText(img, text, Point(rect.x + 130, rect.y + 60), CV_FONT_HERSHEY_TRIPLEX,
		2, Scalar(0),4);

}

void Button::myMouseCallBack(int event, int x, int y, int flags, void* param){

	switch (event){
	case CV_EVENT_MOUSEMOVE:
		for (int i = 0; i < buttons.size(); i++){
			if (buttons[i]->rect.contains(Point(x, y)) && buttons[i]->active){
				buttons[i]->color = Scalar(242,178,10);
			}
			else
			{
				buttons[i]->color = Scalar(242, 61, 10);
			}
		}
		break;


	case  CV_EVENT_LBUTTONDOWN:

		for (int i = 0; i < buttons.size(); i++){
			if (buttons[i]->rect.contains(Point(x, y)) && buttons[i]->active){
				buttons[i]->isPressed = true;
			}
			else
			{
				buttons[i]->isPressed = false;
			}
		}
		break;
	default:
		for (int i = 0; i < buttons.size() ; i++)
		{
			buttons[i]->color = Scalar(242, 61, 10);
		}
	}



}


	
void Button::setActive(bool active){
	this->active = active;
}


bool Button::getIsPressed(){
	return this->isPressed;
}

void Button::setIsPressed(bool flag){
	this->isPressed = flag;
}


Button::~Button(){

}