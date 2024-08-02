from math import floor

def ex():
	qtdRefrigerantes, garrafaPorRefrigerante = map(int, input().split())
	refrigerantesGanhados = floor(qtdRefrigerantes/garrafaPorRefrigerante)
	refrigerantesRestantes = qtdRefrigerantes - refrigerantesGanhados * garrafaPorRefrigerante
	print(refrigerantesRestantes + refrigerantesGanhados)

numCasosTeste = int(input())
for i in range(0, numCasosTeste):
	ex()