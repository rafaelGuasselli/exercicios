ax1, ay1 = map(int, input().split())
ax2, ay2 = map(int, input().split())
ax3, ay3 = map(int, input().split())
ax4, ay4 = map(int, input().split())

bx1, by1 = map(int, input().split())
bx2, by2 = map(int, input().split())
bx3, by3 = map(int, input().split())
bx4, by4 = map(int, input().split())

#Calcula o dobro da area com a equação de coordenada pra area de algebra linear
#Ref:
#https://www.themathdoctors.org/polygon-coordinates-and-areas/
doubleAreaA = abs((ax1 * ay2 - ax2 * ay1) + (ax2 * ay3 - ax3 * ay2) + (ax3 * ay4 - ax4 * ay3) + (ax4 * ay1 - ax1 * ay4))
doubleAreaB = abs((bx1 * by2 - bx2 * by1) + (bx2 * by3 - bx3 * by2) + (bx3 * by4 - bx4 * by3) + (bx4 * by1 - bx1 * by4))

#O porquê que o beecrowd passou tendo que checar a < b, eu não fasso a menor ideia...
#Deveria ser maior que...
if doubleAreaA > doubleAreaB:
	print("terreno A")
else:
	print("terreno B")