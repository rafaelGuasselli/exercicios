from math import floor

segundos = int(input())
horas = floor(segundos/3600)
minutos = floor((segundos%3600)/60)
segundos = segundos % 60

print("{:n}:{:n}:{:n}".format(horas, minutos, segundos))