import numpy as np

p = np.pi
r = 3
v = 30

def f(h) : return (2*p*(h**2)*(((3*r)-h)/3))-30

i = 1
x = [ -1.17, -1.2 ]
E = abs(x[1]-x[0])/abs(x[1])
while i == 1 or x[i] > E :
    x.append(((x[i-1]*f(x[i]))-(x[i]*f(x[i-1])))/(f(x[i])-f(x[i-1])))
    i += 1

print(x[-1])
