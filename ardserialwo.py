import serial
import commands
import time

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=5)

ser.flush()

while True:

    ser.flush()

    mycmd=commands.getoutput("sensors | grep -A 0 'Physical id 0' | cut -c18-19")
    ser.write(mycmd)
    ser.write('!')

    gpucmd=commands.getoutput("nvidia-settings -q gpucoretemp | grep -m 1 -A 0 'Attribute' | cut -c 42-43")
    ser.write(gpucmd)
    ser.write('@')

    ramcmd=commands.getoutput("free -m -t -h | grep Mem | cut -c 28-31")
    ser.write(ramcmd)
    ser.write('#')
    
    timecmd=commands.getoutput("date '+%X'")
    ser.write(timecmd)
    ser.write('$')

    datecmd=commands.getoutput("date +'%a %m-%d'")
    ser.write(datecmd)
    ser.write('%')

    

    ser.write('\n')

    time.sleep(1)

    ser.flush()

####Tried but failed below #######################
    #pwrcmd=commands.getoutput("pwrstat -status | grep -i Load | cut -c 33-46")
    #ser.write(pwrcmd)
    #ser.write('$')