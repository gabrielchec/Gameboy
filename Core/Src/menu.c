#include "menu.h"


void menu_draw(){
	Menu * data = main_menu;
	int i = 0;
	while( i < MAIN_MENU_SIZE){
		lcd_write_long_text(data[i].name, i, 0);
		if(data[i].set){
			uint8_t* buffer = &display[i * LCD_COL_SIZE];
			for(int j = 0; j < LCD_COL_SIZE - 5; j++){
				buffer[j] = ~buffer[j];
			}
		}
		i++;
	}
}

void menu_actual(){
	if(joystick_changed){
		if(joystick_direction.y){
			menu_change_set(joystick_direction.y);
			menu_draw();
		}
	}
}

void menu_init(){
	strcpy(main_menu[0].name,"List of games ");
	main_menu[0].settable = 0;
	main_menu[0].set = 0;

	strcpy(main_menu[1].name, "Snake         ");
	main_menu[1].settable = 1;
	main_menu[1].set = 1;

	strcpy(main_menu[2].name, "Tetris        ");
	main_menu[2].settable = 1;
	main_menu[2].set = 0;

	strcpy(main_menu[3].name, "Tic Tac Toe   ");
	main_menu[3].settable = 1;
	main_menu[3].set = 0;
	//menu_draw();
}

extern void menu_change_set(int dir){
	Menu * data = main_menu;
	for(uint8_t i = 0; i < MAIN_MENU_SIZE;i++){
		if(data[i].set == 1){
			if(dir == 1){
				int n = i < MAIN_MENU_SIZE -1 ? i + 1 : 0;
				while(!data[n].settable){
					n++;
					if(n >= MAIN_MENU_SIZE) n = 0;
				}
				data[n].set = 1;
				data[i].set = 0;
			}
			else if(dir == -1){
				int p = i > 0 ? i - 1 : MAIN_MENU_SIZE - 1;
				while(!data[p].settable){
					p--;
					if(p < 0) p = MAIN_MENU_SIZE - 1;
				}
				data[p].set = 1;
				data[i].set = 0;
			}
			break;
		}
	}
}

