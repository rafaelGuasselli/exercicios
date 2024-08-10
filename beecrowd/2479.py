qtdCriancas = int(input())
qtdComportadas = 0
nomes = []
for i in range(0, qtdCriancas):
	comportou, nome = input().split(" ")
	qtdComportadas += 1 if comportou == "+" else 0
	nomes.append(nome)
nomes.sort()
for nome in nomes:
	print(nome)
print("Se comportaram: {:n} | Nao se comportaram: {:n}".format(qtdComportadas, (qtdCriancas-qtdComportadas)))