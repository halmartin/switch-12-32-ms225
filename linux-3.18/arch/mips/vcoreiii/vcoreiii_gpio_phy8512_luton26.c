/*
 *
 * VCore-III GPIO on the 8512 PHY, Luton26 glue
 *
 * Copyright (c) 2011 Meraki, Inc.
 * Author: Kevin Paul Herbert (kph@meraki.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 * This is the LUTON26 glue for the GPIO driver for the GPIO bits on
 * the 8512 PHY.
 */

#define SUPPORT_VTSS_VCOREIII_LUTON26

#include "vcoreiii_miim_phy8512.h"
#include "vcoreiii_gpio_phy8512.h"

int luton26_phy8512_gpio_get_value(struct gpio_chip *chip, unsigned gpio)
{
	return phy8512_gpio_get_value(chip, gpio);
}

void luton26_phy8512_gpio_set_value(struct gpio_chip *chip, unsigned gpio,
				    int value)
{
	phy8512_gpio_set_value(chip, gpio, value);
}

int luton26_phy8512_gpio_direction_input(struct gpio_chip *chip, unsigned gpio)
{
	return phy8512_gpio_direction_input(chip, gpio);
}

int luton26_phy8512_gpio_direction_output(struct gpio_chip *chip, unsigned gpio,
					  int value)
{
	return phy8512_gpio_direction_output(chip, gpio, value);
}

int luton26_phy8512_gpio_to_irq(struct gpio_chip *chip, unsigned gpio)
{
	return phy8512_gpio_to_irq(chip, gpio);
}

MODULE_AUTHOR("Kevin Paul Herbert <kph@meraki.com>");
MODULE_DESCRIPTION("GPIO driver for 8512 PHY on Luton26");
MODULE_LICENSE("GPL");
