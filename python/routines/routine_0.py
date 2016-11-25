#!/usr/bin/env python3

import wiringpi as wp
import time


RELAY0_PIN = 0  # BCM GPIO 17
RELAY1_PIN = 1  # BCM GPIO 18


def init():
    wp.wiringPiSetup()
    wp.pinMode(RELAY0_PIN, wp.OUTPUT)
    wp.pinMode(RELAY1_PIN, wp.OUTPUT)


def reset():
    wp.digitalWrite(RELAY0_PIN, wp.HIGH)
    wp.digitalWrite(RELAY1_PIN, wp.HIGH)


def main():
    init()
    reset()

    # enable first valve for 45.0 seconds
    wp.digitalWrite(RELAY0_PIN, wp.LOW)
    time.sleep(45.0)
    wp.digitalWrite(RELAY0_PIN, wp.HIGH)

    # enable second valve for 120.0 seconds
    wp.digitalWrite(RELAY1_PIN, wp.LOW)
    time.sleep(120.0)
    wp.digitalWrite(RELAY1_PIN, wp.HIGH)

    reset()


if __name__ == '__main__':
    try:
        main()
    except:
        print('Exception caught, quitting.')
        reset()
