b=int(input())
t=int(input())
area=160*70                 #calculando a area do retangulo
metade=area/2   
perimetro=t+b               #calculando o trapezio
perimetro=perimetro*70
perimetro=perimetro/2
if  perimetro<metade:
    print("2")             #verifica se a area do trapezio e maior que o resto da area do retangulo 
elif    perimetro>metade:
    print("1")
else:
    print("0")
