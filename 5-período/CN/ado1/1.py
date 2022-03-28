import numpy as np

e = np.exp(1)
g = 9.8
c = 15
v = 35
t = 9

def f1(m) : return (g*m)/c
def f2(m) : return 1-e**(-(c/m)*t)
def f(m)  : return (f1(m)*f2(m))-v
def d1(m) : return g/c
def d2(m) : return (c*t*e**(-(c*t)/m))/(m**2)
def d(m)  : return (f1(m)*d2(m))+(d1(m)*f2(m))

i = 0
x = [ 1 ]
while i == 0 or np.abs(x[i]-x[i-1]) > 0.0001 :
    x.append(x[i]-(f(x[i])/d(x[i])))
    i += 1

print(x[-1])
