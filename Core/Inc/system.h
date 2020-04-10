#define LCD_SIZE 504
#define LCD_COL_SIZE 84
#define LCD_ROW_SIZE 48

#include "main.h"
#include "FONT.h"


typedef struct {
	int x; 
	int y; 
 }Point;



SPI_HandleTypeDef hspi2;
ADC_HandleTypeDef hadc1;

uint16_t joystick[2];
extern uint8_t display[LCD_SIZE];
extern void system_init();
extern void lcd_reset();	
extern void lcd_clear();													
extern void lcd_cmd(uint8_t cmd);											
extern void lcd_data(const uint8_t* data, int size);							
extern void lcd_write_long_text(char* data, uint8_t row, uint8_t col);		
extern void lcd_write_line(char* data, uint8_t row, uint8_t col);
extern void lcd_set_point_v(_Bool value, uint8_t x, uint8_t y);
extern void lcd_set_point_p(_Bool value, const Point * point);

extern Point joy_move();											//return point with values with range [-512, 512]
extern void joy_scale(Point *p, uint8_t s);							//scale point by s value
extern void joy_direction();												//return point with values {-1,0,1} 
extern void joy_button_pressed();
_Bool joystick_button_pressed;										//1 if button ist pressed, 0 if button iss pulled
_Bool joystick_button_toggle;										//toogle joystick button when pressed
_Bool joystick_changed;
_Bool joystick_button_changed;
Point joystick_direction;


void (*system_actual)(void);
