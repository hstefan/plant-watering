#!/usr/bin/env python3

import wiringpi as wp

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

    while True:
        # activates first relay
        wp.digitalWrite(RELAY0_PIN, wp.LOW)
        wp.delay(1000)

        # deativates first relay
        wp.digitalWrite(RELAY0_PIN, wp.HIGH)
        wp.delay(1000)

        # activates second relay
        wp.digitalWrite(RELAY1_PIN, wp.LOW)
        wp.delay(1000)

        # deactivates second relay
        wp.digitalWrite(RELAY1_PIN, wp.HIGH)
        wp.delay(1000)

        # activates both relays
        wp.digitalWrite(RELAY0_PIN, wp.LOW)
        wp.digitalWrite(RELAY1_PIN, wp.LOW)
        wp.delay(1000)

        reset()


if __name__ == '__main__':
    main()
