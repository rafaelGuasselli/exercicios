KM_POR_LITRO = 12

tempoViagem = int(input())
velocidadeMedia = int(input())
kmTotais = tempoViagem * velocidadeMedia

print("{:.3f}".format(kmTotais / KM_POR_LITRO))