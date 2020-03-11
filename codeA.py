import serial
import time
from matplotlib import pyplot as plt
from matplotlib import style

ser=serial.Serial('COM6',9600,5)

while(1):
    x1=ser.readline().decode().split('\r\n')
    x2=ser.readline().decode().split('\r\n')
    y1=ser.readline().decode().split('\r\n')
    y2=ser.readline().decode().split('\r\n')
    plt.plot([x1,x2],[y1,y2])
