#ifndef _SPRITE_H
#define _SPRITE_H

#include "string.h"
#include "color.h"

#define LCD_WIDTH_PX 384
#define LCD_HEIGHT_PX 216 

void VRAM_XORSprite(const color_t* data, int x, int y, int width, int height) {
   color_t* VRAM = (color_t*)0xA8000000;
   VRAM += (LCD_WIDTH_PX*y + x);
   short i, j;
   for(j=y; j<y+height; j++) {
      for(i=x; i<x+width;  i++) {
         *(VRAM++) ^= *(data++);
      }
      VRAM += (LCD_WIDTH_PX-width);
   }
}

void VRAM_XORSprite_Char(const char* data, int x, int y, int width, int height) { VRAM_XORSprite((const color_t *)data, x, y, width, height); }

void VRAM_CopySprite(const color_t* data, int x, int y, int width, int height) {
	//color_t* VRAM = (color_t*)0xA8000000; // For cg- 10/20
	color_t* VRAM = (color_t*)0xAC000000; //For cg- 50
	VRAM += (LCD_WIDTH_PX*y + x);
	short j;
	for(j=y; j<y+height; j++) {
		memcpy(VRAM,data,2*width);
		VRAM +=LCD_WIDTH_PX;
		data += width;
	}
}

void VRAM_CopySprite_Char(const char* data, int x, int y, int width, int height) { VRAM_CopySprite((const color_t *)data, x, y, width, height); }

#endif