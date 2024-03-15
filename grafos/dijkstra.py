import sys


class Graph():
	def __init__(self, vertices):
		self.qtdVertices = vertices
		self.graph = [[0 for column in range(vertices)]
					for row in range(vertices)]

	def printSolution(self, dist):
		print("Vertex \tDistance from Source")
		for node in range(self.qtdVertices):
			print(node, "\t", dist[node])

	def getIndexOfVerticeWithMinDistance(self, distancias, sptSet):
		min = sys.maxsize

		for vertice in range(self.qtdVertices):
			if distancias[vertice] < min and sptSet[vertice] == False:
				min = distancias[vertice]
				min_index = vertice

		return min_index

	def dijkstra(self, src):
		distanciaDaOrigem = [sys.maxsize] * self.qtdVertices
		distanciaDaOrigem[src] = 0
		sptSet = [False] * self.qtdVertices

		for _ in range(0, self.qtdVertices):
			minDistVert = self.getIndexOfVerticeWithMinDistance(distanciaDaOrigem, sptSet)
			sptSet[minDistVert] = True

			for vertice in range(self.qtdVertices):
				distanciaAteOVerticePeloVerticeMinimo = distanciaDaOrigem[minDistVert] + self.graph[minDistVert][vertice]
				naoVisitado = sptSet[vertice] == False
				if naoVisitado and distanciaAteOVerticePeloVerticeMinimo < distanciaDaOrigem[vertice]:
					distanciaDaOrigem[vertice] = distanciaAteOVerticePeloVerticeMinimo
		self.printSolution(distanciaDaOrigem)


# Driver's code
if __name__ == "__main__":
	I = float("inf")
	g = Graph(6)
	g.graph =[
		[0, 1, 5, I, I, I],
		[1, 0, 3, 9, 2, I],
		[5, 3, 0, I, 2, I],
		[I, 9, I, 0, I, 2],
		[I, 2, 2, I, 0, 2],
		[I, I, I, 2, 2, 0],
	]

	g.dijkstra(0)