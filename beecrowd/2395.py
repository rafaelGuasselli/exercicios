from math import floor

container = input().split()
navio = input().split()

larguraDoContainer = int(container[0])
comprimentoDoContainer = int(container[1])
alturaDoContainer = int(container[2])

larguraDoNavio = int(navio[0])
comprimentoDoNavio = int(navio[1])
alturaDoNavio = int(navio[2])

numeroMaximoDeContainersPorAltura = floor(alturaDoNavio/alturaDoContainer)
numeroMaximoDeContainersPorLargura = floor(larguraDoNavio/larguraDoContainer)
numeroMaximoDeContainersPorComprimento = floor(comprimentoDoNavio/comprimentoDoContainer)

print(numeroMaximoDeContainersPorAltura * numeroMaximoDeContainersPorComprimento * numeroMaximoDeContainersPorLargura)