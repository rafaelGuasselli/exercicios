dia1 = int(input().split("Dia ")[1])
horas1, minutos1, segundos1 = map(int, input().split(" : "))

dia2 = int(input().split("Dia ")[1])
horas2, minutos2, segundos2 = map(int, input().split(" : "))

momento1EmSegundos = horas1 * 3600 + minutos1 * 60 + segundos1
momento2EmSegundos = horas2 * 3600 + minutos2 * 60 + segundos2 + ((dia2 - dia1) * 86400)

diferenca = max(momento2EmSegundos - momento1EmSegundos, 60)
diferencaDias = diferenca // 86400
diferenca -= diferencaDias * 86400

diferencaEmHoras = diferenca // 3600
diferenca -= diferencaEmHoras * 3600

diferencaEmMinutos = diferenca // 60
diferenca -= diferencaEmMinutos * 60

diferencaEmSegundos = diferenca

print("{:n} dia(s)".format(diferencaDias))
print("{:n} hora(s)".format(diferencaEmHoras))
print("{:n} minuto(s)".format(diferencaEmMinutos))
print("{:n} segundo(s)".format(diferencaEmSegundos))
