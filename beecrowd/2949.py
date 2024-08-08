frequencias = {
	"A": 0,
    "E": 0,
    "H": 0,
    "M": 0,
    "X": 0,
}

qtd = int(input())
for i in range(0, qtd):
    nome, raca = input().split()
    frequencias[raca] += 1

print("{:n} Hobbit(s)".format(frequencias["X"]))
print("{:n} Humano(s)".format(frequencias["H"]))
print("{:n} Elfo(s)".format(frequencias["E"]))
print("{:n} Anao(oes)".format(frequencias["A"]))
print("{:n} Mago(s)".format(frequencias["M"]))