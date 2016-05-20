from random import randint
fh=open("C:\\Users\\Abhishek\\Desktop\\raw_data.txt",'w')
m1=86600
m2= 1000000000
m3=-1000000000
n=randint(1,m1)
fh.write(str(n)+"\n")
for i in range(n):
    k=randint(m3,m2)
    fh.write(str(k)+"\n")
fh.close()