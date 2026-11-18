import time
import math
import os
from playsound import playsound


def timer(t):
    start = time.time()
    end = start + t
    for i in range(t*1):
        h = math.floor((t-i)/3600)
        m = math.floor((((t-(h*3600)-i)/60)))
        s = math.floor((t-m*60-h*3600)-i)
        os.system("cls")
        print("To pause timer click anywhere on the terminal")
        print("start time: ", time.ctime(start))
        print("end time:   ", time.ctime(end))
        print(h, " hours left, ", m, " minutes left, ", s, " seconds left")
        time.sleep(1)
        i-=1
    if p is True:
        for i in range(50):
            playsound("C:\\Windows\\Media\\Windows Unlock.wav")
    else:
        os.system("cls")
        print("\t\tEND!\nPress Ctrl+C to proceed")
        while True:
            try:
                playsound("C:\\Windows\\Media\\Windows Unlock.wav")
            except:
                break


def normal():
    H = int(input("Number of hours:   "))
    M = int(input("Number of minutes: "))
    S = int(input("Number of seconds: "))
    t = ((H*3600) + (M*60) + S)
    if t <= 0:
        print("error: time not valid!")
        exit()
    timer(t)


def pomo(P=4):
    for i in range(P):
        print("Pomodoro number ", i+1, "\nStart work now for 25 minutes!")
        t = int(25*60)
        timer(t)
        print("Break number ", i+1, "\nYou can rest now for 5 minutes :-)")
        t = int(5*60)
        timer(t)


p = 0
if input("For normal timer press enter\nFor pomodoro type pomo\n") == "pomo":
    pomo()
    p = 1
else:
    normal()
print("Program terminating...")

