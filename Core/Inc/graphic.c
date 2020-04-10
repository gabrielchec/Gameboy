/*
 * graphic.c
 *
 *  Created on: 10 kwi 2020
 *      Author: Gabriel
 */

//extern uint8_t backgroundg[LCD_SIZE];
//extern uint8_t foreground[LCD_SIZE];
#include "graphic.h"

extern Point add_points(Point a, Point b){
	return (Point){a.x + b.x, a.y + b.y};
}

extern Point substract_points(Point a, Point b){
	return (Point){b.x - a.x, b.y - a.y};
}

void draw_line(Point a, Point b){
	if(a.x > b.x){
		Point c = a;
		a = b;
		b = c;
	}
	int y_0 = a.y - (b.y - a.y)/((b.x - a.x) * 1.) * a.x;
	for(int i = a.x; i <= b.x; i++){
		lcd_set_point_v(1, i, i * (b.y - a.y)/((b.x - a.x) * 1.) + y_0 );
	}
}

void draw_rectangle(Point a, Point c, _Bool filled){
	for(int i = a.x; i <= c.x; i++){
		for(int j = a.y; j <= c.y; j++){
			if(filled){
				lcd_set_point_v(1,i, j);
			}
			else{
				if(i == a.y || i == c.x || j == a.x || j == c.y){
					lcd_set_point_v(1,i, j);
				}
			}
		}
	}
}
void draw_triangle(Point a, Point b, Point c, _Bool filled){
	if(filled){
;
	}
	else{
		draw_line(a, b);
		draw_line(b, c);
		draw_line(a, c);
	}
}
void draw_circle(Point a, uint8_t size, _Bool filled){
	//Bresenham’s algorithm
	int x = 0, y = size;
	int d = 3 - 2 * size;
	circle(a, x, y);
	 while (y >= x) {
	       x++;
	        if (d > 0){
	            y--;
	            d = d + 4 * (x - y) + 10;
	        }
	        else
	            d = d + 4 * x + 6;
	        circle(a, x, y);
	    }
	}


void circle(Point a, int x, int y)
{
    lcd_set_point_v(1, a.x + x, a.y + y);
    lcd_set_point_v(1, a.x - x, a.y + y);
    lcd_set_point_v(1, a.x + x, a.y - y);
    lcd_set_point_v(1, a.x - x, a.y - y);
    lcd_set_point_v(1, a.x + y, a.y + x);
    lcd_set_point_v(1, a.x - y, a.y + x);
    lcd_set_point_v(1, a.x + y, a.y - x);
    lcd_set_point_v(1, a.x - y, a.y - x);
}

extern void draw_vertex(Point *a, int size){
	for(int i = 0; i < size - 1; i++){
		draw_line(a[i], a[i + 1]);
	}
	draw_line(a[0], a[size - 1]);
}
