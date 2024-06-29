distancia, velocidade = map(int, input().split())	

minutos = 1140
qtdMinutos = distancia/velocidade * 60
minutos = (minutos + qtdMinutos) % 1440

print("{:02d}:{:02d}".format(int(minutos//60),  int(minutos%60)))