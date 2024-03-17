def inverter(direcao):
	return (direcao + 1) % 2

qtdPessoas = int(input())
pessoas = []

for i in range(qtdPessoas):
	tempo, direcao = map(int, input().split())
	pessoas.append((tempo, direcao))

pessoas.sort()

TEMPO_MOVIMENTO = 10
tempoAtual, direcaoAtual = pessoas[0]
pessoasEsperando = [[], []]

while len(pessoas + pessoasEsperando[0] + pessoasEsperando[1]) > 0:
	aindaTemPessoas = lambda: len(pessoas) > 0
	aPessoaJaChegou = lambda: pessoas[0][0] <= tempoAtual
	faltaPessoasEsperando = lambda: len(pessoasEsperando[0] + pessoasEsperando[1]) == 0
	
	while aindaTemPessoas() and (aPessoaJaChegou() or faltaPessoasEsperando()):
		pulaTempo = not aPessoaJaChegou() and faltaPessoasEsperando()
		proximoTempo, proximaDirecao = proximaPessoa = pessoas.pop(0)
		pessoasEsperando[proximaDirecao].append(proximaPessoa)
		if pulaTempo: tempoAtual = proximoTempo
	
	vaiPraMesmaDirecao = not len(pessoasEsperando[direcaoAtual]) == 0
	if vaiPraMesmaDirecao:
		tempo, direcao = pessoasEsperando[direcaoAtual].pop(0)
		tempoAtual = tempo + TEMPO_MOVIMENTO
	else:
		direcaoAtual = inverter(direcaoAtual)
		tempo, direcao = pessoasEsperando[direcaoAtual].pop(0)
		tempoAtual = tempoAtual + TEMPO_MOVIMENTO
		pessoasEsperando[direcaoAtual] = []
  
print(tempoAtual)	