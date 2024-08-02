UMA_HORA_EM_ANGULO = 30
UM_MINUTO_EM_ANGULO = 6

def ex3084(entrada):
    horasEmAngulo, minutosEmAngulo = map(int, entrada.split())
    horas = int(horasEmAngulo/UMA_HORA_EM_ANGULO)
    minutos = int(minutosEmAngulo/UM_MINUTO_EM_ANGULO)
    print("{:02d}:{:02d}".format(horas, minutos))
    

while True:
    try:
        entrada = input()
        ex3084(entrada)
    except EOFError:
        break