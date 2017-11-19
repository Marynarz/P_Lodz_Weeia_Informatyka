import pylab
print "a*x2 + b+x +c"
zakres= map(int,raw_input("Zakres x1 x2: ").split())
x= range(zakres[0],zakres[1])
a= int(raw_input("Wspolczynnik a: "))
b= int(raw_input("Wspolczynnik b: "))
c= int(raw_input("Wspolczynnik c: "))

y = []

for i in x:
    y.append((a*i*i)+(b*i)+b)

pylab.plot(x,y)
pylab.title("Wykres 2*x2 +2")
pylab.grid(True)
pylab.show()