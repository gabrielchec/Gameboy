#include "menu.h"


void menu_draw(Menu *data){
	lcd_write_line(data->title.name, 0, 0);
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
	static int i = 0;
	static _Bool is_hold = 0;
	if(system_actual){					//is system is initialized
		if(!joystick_button_pressed && joystick_button_changed){
			menu_pressed(actual_menu);
			lcd_clear();
			menu_draw(actual_menu);
		}

		if(joystick_changed){
			if(joystick_direction.y){
				is_hold = 1;
				menu_change_set(actual_menu, joystick_direction.y);
				menu_draw(actual_menu);
			}
			else is_hold = 0;

		}
		else{
			if(is_hold)i++;
			else i = 0;
			if(i == 50){
				i -= 10;
				menu_change_set(actual_menu, joystick_direction.y);
				menu_draw(actual_menu);
			}
		}

	}
}

void menu_set(Menu *data, char *title, char items[][15], uint8_t size, _Bool * settable, void (*pointers[])()){
	data->size = size;
	strcpy(data->title.name ,title);
	for(uint8_t i = 0;i < size; i++){
		strcpy(data->data[i].name, *(items + i));
		data->data[i].settable = settable[i];
		data->data[i].fun = pointers[i];
	}
	for(uint8_t i = 0; i < size; i++){
		if(settable[i]){
			data->set = i;
			break;
		}
	}
	data->visible[0] = 0;
	data->visible[1] = 5;
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

extern void menu_pressed(Menu * data){
	if(data->data[data->set].fun)
		data->data[data->set].fun();
}

