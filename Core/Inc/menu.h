#ifndef MENU_H
#define MENU_H

#include "system.h"
#include "string.h"
#define MAIN_MENU_SIZE 4
typedef struct {
	uint8_t name[LCD_COL_SIZE - 5];
	_Bool set;
	_Bool settable;
	void (*fun)();
}Menu;

Menu main_menu[MAIN_MENU_SIZE];
extern void menu_draw();
extern void menu_actual();
extern void menu_init();
extern void menu_move();
extern void menu_change_set(int dir);
extern uint8_t slide_bar[LCD_COL_SIZE * 4];

#endif
