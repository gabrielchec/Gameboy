#include "system.h"


void joy_scale(Point * p, uint8_t s){
		p->x = (p->x * s) / 1024;
	 	p->y = (p->y * s) / 1024;
	}

Point joy_move(){

	return (Point){( joystick[0] - 2048) / 4, (joystick[1] - 2048) / 4};
}

void joy_direction(Point * point){
	if(joystick[0] > 3500) point->x = 1;
	else if(joystick[0] < 500) point->x = -1;
	else point->x = 0;

	if(joystick[1] > 3500) point->y = 1;
	else if(joystick[1] < 500) point->y = -1;
	else point->y = 0;
}


Point add_points(Point * one, Point * two){
	return (Point){one->x + two->x, one->y + two->y};
}
