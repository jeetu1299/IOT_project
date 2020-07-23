from datetime import *
import time

now = datetime.now()
print("now =", now)
dt_string = now.strftime("%S")
print("date and time =", dt_string)

time.sleep(10)

now2 = datetime.now()
print("now =", now2)
dt_string2 = now2.strftime("%S")
print("date and time =", dt_string2)

t1 = int(dt_string)
t2 = int(dt_string2)

print("Different bet seconds : ",t2-t1)
