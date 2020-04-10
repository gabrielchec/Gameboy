/*
 * snake.c
 *
 *  Created on: 10 kwi 2020
 *      Author: Gabriel
 */
#include "snake.h"

void snake_menu_set(){
	actual_menu = &snake_menu;
}

void snake_new_game(){
	system_actual = test_draw;
	lcd_clear();

}

void test_draw(){
	lcd_clear();

	Point x = {70,10};
	Point y = {20,40};
	Point a[4] = {{70,10}, {20,40},{10,40},{20,10},{10,10}};
	draw_vertex(a,4);

}
