# PRU-programming-for-Pulse-Count-and-PulseWidth
resistors 4.7k is  pulled down and signal is connected to P9.30

./xreadDistance 1
IT WILL START COUNTING FOR TON TIME.
WHEN 0V BY TOGGLE SWITCH :


New =0x34
Value at address 0x4A300008 is: 0x3776EDB3

WHEN 3.3V BY TOGGLE SWITCH:
New =0x35
Value at address 0x4A300008 is: 0x28B7
##############################how to load firmware?:
#!/bin/bash
echo 'stop' > /sys/class/remoteproc/remoteproc2/state
config-pin P9_28 pruin
config-pin P8_27 pruin
sleep 0.1
sudo cp /home/debian/ft.out /lib/firmware/ft
sleep 1
echo 'ft' > /sys/class/remoteproc/remoteproc2/firmware
sleep 1
echo 'start' > /sys/class/remoteproc/remoteproc1/state
