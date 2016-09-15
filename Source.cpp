#include "MainMenu.h"

int main(){
	int points = 0;
	bool isPlaying[] = {false,false,false};
	bool isLevel[] = {true, false, false};
	initLevel1Variables();
	initLevel2Variables();
	initLevel3Variables();

	while (true)
	{

		char c = waitKey(20);
	
		showMenu();
		updateIsPlaying(isPlaying);
		updateIsLevel(isLevel, points);
		if (isPlaying[0] && isLevel[0]) {
			isPlaying[0] = playLevel1(c,&points);
			
		}
		else if (isPlaying[1] && isLevel[1]){
			isPlaying[1] = playLevel2(c, &points);
		}
		else if (isPlaying[2] && isLevel[2]){
			isPlaying[2] = playLevel3(&points);
		}


		if (c == 27) break;
			
	}
	
}