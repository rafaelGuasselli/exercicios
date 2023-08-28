cod, qtd = input().split()
cod = int(cod)
qtd = int(qtd)
cases = [ 4.00, 4.50, 5.00, 2.00, 1.50 ]
print("Total: R$ {:.2f}".format(qtd * cases[cod - 1]))