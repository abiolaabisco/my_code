import RPi.GPIO as GPIO
import time


GPIO.setmode(GPIO.BOARD)
GPIO.setup(11, GPIO.IN)
GPIO.setup(4, GPIO.OUT)
#GPIO.setup(26, GPIO.OUT)

GPIO.output(4,False)
GPIO.output(26,False)
print "initializing PIR sensor....."
time.sleep(5)
print "PIR ready"
 

try:
    while True:
        i= GPIO.input(11)
        if i ==0:
            print "no intruder", i
            GPIO.output(4, 0)
            time.sleep(0.1)
        else i ==1:
            print "intruder" ,i
            GPIO.output(3,1)
            time.sleep(0.1)

