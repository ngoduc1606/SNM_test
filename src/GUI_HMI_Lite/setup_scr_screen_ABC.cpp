// /*
//  * Copyright 2022 NXP
//  * SPDX-License-Identifier: MIT
//  * The auto-generated can only be used on NXP devices
//  */

// #include "lvgl.h"
// #include <stdio.h>
// #include "gui_guider.h"
// #include "events_init.h"
// #include "custom.h"

// static lv_style_t style_screen_ABC;
// static lv_style_t style_screen_ABC_button_Example;
// static lv_style_t style_screen_ABC_button_Example_label;

// void setup_scr_screen_ABC(lv_ui *ui){
//     //Write codes screen
// 	ui->screen_ABC = lv_obj_create(NULL);

//     //Write style state: LV_STATE_DEFAULT for style_screen_ABC
// 	if (style_screen_ABC.prop_cnt > 1)
// 		lv_style_reset(&style_screen_ABC);
// 	else
// 		lv_style_init(&style_screen_ABC);
// 	lv_style_set_bg_color(&style_screen_ABC, lv_color_make(0xff, 0xff, 0xff));
// 	lv_style_set_bg_opa(&style_screen_ABC, 0);
// 	lv_obj_add_style(ui->screen_ABC, &style_screen_ABC, LV_PART_MAIN|LV_STATE_DEFAULT);

//     //CREATE button
//     ui->screen_ABC_button_Example = lv_btn_create(ui->screen_ABC);
//     create_button(ui->screen_ABC_button_Example,0,0,style_screen_ABC_button_Example);
//     // label for button
//     ui->screen_ABC_button_Example_label =  lv_label_create(ui->screen_ABC_button_Example);
//     create_label_button(ui->screen_ABC_button_Example_label,"example");
// }
