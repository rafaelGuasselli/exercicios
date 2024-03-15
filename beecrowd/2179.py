qtdLinhas = int(input())
y = int(input())
x = int(input())

qtdPercursoPercorrido = 0
qtdCelulasPercorridos = 0
caminho = ""
layer = 1

def adicionarAoCaminho(y, x):
	global caminho
	global qtdPercursoPercorrido
	global qtdCelulasPercorridos

	valor = qtdLinhas * y + x + 1
	if y >= 0 and x >= 0 and y < qtdLinhas and x < qtdLinhas:
		caminho += str(valor) + " "
		qtdPercursoPercorrido += 1
	qtdCelulasPercorridos += 1

adicionarAoCaminho(y, x)
while qtdPercursoPercorrido < qtdLinhas * qtdLinhas:
	for i in range(layer):
		if qtdPercursoPercorrido >= qtdLinhas * qtdLinhas: break
		x += 1
		adicionarAoCaminho(y, x)
	
	for i in range(layer):
		if qtdPercursoPercorrido >= qtdLinhas * qtdLinhas: break
		y += 1
		adicionarAoCaminho(y, x)

	for i in range(layer+1):
		if qtdPercursoPercorrido >= qtdLinhas * qtdLinhas: break
		x -= 1
		adicionarAoCaminho(y, x)

	for i in range(layer+1):
		if qtdPercursoPercorrido >= qtdLinhas * qtdLinhas: break
		y -= 1
		adicionarAoCaminho(y, x)
	
	layer += 2

print(caminho.strip())
print(qtdCelulasPercorridos)