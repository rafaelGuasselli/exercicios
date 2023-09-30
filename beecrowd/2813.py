qtdTestes = int(input())

tEsquerda = 0
tDireita = 0

esquerda = 0
direita = 0
for i in range(0, qtdTestes):
    entrada = input().lower().split()
    if entrada[0] == "chuva":
        direita += 1
        if esquerda == 0:
            tEsquerda += 1
        else: 
            esquerda -= 1
    
    if entrada[1] == "chuva":
        esquerda += 1
        if direita <= 0:
            tDireita += 1
        else:
            direita -= 1

print("{:n} {:n}".format(tEsquerda, tDireita))