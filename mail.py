import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
SENSOR1 = 18
SENSOR2= 16
SENSOR3 = 26
SENSOR4 = 22

GPIO.setup(SENSOR1, GPIO.IN, GPIO.PUD_DOWN)
GPIO.setup(SENSOR2, GPIO.IN, GPIO.PUD_DOWN)
GPIO.setup(SENSOR3, GPIO.IN, GPIO.PUD_DOWN)
GPIO.setup(SENSOR4, GPIO.IN, GPIO.PUD_DOWN)
Previous_state = False
Current_state =False

while True:
    time.sleep(0.1)
    Previous_state = Current_state
    Current_state =GPIO.input((SENSOR1)and  (SENSOR2) or  (SENSOR3) and  (SENSOR4))
    if Current_state != Previous_state:
        new_state = "HIGH" if Current_state else "LOW"
        print("GPIO pin %s is %s" % (SENSOR1, new_state) and (SENSOR2, new_state)or(SENSOR3, new_state) and(SENSOR4, new_state))
        import smtplib
        server = smtplib.SMTP('smtp.gmail.com' , 578)
        server.starttls()
        server.login("abiolaabisco37@gmail.com", "*********")

        msg= 'intruder'
        server.sendmail("abiolaabisco37@gmail.com", "to_email_address", msg)
        server.quit()
        
              
              


