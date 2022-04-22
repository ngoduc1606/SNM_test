/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "Arduino.h"


static void screen_1_btn_BACK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(guider_ui.screen))
		{
			setup_scr_screen(&guider_ui);
			Serial.printf("setup screen done\n");
		}
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			lv_scr_load_anim(guider_ui.screen, LV_SCR_LOAD_ANIM_OVER_RIGHT, 100, 100, true);
			Serial.printf("vua an chuyen trang \n");
		}
	}
		break;
	default:
		break;
	}
}


void events_init_screen_1(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_1_btn_BACK, screen_1_btn_BACK_event_handler, LV_EVENT_ALL, NULL);
}


void setup_scr_screen_1(lv_ui *ui){

	//Write codes screen_1
	ui->screen_1 = lv_obj_create(NULL);
	
	//Write codes screen_1_btn_BACK
	ui->screen_1_btn_BACK= lv_btn_create(ui->screen_1);
    setup_button(ui->screen_1_btn_BACK,5,85,"BACK");
	//Write codes screen_1_btn_UP
	ui->screen_1_btn_UP = lv_btn_create(ui->screen_1);
    setup_button(ui->screen_1_btn_UP,45,85,"UP");
	//Write codes screen_1_btn_DOWN
	ui->screen_1_btn_DOWN = lv_btn_create(ui->screen_1);
    setup_button(ui->screen_1_btn_DOWN,85,85,"DOWN");
	//Write codes screen_1_btn_OK
	ui->screen_1_btn_OK = lv_btn_create(ui->screen_1);
    setup_button(ui->screen_1_btn_OK,125,85,"OK");

	//Write codes screen_1_label_1
	ui->screen_1_label_1 = lv_label_create(ui->screen_1);
	setup_label(ui->screen_1_label_1,"SCREEN 1",31,30,100,32);

	

	events_init_screen_1(ui);
}