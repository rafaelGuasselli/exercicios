from math import radians, sin, cos, pi, degrees
def toRadians(lat):
	if lat >= 0:
		return radians(lat)
	else:
		return radians(360+lat)

def ex(entrada):
	radius, latitude, longitude = map(float, entrada.split())
	
	latitude = toRadians(latitude)
	longitude = toRadians(longitude)

	x = radius * cos(latitude) * sin(longitude)
	y = radius * sin(latitude)
	z = radius * -cos(latitude) * cos(longitude)

	x = round(x * 100)/100	
	y = round(y * 100)/100 
	z = round(z * 100)/100

	print("{:.2f} {:.2f} {:.2f}".format(x, y, z))

while True:
	try:
		entrada = input()
		ex(entrada)
	except:
		break