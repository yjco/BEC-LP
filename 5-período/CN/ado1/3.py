import numpy as np

def f(x) : return (x**3)+(12*(x**2))-(100*x)-6
def bolzano(x, y) : return f(x)*f(y) < 0

E = 0.0001
intervalos = [ [-10,8], [-2,0], [8,10] ]
raizes = [ ]

for inter in intervalos :

    if not bolzano(*inter) :
        continue

    v = E+1
    bc = f(inter[0]) < 0
    for i in range(0, int(np.ceil((np.log(inter[1]-inter[0])-np.log(E))/np.log(2)))) :

        m = (inter[0]+inter[1])/2
        v = f(m)

        if bc :
            inter[0 if v < 0 else 1] = m
        else :
            inter[0 if v > 0 else 1] = m

    raizes.append(m)

for r in raizes : print(r)
