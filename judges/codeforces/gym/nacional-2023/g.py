def intersect(retaA, retaB):
	typeA, a, b, lxa, rxa = retaA
	typeB, c, d, lxb, rxb = retaB

	lxc, rxc = max(lxa, lxb), min(rxa, rxb)
	if lxc > rxc:
		return None
	
	if typeA == typeB == "reta":
		if a != c and b != d:
			x = (d-b)//(a-c)
			y = x * a + b
			if x >= lxc and x <= rxc:
				return ("ponto", x, y, x, x)
		elif a == c and b == d:
			return ("reta", a, b, lxc, rxc)
	elif typeA == typeB == "ponto" and a == c and b == d:
		return retaA
	elif typeA == "ponto" and typeB == "reta" and a*c+d == b:
		return ("ponto", a, b, a, a) 
	elif typeA == "reta" and typeB == "ponto" and c*a+b == d:
		return ("ponto", c, d, c, c) 
	return None

def construirRetas(a, b, c):
	retas = []
	retas.append(("reta",  1, b + c - a, a - c,		a))
	retas.append(("reta", -1, a + b + c, 	a,	a + c))
	retas.append(("reta",  1, b - a - c, 	a,	a + c))
	retas.append(("reta", -1, a + b - c, a - c, 	a))
	return retas

def construirPontos(reta):
	typeA, a, b, lxa, rxa = reta
	if typeA == "ponto":
		return [(a, b)]
	elif typeA == "reta":
		pontos = []
		for x in range(lxa, rxa+1):
			y = x * a + b
			pontos.append((x, y))
		return pontos
	else:
		return []
	

n = int(input())
a, b, c = map(int, input().split())
retas = construirRetas(a, b, c)
for i in range(n-1):
	a, b, c = map(int, input().split())
	novasRetas = construirRetas(a, b, c)
	interRetas = []

	for i in retas:
		for j in novasRetas:
			inter = intersect(i, j)
			if inter:
				interRetas.append(inter)
	retas = interRetas

pontos = []
for r in retas:
	pontos.extend(construirPontos(r))
pontos = sorted(set(pontos))
for p in pontos:
	x, y = p
	print(x, y)