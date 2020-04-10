/*
 * run.c
 *
 *  Created on: 10 kwi 2020
 *      Author: Gabriel
 */

#include "run.h"

void system_setup(){
	system_actual = menu_actual;
	  system_init();
	  main_menu_init();
	  snake_menu_init();
}

void main_menu_init(){
	char game_list[7][15];
	strcpy(game_list[0],"Snake         ");
	strcpy(game_list[1],"Tetris        ");
	strcpy(game_list[2],"Tic Tac Toe   ");
	strcpy(game_list[3],"Pokemon       ");
	strcpy(game_list[4],"Minesweeper   ");
	strcpy(game_list[5],"Sudoku        ");
	strcpy(game_list[6],"Truth or dare ");
	void (*pointers[7])();
	pointers[0] = snake_menu_set;
	pointers[1] = NULL;
	pointers[2] = NULL;
	pointers[3] = NULL;
	pointers[4] = NULL;
	pointers[5] = NULL;
	pointers[6] = NULL;

	_Bool set_list[7] = {1, 1, 1, 1, 1, 1, 1};
	char title[15];
	strcpy(title,  "List of games ");
	menu_set(&main_menu, title, game_list, 7, set_list, pointers);
	actual_menu = &main_menu;
}

void snake_menu_init(){

	char items[SNAKE_MENU_SIZE][15];
	strcpy(items[0],"Resume        ");
	strcpy(items[1],"Start         ");
	strcpy(items[2],"Options       ");
	strcpy(items[3],"Exit          ");
	_Bool set_list[SNAKE_MENU_SIZE] = {0, 1, 1, 1};
	char title[15];
	strcpy(title,  "Snake         ");
	void (*pointers[SNAKE_MENU_SIZE])();
	pointers[0] = NULL;
	pointers[1] = snake_new_game;
	pointers[2] = NULL;
	pointers[3] = exit_game;
	menu_set(&snake_menu, title, items, SNAKE_MENU_SIZE, set_list, pointers);
}


void exit_game(){
	system_actual = menu_actual;
	actual_menu = &main_menu;

}

