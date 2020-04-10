/*
 * graphic.h
 *
 *  Created on: 10 kwi 2020
 *      Author: Gabriel
 */

#include "system.h"
#include "math.h"
#ifndef INC_GRAPHIC_H_
#define INC_GRAPHIC_H_

extern Point add_points(Point a, Point b);
extern Point substract_points(Point a, Point b);

extern void draw_line(Point a, Point b);
extern void draw_rectangle(Point a, Point c, _Bool filled);
extern void draw_triangle(Point a, Point b, Point c, _Bool filled);
extern void draw_circle(Point a, uint8_t size, _Bool filled);
extern void draw_vertex(Point *a, int size);
extern void circle(Point a, int x, int y);


#endif /* INC_GRAPHIC_H_ */
