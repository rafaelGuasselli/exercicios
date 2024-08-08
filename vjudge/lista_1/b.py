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
tempoAtual, direcaoAtual = 0, pessoas[0][1]
ultimaPessoaEsperando = [None, None]

while naoEstaVazia(pessoas) or ultimaPessoaEsperando[0] or ultimaPessoaEsperando[1]:
	aPessoaJaChegou = lambda: pessoas[0][0] <= tempoAtual
	faltaPessoasEsperando = lambda: not (ultimaPessoaEsperando[0] or ultimaPessoaEsperando[1])
	
	while naoEstaVazia(pessoas) and (aPessoaJaChegou() or faltaPessoasEsperando()):
		pulaTempo = (not aPessoaJaChegou()) and faltaPessoasEsperando()
		ultimoTempo, ultimaDirecao = ultimaPessoa = pessoas.pop(0)
		ultimaPessoaEsperando[ultimaDirecao] = ultimaPessoa
		if pulaTempo: tempoAtual = ultimoTempo
	
	vaiPraMesmaDirecao = ultimaPessoaEsperando[direcaoAtual]
	if vaiPraMesmaDirecao:
		tempo, direcao = ultimaPessoaEsperando[direcaoAtual]
		tempoAtual = tempo + TEMPO_MOVIMENTO
		ultimaPessoaEsperando[direcaoAtual] = None
	else:
		direcaoAtual = inverter(direcaoAtual)
		tempoAtual = tempoAtual + TEMPO_MOVIMENTO
		ultimaPessoaEsperando[direcaoAtual] = None
  
  
print(tempoAtual)	