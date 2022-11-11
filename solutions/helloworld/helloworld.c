/*
 * Copyright (C) 2015-2020 Alibaba Group Holding Limited
 */

#include "aos/init.h"
#include "board.h"
#include <aos/errno.h>
#include <aos/kernel.h>
#include <k_api.h>
#include <stdio.h>
#include <stdlib.h>
#include "led.h"
#include "key.h"

bool led1_switch = false;

static void short_press_handler()
{
    if (led1_switch)
    {
        led1_switch = false;
        led_switch(1, LED_OFF);
    }
    else
    {
        led1_switch = true;
        led_switch(1, LED_ON);
    }
}

int application_start(int argc, char *argv[])
{
    int count = 0;
    key_cfg_t key_cfg = {0, 0, short_press_handler, NULL};

    printf("nano entry here!\n");
    led_switch(1, LED_OFF);

    key_init(&key_cfg);
    while (1)
    {
        printf("hello world! count %d \n", count++);
        aos_msleep(1000);
    };
}
