#ifndef MENU_H
#define MENU_H

#include "system.h"
#include "string.h"

typedef struct {
	char name[LCD_COL_SIZE - 5];
	_Bool settable;
	void (*fun)();
}MenuItem;

typedef struct {
	uint8_t size;
	MenuItem data[15];		//max size of games (can be changed)
	MenuItem title;
	int set;
	uint8_t visible[2];

}Menu;
Menu *actual_menu;
Menu main_menu;
_Bool is_initialized;

extern void menu_draw(Menu *data);
extern void menu_actual();
extern void menu_init();
extern void menu_set(Menu *data, char *title, char items[][15], uint8_t size, _Bool * settable);
extern void menu_move();
extern void menu_change_set(Menu * data, int dir);
extern void menu_pressed(Menu *_data);
extern uint8_t slide_bar[LCD_COL_SIZE * 4];

#endif
