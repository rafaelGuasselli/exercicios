senhaValida = False
while not senhaValida:
    senha = input()
    if senha != "2002":
        print("Senha Invalida")
    else:
        senhaValida = True
print("Acesso Permitido")