import serial
import time
from matplotlib import pyplot as plt
from matplotlib import style

style.use('ggplot')
dataList = [0]*3
ser=serial.Serial('COM6',9600,6)
x=0
y=0
dir=0
n=0

def getval():
    ad=ser.readline().decode().split('\r\n')
    return ad

def plott(f,l,r):
    if(dir==0):
        if(n==1):
            n=0
        else:
            z=y+15
            if(l<30):
                plt.plt([x-l,x-l],[y,z])
            if(r<30):
                plt.plot([x+r,x+r],[y,z])
            if(f<30):
                plt.plot([x-l,x+r],[z,z])
            y=z
    if(dir==1):
        if(n==1):
            n=0
        else:
            z=x-15
            if(l<30):
                plt.plt([z,x],[y-l,y-l])
            if(r<30):
                plt.plot([z,x],[y+r,y+r])
            if(f<30):
                plt.plot([x-f,x-f],[y-l,y+r])
            x=z
    if(dir==2):
        if(n==1):
            n=0
        else:
            z=y-15
            if(l<30):
                plt.plt([x+l,x+l],[y,z])
            if(r<30):
                plt.plot([x-r,x-r],[y,z])
            if(f<30):
                plt.plot([x+l,x-r],[z,z])
            y=z
    if(dir==3):
        if(n==1):
            n=0
        else:
            z=x+15
            if(l<30):
                plt.plt([z,x],[y+l,y+l])
            if(r<30):
                plt.plot([z,x],[y-r,y-r])
            if(f<30):
                plt.plot([x+f,x+f],[y+l,y-r])
            x=z









def des(f,l,r):
    if(l>15):
        dir=dir+1
        n=1
        return 2

    elif(f>15):
        return 1

    else:
        dir=dir-1
        n=1
        return 3




while(1):

    for i in range(0,3):
        data=getval()
        dataList[i] = data

    f=dataList[0]
    l=dataList[1]
    r=dataList[2]

    plott(f,l,r)
    num=des(f,l,r)
    ser.write(num)


