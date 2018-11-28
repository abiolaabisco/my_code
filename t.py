import smtplib
s= stmtplib.SMTP('smtp.gmail.com', 587)
s.startttls()
s.ehol()
username='abiolaabisco37gmail.com'
password = '**********'
s.login(username, password)
replyto='abiolaabisco@yahoo.com'
sendto = ['firstmail' , 'secondmail']
sendtoshow= 'motion detected'
content = "hello motion"
mailText = 'from: '+replyto+'\nTo: '+sendtoshow+'\n'
mailText = mailtext+'subject: '+Subject+'\n'+content
s.sendmail(replyto, sendto, mailText)
rslt=s.quit()
print('sendmail result=' + str(rslt[1]))

import RPi.GPIO as GPIO

import time

sensor1 =16
sensor2 = 12
sensor3 = 19
sensor4 = 20
buzzer= 18
GPIO.setmode(GPIO.BOARD)
GPIO.setup(sensor1,GPIO.IN)
GPIO.setup(sensor2,GPIO.IN)
GPIO.setup(sensor3,GPIO.IN)
GPIO.setup(sensor4,GPIO.IN)
GPIO.setup(buzzer,GPIO.OUT)
     
GPIO.output(buzzer,False)
print "initializing pir sensoer...."
time.sleep(1)
print "PIR READY...."
print" "

try:
    while True:
        if GPIO.input(12) or GPIO.input(16) or GPIO.input(19)or GPIO.input(21):
            GPIO.output(buzzer, True)
            print "motion detected"
            #while GPIO.input (12) or GPIO.input(16) or GPIO.input(19)or GPIO.input(21):
            time.sleep(2)
        else:
            GPIO.output(buzzer, False)

except KeyboardInterrupt:
    GPIO.cleanup()
    
