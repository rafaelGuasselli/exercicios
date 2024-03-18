def inverter(direcao):
	return (direcao + 1) % 2

def naoEstaVazia(lista):
    return len(lista) > 0

qtdPessoas = int(input())
pessoas = []

for i in range(qtdPessoas):
	tempo, direcao = map(int, input().split())
	pessoas.append((tempo, direcao))

pessoas.sort()

TEMPO_MOVIMENTO = 10
tempoAtual, direcaoAtual = pessoas[0]
pessoasEsperando = [[], []]

while naoEstaVazia(pessoas + pessoasEsperando[0] + pessoasEsperando[1]):
	aPessoaJaChegou = lambda: pessoas[0][0] <= tempoAtual
	faltaPessoasEsperando = lambda: len(pessoasEsperando[0] + pessoasEsperando[1]) == 0
	
	while naoEstaVazia(pessoas) and (aPessoaJaChegou() or faltaPessoasEsperando()):
		pulaTempo = not aPessoaJaChegou() and faltaPessoasEsperando()
		proximoTempo, proximaDirecao = proximaPessoa = pessoas.pop(0)
		pessoasEsperando[proximaDirecao].append(proximaPessoa)
		if pulaTempo: tempoAtual = proximoTempo
	
	vaiPraMesmaDirecao = naoEstaVazia(pessoasEsperando[direcaoAtual])
	if vaiPraMesmaDirecao:
		tempo, direcao = pessoasEsperando[direcaoAtual][-1]
		tempoAtual = tempo + TEMPO_MOVIMENTO
		pessoasEsperando[direcaoAtual] = []
	else:
		direcaoAtual = inverter(direcaoAtual)
		tempoAtual = tempoAtual + TEMPO_MOVIMENTO
		pessoasEsperando[direcaoAtual] = []
  
print(tempoAtual)	