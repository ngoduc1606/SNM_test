/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"

lv_ui guider_ui;
void setup_ui(lv_ui *ui){
	setup_Monitering_Screen(ui);
	lv_scr_load(ui->Monitering_Screen);
}

void setup_button(lv_obj_t *button, int pos_x, int pos_y, char * button_label_str)
{
    lv_obj_set_pos(button, pos_x, pos_y);
	lv_obj_set_size(button, 30, 15);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn
	static lv_style_t style_button ;
	if (style_button.prop_cnt > 1)
		lv_style_reset(&style_button);
	else
		lv_style_init(&style_button);
	lv_style_set_radius(&style_button, 5);
	lv_style_set_bg_color(&style_button, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_button, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_button, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_button, 255);
	lv_style_set_shadow_color(&style_button, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_button, 255);
	lv_style_set_border_color(&style_button, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_button, 0);
	lv_style_set_border_opa(&style_button, 255);
	lv_obj_add_style(button, &style_button, LV_PART_MAIN|LV_STATE_DEFAULT);

	lv_obj_t *btn_label;
	btn_label = lv_label_create(button);
    lv_label_set_text(btn_label, button_label_str);
    lv_obj_set_style_text_color(btn_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(btn_label, &lv_font_montserrat_8, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(button, 0, LV_STATE_DEFAULT);
    lv_obj_align(btn_label, LV_ALIGN_CENTER, 0, 0);
}

void setup_label(lv_obj_t *label, char* label_text,int pos_x, int pos_y, int width,int height)
{
	lv_obj_set_pos(label, pos_x, pos_y);
	lv_obj_set_size(label, width, height);
	lv_label_set_text(label, label_text);
	lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
}
void setup_roller(lv_obj_t *roller, char* option,int row_count, int align,int width, int pos_x, int pos_y)
{
	lv_roller_set_options(roller, option, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(roller, row_count);
    lv_obj_set_width(roller, width);
	lv_obj_align(roller, align, pos_x, pos_y);
}
