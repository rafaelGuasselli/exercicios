salario = float(input())
imposto = 0

if salario > 4500:
    imposto += (salario - 4500) * 0.28
    salario = 4500

if salario > 3000:
    imposto += (salario - 3000) * 0.18
    salario = 3000

if salario > 2000:
    imposto += (salario - 2000) * 0.08
    salario = 2000

if imposto == 0:
    print("Isento")
else:
    print("R$ {:.2f}".format(imposto))