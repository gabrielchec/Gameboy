#include "menu.h"


void menu_draw(Menu *data){
	lcd_write_long_text(data->title.name, 0, 0);
	for(uint8_t i = data->visible[0], k = 1; i < data->visible[1]; i++, k++){
		lcd_write_long_text(data->data[i].name, k, 0);
		if(k - 1 + data->visible[0] == data->set){
			uint8_t* buffer = &display[k * LCD_COL_SIZE];
			for(int j = 0; j < LCD_COL_SIZE - 5; j++){
				buffer[j] = ~buffer[j];
			}
		}
	}
}

void menu_actual(){
	if(is_initialized){
		if(joystick_changed){
			if(joystick_direction.y){
				menu_change_set(actual_menu, joystick_direction.y);
				menu_draw(actual_menu);
			}
		}
	}
}

void menu_set(Menu *data, char *title, char items[][15], uint8_t size, _Bool * settable){
	data->size = size;
	strcpy(data->title.name ,"List of games ");
	data->title.settable = 0;
	for(uint8_t i = 0;i < size; i++){
		strcpy(data->data[i].name, *(items + i));
		data->data[i].settable = settable[i];

	}
	data->set = 0;
	data->visible[0] = 0;
	data->visible[1] = 5;
}

void menu_init(){
	char game_list[7][15];
	strcpy(game_list[0],"Snake         ");
	strcpy(game_list[1],"Tetris        ");
	strcpy(game_list[2],"Tic Tac Toe   ");
	strcpy(game_list[3],"Pokemon       ");
	strcpy(game_list[4],"Minesweeper   ");
	strcpy(game_list[5],"Sudoku        ");
	strcpy(game_list[6],"Truth or dare ");

	_Bool set_list[6] = {1, 1, 1, 0, 1, 1, 1};
	char title[15];
	strcpy(title,  "List of games ");
	menu_set(&main_menu, title, game_list, 7, set_list);
	actual_menu = &main_menu;
	is_initialized = 1;
}

void menu_change_set( Menu * data, int dir){
	int i = data->set;

	int n = 0;
	if(dir == 1){
		n = i < (data->size) - 1 ? i + 1 : 0;
		while(!(data->data[n].settable)){
			n++;
			if(n >= data->size) n = 0;
		}
	}
	else if(dir == -1){
		n = i > 0 ? i - 1 : (data->size) - 1;
		while(!data->data[n].settable){
			n--;
			if(n < 0) n = data->size - 1;
		}
	}
	data->set = n;
	if(n >= data->visible[1]){
		data->visible[1] = n + 1;
		data->visible[0] = n - 4;
	}
	else if( n < data->visible[0]){
		data->visible[0] = n;
		data->visible[1] = n + 5;
	}
}

extern void menu_pressed(){

}

