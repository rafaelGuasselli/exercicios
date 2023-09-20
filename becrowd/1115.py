def quadrante(x, y):
    if (x == 0 or y == 0): 
        return 
    if (x > 0  and y > 0):  
        print("primeiro")
    if (x <= 0 and y > 0):  
        print("segundo")
    if (x <= 0 and y <= 0):  
        print("terceiro")   
    if (x > 0  and y <= 0):  
        print("quarto")

while True: 
    try:
        x, y = map(int, input().split())
        quadrante(x, y)
    except(EOFError):
        break