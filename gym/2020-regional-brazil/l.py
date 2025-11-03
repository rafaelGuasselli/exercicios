n = int(input())
criancas = input().split()
ordem = input().split()
irritantes = ""
first = True
for e in range(n):
    if first:
        irritantes += ordem[0]
        first = False
    else:
        irritantes+= ""+ordem[0]
    ordem.remove(criancas[0])
    criancas.remove(criancas[0])
    
print(irritantes)