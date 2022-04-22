/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "Arduino.h"
int16_t a=1000;
static void screen_btn_OK_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(guider_ui.screen_1))
			setup_scr_screen_1(&guider_ui);
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
			lv_scr_load_anim(guider_ui.screen_1, LV_SCR_LOAD_ANIM_OVER_LEFT, 100, 100, true);
	
	}
		break;
	default:
		break;
	}
}

void events_init_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_btn_OK, screen_btn_OK_event_handler, LV_EVENT_ALL, NULL);
}

void setup_scr_screen(lv_ui *ui){

	//Write codes screen
	ui->screen = lv_obj_create(NULL);

	//Write codes screen_btn_BACK
	ui->screen_btn_BACK= lv_btn_create(ui->screen);
    setup_button(ui->screen_btn_BACK,5,85,"BACK");
	//Write codes screen_btn_UP
	ui->screen_btn_UP = lv_btn_create(ui->screen);
    setup_button(ui->screen_btn_UP,45,85,"UP");
	//Write codes screen_btn_DOWN
	ui->screen_btn_DOWN = lv_btn_create(ui->screen);
    setup_button(ui->screen_btn_DOWN,85,85,"DOWN");
	//Write codes screen_btn_OK
	ui->screen_btn_OK = lv_btn_create(ui->screen);
    setup_button(ui->screen_btn_OK,125,85,"OK");

	//Write codes screen_label_1
	ui->screen_label_1 = lv_label_create(ui->screen);
	setup_label(ui->screen_label_1,"SCREEN 0",31,30,100,32);

	// ui->screen_label_scroll = lv_label_create(ui->screen);
	// lv_label_set_long_mode(ui->screen_label_scroll, LV_LABEL_LONG_SCROLL_CIRCULAR);     /*Circular scroll*/
    // lv_obj_set_width(ui->screen_label_scroll, 150);
	
    // lv_label_set_text(ui->screen_label_scroll, "It is a circularly scrolling text.k " + a);
    // lv_obj_align(ui->screen_label_scroll, LV_ALIGN_TOP_LEFT, 0, 0);
	//Init events for screen
	events_init_screen(ui);
}