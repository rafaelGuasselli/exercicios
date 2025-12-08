ham=input()
ingredients = list(map(int, input().split()))
price = list(map(int, input().split()))
money = int(input())
required = [0, 0, 0]

for i in ham:
	if i == "B":
		required[0]+=1
	elif i == "S":
		required[1]+= 1
	else:
		required[2]+=1


def moneyReq(qtd, i, p, r):
	req = max(0, qtd*r[0]-i[0]) * p[0]
	req += max(0, qtd*r[1]-i[1]) * p[1]
	req += max(0, qtd*r[2]-i[2]) * p[2]
	return req


left = 0
right = 1e18
maximo = 0

while left <= right:
	mid = left + (right-left)//2
	if moneyReq(mid, ingredients, price, required) <= money:
		maximo = max(maximo, mid)
		left = mid+1
	else:
		right = mid-1

print(int(maximo))
	