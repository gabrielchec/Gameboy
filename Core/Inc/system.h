#define LCD_SIZE 504
#define LCD_COL_SIZE 84
#define LCD_ROW_SIZE 48

#include "main.h"
#include "FONT.h"
SPI_HandleTypeDef hspi2;

extern uint8_t display[LCD_SIZE];
extern void system_init();
extern void lcd_reset();
extern void lcd_cmd(uint8_t cmd);
extern void lcd_data(const uint8_t* data, int size);
extern void lcd_write_long_text(uint8_t* data, uint8_t row, uint8_t col);
extern void lcd_write_line(uint8_t* data, uint8_t row, uint8_t col);
