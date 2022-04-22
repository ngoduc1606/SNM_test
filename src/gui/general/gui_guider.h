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


	lv_obj_t *Menu_Screen;
	lv_obj_t *Menu_Screen_btn_BACK;
	lv_obj_t *Menu_Screen_btn_UP;
	lv_obj_t *Menu_Screen_btn_DOWN;
	lv_obj_t *Menu_Screen_btn_OK;
	lv_obj_t *Menu_Screen_btn_ALARM;
	lv_obj_t *Menu_Screen_btn_MENU;
	lv_obj_t *Menu_Screen_label_1;
	lv_obj_t *Menu_Screen_led_1;
	lv_obj_t *Menu_Screen_led_2;
	lv_obj_t *Menu_Screen_label_2;
	lv_obj_t *Menu_Screen_notified_obj;
	lv_obj_t *Menu_Screen_roller;
	lv_obj_t *Menu_Screen_label_wifi;
	lv_obj_t *Menu_Screen_label_bluetooth;
	lv_obj_t *Menu_Screen_label_warning;
	lv_obj_t *Menu_Screen_label_SD;
	lv_obj_t *Menu_Screen_label_modbus_active;
	lv_obj_t *Menu_Screen_label_time;
	
	lv_obj_t *Detail_Screen;
	lv_obj_t *Detail_Screen_btn_MENU;
	lv_obj_t *Detail_Screen_btn_UP;
	lv_obj_t *Detail_Screen_btn_DOWN;
	lv_obj_t *Detail_Screen_btn_BACK;
	lv_obj_t *Detail_Screen_btn_OK;
	lv_obj_t *Detail_Screen_btn_ALARM;
	lv_obj_t *Detail_Screen_label_1;

	lv_obj_t *Monitering_Screen;
	lv_obj_t *Monitering_Screen_btn_MENU;
	lv_obj_t *Monitering_Screen_btn_UP;
	lv_obj_t *Monitering_Screen_btn_DOWN;
	lv_obj_t *Monitering_Screen_btn_BACK;
	lv_obj_t *Monitering_Screen_btn_OK;
	lv_obj_t *Monitering_Screen_btn_ALARM;
	lv_obj_t *Monitering_Screen_label_1;
	
}lv_ui;


void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
//HMI_Lite
void setup_Monitering_Screen(lv_ui *ui);
void setup_Menu_Screen(lv_ui *ui);
void setup_Detail_Screen(lv_ui *ui);
//HMI
void setup_HMI_Monitering_Screen(lv_ui *ui);
void setup_HMI_Menu_Screen(lv_ui *ui);
void setup_HMI_Detail_Screen(lv_ui *ui);

void setup_button(lv_obj_t *button, int pos_x, int pos_y, char * button_label_str);
void setup_label(lv_obj_t *label, char* label_text,int pos_x, int pos_y, int width,int height);
void setup_roller(lv_obj_t *roller, char* option,int row_count, int align,int width, int pos_x, int pos_y);
// void setup_led(lv_obj_t *led, int pos_x, int pos_y, int width, int height);
#ifdef __cplusplus
}
#endif
#endif