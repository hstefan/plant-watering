#!/usr/bin/env python3

import serial
import time


ser = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=1)


def write_for_secs(data, secs):
    start = time.time()
    while time.time() - start < secs:
        ser.write(data)
        ser.flush()
        ser.read()
        time.sleep(0.05)


def wait_available():
    print('Waiting for MCU to become ready.')
    while True:
        ser.write(bytearray([0]))
        recv = ser.read()

        if len(recv) > 0 and recv[-1] == 0:
            print('Ready!')
            break

while True:
    wait_available()

    print('Enabling solenoid 0.')
    write_for_secs(bytearray([0b00000001]), 2.0)

    print('Enabling solenoid 0 and 1.')
    write_for_secs(bytearray([0b00000011]), 2.0)

    print('Enabling solenoid 1 and 2')
    write_for_secs(bytearray([0b00110]), 2.0)

    print('Enabling ALL solenoids!')
    write_for_secs(bytearray([0b1111]), 2.0)

    print('Sleeping!')
    time.sleep(5)
