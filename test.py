import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setup(16, GPIO.IN)
GPIO.setup(15, GPIO.IN)

GPIO.setup(18,GPIO.OUT)
#GPIO.setup(25,GPIO.OUT)

GPIO.output(18,False)
print "initialize...."
#time.sleep(1)
print "print ready"

try:
    while True:
        if GPIO.input(16) and (15):
           GPIO.output(18,True)
            #GPIO.output(25,True)
           print "motion"
           while GPIO.input(16)and (15):
                time.sleep(0.2)
        else:
            GPIO.output(18, False)
            #GPIO.output(25, False)
except KeyboardInterrupt:
    GPIO.cleanup() 

