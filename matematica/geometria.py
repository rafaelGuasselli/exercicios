def calculateAreaFromClockWiseCoordinates(coordinates):
	area = 0
	for i in range(0, len(coordinates)):
		currentI, nextI = i, i+1 % len(coordinates)
		cy, cx = coordinates[currentI]
		ny, nx = coordinates[nextI]
		area += (cx * ny - nx * cy)
	return abs(area)/2