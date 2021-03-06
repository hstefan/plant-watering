#!/usr/bin/env python3

import time
import logging
import traceback
import wiringpi as wp


RELAY0_PIN = 0  # BCM GPIO 17
RELAY1_PIN = 1  # BCM GPIO 18


def init():
    logging.basicConfig(filename='/var/log/watering.log', level=logging.INFO,
                        format='%(asctime)s %(message)s',
                        datefmt='%m/%d/%Y %I:%M:%S %p')
    logging.info('Initializing GPIO.')
    wp.wiringPiSetup()
    wp.pinMode(RELAY0_PIN, wp.OUTPUT)
    wp.pinMode(RELAY1_PIN, wp.OUTPUT)


def reset():
    logging.info('Resetting GPIO level.')
    wp.digitalWrite(RELAY0_PIN, wp.HIGH)
    wp.digitalWrite(RELAY1_PIN, wp.HIGH)


def main():
    init()
    reset()

    # enable first valve for 45.0 seconds
    logging.info('Enabling first valve.')
    wp.digitalWrite(RELAY0_PIN, wp.LOW)
    time.sleep(45.0)
    logging.info('Disabling first valve.')
    wp.digitalWrite(RELAY0_PIN, wp.HIGH)

    # enable second valve for 120.0 seconds
    logging.info('Enabling second valve.')
    wp.digitalWrite(RELAY1_PIN, wp.LOW)
    time.sleep(120.0)
    logging.info('Disabling second valve.')
    wp.digitalWrite(RELAY1_PIN, wp.HIGH)

    reset()


if __name__ == '__main__':
    try:
        main()
    except:
        logging.error(traceback.format_exc())
        reset()
