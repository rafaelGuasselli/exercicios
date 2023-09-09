THRASH_HOLD_OLHO = 40000000

aberturaDoTelescopioEmMilimetrosQuadrados = int(input())
numeroDeEstrelas = int(input())
estrelasVisiveis = 0

# O olho humano so consegue enxergar acima de 40000000 fotons
# Cada estrela emiti uma quantidade de fotons por milimetro²
# O telescopia cria uma imagem ampliada dependendo do tamanho da abertura em mm²
# Com essa imagem amplida é possível testar se o olho humano consegue enxergala

for i in range(0, numeroDeEstrelas):
    fotonsEmitidosPorMilimetroQuadrado = int(input())
    fotonsAmpliados = fotonsEmitidosPorMilimetroQuadrado * aberturaDoTelescopioEmMilimetrosQuadrados
    if (fotonsAmpliados >= THRASH_HOLD_OLHO):
        estrelasVisiveis += 1
print(estrelasVisiveis)