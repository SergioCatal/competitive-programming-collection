time = input()
w = time[-2:]
time = time[:-2]
time = time.split(':')
if time[0]=="12" and w == "AM":
    time[0] = "00"
elif time[0]!="12" and w == "PM":
    time[0] = str(int(time[0])+12)
time = ':'.join(time)
print(time)
