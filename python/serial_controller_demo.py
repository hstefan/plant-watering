#!/usr/bin/env python3

import serial
import time


ser = serial.Serial('/dev/ttyACM0', 9600)

def write_for_secs(data, secs):
    start = time.time()
    while time.time() - start < secs:
        ser.write(data)
        ser.flush()
        ser.read(1)


while True:
    print('Enabling solenoid 0.')
    write_for_secs(bytearray([0b00011111]), 2.0)

    print('Enabling solenoid 0 and 1.')
    write_for_secs(bytearray([0b00111111]), 2.0)

    print('Enabling solenoid 1 and 2')
    write_for_secs(bytearray([0b01101111]), 2.0)

    print('Enabling ALL solenoids!')
    write_for_secs(bytearray([0b11111111]), 2.0)

    print('Sleeping!')
    time.sleep(5)
