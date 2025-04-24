n=int(input())
valor_total=0
if  n>=101:             #Pega o excedente de 101 e o valor de n
    n=n-100             #e calcula com a taxa do excedente
    valor_total+=n*5    
    n=100
if  n>=31:
    n=n-30
    valor_total+=n*2
    n=30
if  n>=11:
    n=n-10
    valor_total+=n*1
    n=10
if  n<=10:
    print(valor_total+7)#inclui o valor da franquia

