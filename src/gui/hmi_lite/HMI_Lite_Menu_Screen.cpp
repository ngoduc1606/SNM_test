/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "../general/gui_guider.h"
typedef struct ScreenMenu
{
	int temperature = 23, humidity = 75;
	int hour = 14, minute = 10;
	char Option[100]="Connection\nMeasure\nLog Data\nFault & Alarm\nOthers\nDebug\nAbout";
	char time[10], information[100];
};

ScreenMenu Menu_Screens;
static void Menu_Screen_btn_BACK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(guider_ui.Monitering_Screen))
			setup_Monitering_Screen(&guider_ui);
		//pointer to object's dispaly
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.Monitering_Screen, LV_SCR_LOAD_ANIM_OVER_RIGHT, 100, 100, true);
	}
		break;
	default:
		break;
	}
}
static void Menu_Screen_btn_OK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(guider_ui.Detail_Screen))
			setup_Detail_Screen(&guider_ui);
		//pointer to object's dispaly
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.Detail_Screen, LV_SCR_LOAD_ANIM_OVER_LEFT, 100, 100, true);
	}
		break;
	default:
		break;
	}
}
static void Menu_Screen_btn_UP_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		uint8_t roller_selected = lv_roller_get_selected(guider_ui.Menu_Screen_roller);
		roller_selected++;
		lv_roller_set_selected(guider_ui.Menu_Screen_roller,roller_selected,LV_ANIM_ON);
	}
		break;
	default:
		break;
	}
}
static void Menu_Screen_btn_DOWN_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		uint8_t roller_selected = lv_roller_get_selected(guider_ui.Menu_Screen_roller);
		roller_selected--;
		lv_roller_set_selected(guider_ui.Menu_Screen_roller,roller_selected,LV_ANIM_ON);
	}
		break;
	default:
		break;
	}
}
void events_init_Menu_Screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Menu_Screen_btn_BACK, Menu_Screen_btn_BACK_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Menu_Screen_btn_OK, Menu_Screen_btn_OK_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Menu_Screen_btn_DOWN, Menu_Screen_btn_DOWN_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Menu_Screen_btn_UP, Menu_Screen_btn_UP_event_handler, LV_EVENT_ALL, NULL);
}


void setup_Menu_Screen(lv_ui *ui){

	//Write codes screen
	ui->Menu_Screen = lv_obj_create(NULL);

	//Create 4 button
	//Write codes Menu_Screen_btn_BACK
	ui->Menu_Screen_btn_BACK= lv_btn_create(ui->Menu_Screen);
	setup_button(ui->Menu_Screen_btn_BACK,5,85,"BACK");
	//Write codes Menu_Screen_btn_UP
	ui->Menu_Screen_btn_UP = lv_btn_create(ui->Menu_Screen);
	setup_button(ui->Menu_Screen_btn_UP,45,85,"UP");
	//Write codes Menu_Screen_btn_DOWN
	ui->Menu_Screen_btn_DOWN = lv_btn_create(ui->Menu_Screen);
	setup_button(ui->Menu_Screen_btn_DOWN,85,85,"DOWN");
	//Write codes Menu_Screen_btn_OK
	ui->Menu_Screen_btn_OK = lv_btn_create(ui->Menu_Screen);
	setup_button(ui->Menu_Screen_btn_OK,125,85,"OK");

	//create notified obj
	ui->Menu_Screen_notified_obj = lv_obj_create(ui->Menu_Screen);
	lv_obj_set_pos(ui->Menu_Screen_notified_obj, 0, 0);
	lv_obj_set_size(ui->Menu_Screen_notified_obj, 160, 20);
	//create font wifi
	ui->Menu_Screen_label_wifi = lv_label_create(ui->Menu_Screen_notified_obj);
	setup_label(ui->Menu_Screen_label_wifi,"wifi",-10,-15,15,15);
	lv_label_set_text(ui->Menu_Screen_label_wifi,LV_SYMBOL_WIFI);
	//create font bluetooth
	ui->Menu_Screen_label_bluetooth = lv_label_create(ui->Menu_Screen_notified_obj);
	setup_label(ui->Menu_Screen_label_bluetooth,"bluetooth",5,-15,15,15);
	lv_label_set_text(ui->Menu_Screen_label_bluetooth,LV_SYMBOL_BLUETOOTH);
	//create font warning
	ui->Menu_Screen_label_warning = lv_label_create(ui->Menu_Screen_notified_obj);
	setup_label(ui->Menu_Screen_label_warning,"warning",20,-15,15,15);
	lv_label_set_text(ui->Menu_Screen_label_warning,LV_SYMBOL_WARNING);
	//create font modbus_active
	ui->Menu_Screen_label_modbus_active = lv_label_create(ui->Menu_Screen_notified_obj);
	setup_label(ui->Menu_Screen_label_modbus_active,"modbus_active",50,-15,15,15);
	lv_label_set_text(ui->Menu_Screen_label_modbus_active,LV_SYMBOL_REFRESH);
	//create font SD
	ui->Menu_Screen_label_SD = lv_label_create(ui->Menu_Screen_notified_obj);
	setup_label(ui->Menu_Screen_label_SD,"SD Card",37,-15,10,15);
	lv_label_set_text(ui->Menu_Screen_label_SD,LV_SYMBOL_SD_CARD);

	//create label time
	ui->Menu_Screen_label_time = lv_label_create(ui->Menu_Screen_notified_obj);
	sprintf(Menu_Screens.time, "%d:%d",Menu_Screens.hour,Menu_Screens.minute);
	setup_label(ui->Menu_Screen_label_time, Menu_Screens.time,90,-15,40,15); 
	//create roller Menu
	ui->Menu_Screen_roller = lv_roller_create(ui->Menu_Screen);
	setup_roller(ui->Menu_Screen_roller,Menu_Screens.Option,2,LV_ALIGN_CENTER,100,0,5);
	events_init_Menu_Screen(ui);
}