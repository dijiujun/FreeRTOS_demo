/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    lvgl.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "lvgl.h"
#include "./src/drivers/display/st7789/lv_st7789.h"
#include "./demos/lv_demos.h"
#include "lv_port_disp.h"



/* USER CODE BEGIN 1 */
// 最小LVGL测试代码
void lvgl_minimal_test(void)
{
    lv_obj_t * label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "LVGL Test");
    lv_obj_center(label);
    
    lv_obj_t * btn = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btn, 100, 50);
    lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, 0, -10);
    
    lv_obj_t * btn_label = lv_label_create(btn);
    lv_label_set_text(btn_label, "Click");
    lv_obj_center(btn_label);
}

    void ui_init()
    {
            lv_obj_t *obj;

            /* set screen background to white */
            lv_obj_t *scr = lv_screen_active();
            lv_obj_set_style_bg_color(scr, lv_color_white(), 0);
            lv_obj_set_style_bg_opa(scr, LV_OPA_100, 0);

            /* create label */
            obj = lv_label_create(scr);
        lv_obj_set_align(obj, LV_ALIGN_CENTER);
        lv_obj_set_height(obj, LV_SIZE_CONTENT);
        lv_obj_set_width(obj, LV_SIZE_CONTENT);
        lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_color(obj, lv_color_black(), 0);
        lv_label_set_text(obj, "Hello World!");
    }

    void LVGL_Task(void const *argument)
{
        /* Initialize LVGL */
        lv_init();
        lv_port_disp_init();

        //ui_init();
        lv_demos_create("music", 0);
        //lv_demos_create("benchmark", 1);
        //lvgl_minimal_test();
        for(;;) {
                /* The task running lv_timer_handler should have lower priority than that running `lv_tick_inc` */
                lv_timer_handler();
                /* raise the task priority of LVGL and/or reduce the handler period can improve the performance */
                osDelay(10);
        }
}
/* USER CODE END 1 */

