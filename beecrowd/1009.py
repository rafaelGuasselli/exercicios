nome = input()
salarioBase = float(input())
totalDeVendas = float(input())
salarioTotal = salarioBase + (totalDeVendas * 0.15)

print("TOTAL = R$ {:.2f}".format(salarioTotal))