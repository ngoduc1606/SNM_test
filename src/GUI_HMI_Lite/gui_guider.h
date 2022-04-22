/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
	lv_obj_t *screen_ABC;
	lv_obj_t *screen_ABC_button_Example;
	lv_obj_t *screen;
	lv_obj_t *screen_btn_BACK;
	lv_obj_t *screen_btn_UP;
	lv_obj_t *screen_btn_DOWN;
	lv_obj_t *screen_btn_OK;
	lv_obj_t *screen_label_1;
	lv_obj_t *screen_label_scroll;

	lv_obj_t *screen_1;
	lv_obj_t *screen_1_btn_BACK;
	lv_obj_t *screen_1_btn_UP;
	lv_obj_t *screen_1_btn_DOWN;
	lv_obj_t *screen_1_btn_OK;

	lv_obj_t *screen_1_label_1;
}lv_ui;


void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen(lv_ui *ui);
void setup_scr_screen_1(lv_ui *ui);
void setup_scr_screen_ABC(lv_ui *ui);

void setup_button(lv_obj_t *button, int pos_x, int pos_y, char * button_label_str);
void setup_label(lv_obj_t *label, char* label_text,int pos_x, int pos_y, int width,int height);
#ifdef __cplusplus
}
#endif
#endif