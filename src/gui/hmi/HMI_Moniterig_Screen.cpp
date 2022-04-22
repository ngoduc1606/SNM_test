/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "../general/gui_guider.h"

static void HMI_Monitering_Screen_btn_OK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(guider_ui.Menu_Screen))
			setup_HMI_Menu_Screen(&guider_ui);
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.Menu_Screen, LV_SCR_LOAD_ANIM_OVER_LEFT, 100, 100, true);
	}
		break;
	default:
		break;
	}
}

void events_init_HMI_Monitering_Screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Monitering_Screen_btn_MENU, HMI_Monitering_Screen_btn_OK_event_handler, LV_EVENT_ALL, NULL);
}

void setup_HMI_Monitering_Screen(lv_ui *ui){
    //Write codes screen
	ui->Monitering_Screen = lv_obj_create(NULL);
    //Create 6 button
    //Write codes Monitering_Screen_btn_MENU
    ui->Monitering_Screen_btn_MENU = lv_btn_create(ui->Monitering_Screen);
    setup_button(ui->Monitering_Screen_btn_MENU,5,245,"MENU");
    //Write codes Monitering_Screen_btn_UP
    ui->Monitering_Screen_btn_UP = lv_btn_create(ui->Monitering_Screen);
    setup_button(ui->Monitering_Screen_btn_UP,85,245,"UP");
    //Write codes Monitering_Screen_btn_BACK
    ui->Monitering_Screen_btn_BACK= lv_btn_create(ui->Monitering_Screen);
    setup_button(ui->Monitering_Screen_btn_BACK,45,245,"BACK");
    //Write codes Monitering_Screen_btn_DOWN
    ui->Monitering_Screen_btn_DOWN= lv_btn_create(ui->Monitering_Screen);
    setup_button(ui->Monitering_Screen_btn_DOWN,125,245,"DOWN");
    //Write codes Monitering_Screen_btn_OK
    ui->Monitering_Screen_btn_OK = lv_btn_create(ui->Monitering_Screen);
    setup_button(ui->Monitering_Screen_btn_OK,165,245,"OK");
    //Write codes Monitering_Screen_btn_ALARM
    ui->Monitering_Screen_btn_ALARM = lv_btn_create(ui->Monitering_Screen);
    setup_button(ui->Monitering_Screen_btn_ALARM,205,245,"ALARM");
    events_init_HMI_Monitering_Screen(ui);
}
