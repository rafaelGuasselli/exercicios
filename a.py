def f(x):
    return (x**4)-(3*x**3)+(x**2)+x+1

def q0(x):
    return (f(x[0])-f(x[2]))/(x[0]-x[2])

def q1(x):
    return ((f(x[1])-f(x[2]))/(x[1]-x[2]))

def ax(x):
    return (q0(x)-q1(x))/(x[0] - x[1])

def bx(x):
    return (q0(x)*(x[2]-x[1]) + q1(x)*(x[0]-x[2]))/(x[0] - x[1])

def cx(x):
    return f(x[2])

def sgn(x):
    return 1 if x>0 else -1

def muller(x):
    a = ax(x)	
    b = bx(x)
    c = cx(x)

    res = x[2] - ((2*c/(b + (sgn(b)*(b**2 - 4*a*c)))))
    return res

def main(x):
    x0=x[0]
    x1=x[1]
    x2=x[2]
    it = 1
    itm = 1e5
    tol = 0.0001
    res = 1
    while (abs(res)>tol and it < itm):
        res = muller(x)
        x0=x1
        x1=x2
        x2=res
        x=[x0,x1,x2]
        it+=1
        print(it, ':', res)

main([-0.5, 0, 0.5])