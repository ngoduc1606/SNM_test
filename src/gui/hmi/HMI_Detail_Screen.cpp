/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "../general/gui_guider.h"
// #include "events_init.h"



static void HMI_Detail_Screen_btn_BACK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(guider_ui.Menu_Screen))
			setup_Menu_Screen(&guider_ui);
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.Menu_Screen, LV_SCR_LOAD_ANIM_OVER_RIGHT, 100, 100, true);
	}
		break;
	default:
		break;
	}
}

void events_init_HMI_Detail_Screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Detail_Screen_btn_BACK, HMI_Detail_Screen_btn_BACK_event_handler, LV_EVENT_ALL, NULL);
}
void setup_HMI_Detail_Screen(lv_ui *ui){

	//Write codes screen_1
	ui->Detail_Screen = lv_obj_create(NULL);
	//Create 6 button
		//Write codes Detail_Screen_btn_MENU
		ui->Detail_Screen_btn_MENU = lv_btn_create(ui->Detail_Screen);
		setup_button(ui->Detail_Screen_btn_MENU,5,245,"MENU");
		//Write codes Detail_Screen_btn_UP
		ui->Detail_Screen_btn_UP = lv_btn_create(ui->Detail_Screen);
		setup_button(ui->Detail_Screen_btn_UP,85,245,"UP");
		//Write codes Detail_Screen_btn_BACK
		ui->Detail_Screen_btn_BACK= lv_btn_create(ui->Detail_Screen);
		setup_button(ui->Detail_Screen_btn_BACK,45,245,"BACK");
		//Write codes Detail_Screen_btn_DOWN
		ui->Detail_Screen_btn_DOWN= lv_btn_create(ui->Detail_Screen);
		setup_button(ui->Detail_Screen_btn_DOWN,125,245,"DOWN");
		//Write codes Detail_Screen_btn_OK
		ui->Detail_Screen_btn_OK = lv_btn_create(ui->Detail_Screen);
		setup_button(ui->Detail_Screen_btn_OK,165,245,"OK");
		//Write codes Detail_Screen_btn_ALARM
		ui->Detail_Screen_btn_ALARM = lv_btn_create(ui->Detail_Screen);
		setup_button(ui->Detail_Screen_btn_ALARM,205,245,"ALARM");

	//Write codes screen_1_label_1
	ui->Detail_Screen_label_1 = lv_label_create(ui->Detail_Screen);
	setup_label(ui->Detail_Screen_label_1,"SCREEN DETAIL",31,30,100,32);

	events_init_HMI_Detail_Screen(ui);
}