from socket import *

s = socket()

s.connect(('192.168.40.129', 12245))

s.send(b'Hello')
q = s.recv(1024)
q.decode()
print(q)
s.close()
