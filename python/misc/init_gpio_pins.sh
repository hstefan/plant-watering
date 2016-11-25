#!/bin/sh
### BEGIN INIT INFO
# Provides:           init_gpio_pins
# Required-Start:
# Required-Stop:
# Default-Start:      S
# Default-Stop:
# Short-Description: Init gpio pins as necessary.
# Description:
### END INIT INFO

gpio mode 0 out
gpio write 0 1
gpio mode 1 out
gpio write 1 1
