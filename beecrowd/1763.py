
paises = {
	"brasil": "Feliz Natal!",
	"alemanha": "Frohliche Weihnachten!",
	"austria": "Frohe Weihnacht!",
	"coreia": "Chuk Sung Tan!",
	"espanha": "Feliz Navidad!",
	"grecia": "Kala Christougena!",
	"estados-unidos": "Merry Christmas!",
	"inglaterra": "Merry Christmas!",
	"australia": "Merry Christmas!",
	"portugal": "Feliz Natal!",
	"suecia": "God Jul!",
	"turquia": "Mutlu Noeller",
	"argentina": "Feliz Navidad!",
	"chile": "Feliz Navidad!",
	"mexico": "Feliz Navidad!",
	"antardida": "Merry Christmas!",
	"canada": "Merry Christmas!",
	"irlanda": "Nollaig Shona Dhuit!",
	"belgica": "Zalig Kerstfeest!",
	"italia": "Buon Natale!",
	"libia": "Buon Natale!",
	"siria": "Milad Mubarak!",
	"marrocos": "Milad Mubarak!",
	"japao": "Merii Kurisumasu!",
}

def ex(entrada):
	pais = entrada
	if pais in paises:
		print(paises[pais])
	else:
		print("--- NOT FOUND ---")

while True:
	try:
		entrada = input()
		ex(entrada)
	except EOFError:
		break
