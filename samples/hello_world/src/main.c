/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/charger.h>

#define MP2733 	DT_NODELABEL(charger)

static const struct device *const dev = DEVICE_DT_GET(MP2733);

int main(void)
{
	const struct charger_driver_api * api = (const struct charger_driver_api *)dev->api;
	union charger_propval val;
	printk("%d\n", api->get_property(dev, CHARGER_PROP_PRESENT, &val));
	printk("set : %d\n",api->set_property(dev, CHARGER_PROP_PRESENT, &val));
	printk("Charge enable %d\n", api->charge_enable(dev, 0));
	printk("Hello world\n");
	return 0;
}
