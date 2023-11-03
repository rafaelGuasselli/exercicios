from math import ceil
qtdAlunos, litrosPorVez, mlPorAluno = map(int, input().split())
mlPorVez = litrosPorVez * 1000
mlPorSala = mlPorAluno * qtdAlunos

print(litrosPorVez * ceil(mlPorSala/mlPorVez))
