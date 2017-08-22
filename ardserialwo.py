#Required modules

import serial
import commands
import time

#Select your appropriate serial port
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=5)
ser.flush()

while True:

    ser.flush()

    #Run commands in shell and grep for the interesting content (Customize to your needs)
    #Get CPU temp in my case i7 6700k you have to find where tu cut the string on your own output
    mycmd=commands.getoutput("sensors | grep -A 0 'Physical id 0' | cut -c18-19")
    ser.write(mycmd)
    ser.write('!')
    
    #Get temperature of Nvidia card GTX 1080
    gpucmd=commands.getoutput("nvidia-settings -q gpucoretemp | grep -m 1 -A 0 'Attribute' | cut -c 42-43")
    ser.write(gpucmd)
    ser.write('@')
    
    #Get amount of free ram
    ramcmd=commands.getoutput("free -m -t -h | grep Mem | cut -c 28-31")
    ser.write(ramcmd)
    ser.write('#')
    
    #Get the time of the day
    timecmd=commands.getoutput("date '+%X'")
    ser.write(timecmd)
    ser.write('$')

    #Get the date
    datecmd=commands.getoutput("date +'%a %m-%d'")
    ser.write(datecmd)
    ser.write('%')

    
    ser.write('\n')

    time.sleep(1)

    ser.flush()

    #Tried but failed below ####################### This works with my UPS for 5 minutes only#
    #pwrcmd=commands.getoutput("pwrstat -status | grep -i Load | cut -c 33-46")
    #ser.write(pwrcmd)
    #ser.write('$')
