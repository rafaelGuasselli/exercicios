valores = list(map(lambda a: int(a), input().split()))

numeroDeVitoriasDoCormengo = valores[0]
numeroDeEmpatesDoCormengo = valores[1]
saldoDeGolsDoCormengo = valores[2]
pontosDoCormengo = numeroDeEmpatesDoCormengo + (numeroDeVitoriasDoCormengo * 3)

numeroDeVitoriasdDoFlaminthians = valores[3]
numeroDeEmpatesDoFlaminthians = valores[4]
saldoDeGolsDoFlaminthians = valores[5]
pontosDoFlaminthians = numeroDeEmpatesDoFlaminthians + (numeroDeVitoriasdDoFlaminthians * 3)

if pontosDoCormengo > pontosDoFlaminthians:
    print("C")
elif pontosDoCormengo < pontosDoFlaminthians:
    print("F")
else:
    if saldoDeGolsDoCormengo > saldoDeGolsDoFlaminthians:
        print("C")
    elif saldoDeGolsDoCormengo < saldoDeGolsDoFlaminthians:
        print("F")
    else:
        print("=")