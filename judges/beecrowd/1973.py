import io, os, sys
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

def main():
	qtdEstrelas = int(input())
	qtdCarneiros = list(map(int, input().split()))

	estrelaAtual = 0
	estrelasAfetadas = [False] * qtdEstrelas
	qtdEstrelasAfetadas = 0
	carneirosNaoRoubados = sum(qtdCarneiros)

	while estrelaAtual >= 0 and estrelaAtual < qtdEstrelas:
		carneiros = qtdCarneiros[estrelaAtual]
		if carneiros > 0:	
			carneirosNaoRoubados -= 1
			qtdCarneiros[estrelaAtual] -= 1

			if not estrelasAfetadas[estrelaAtual]:
				estrelasAfetadas[estrelaAtual] = True
				qtdEstrelasAfetadas += 1

		if carneiros % 2 == 0:
			estrelaAtual -= 1
		else:
			estrelaAtual += 1

	sys.stdout.write(str(qtdEstrelasAfetadas) + " " + str(carneirosNaoRoubados) + "\n")
	
if __name__ == "__main__":
	main()