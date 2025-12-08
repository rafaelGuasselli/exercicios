n, k = map(int, input().split())
ingredientsRequired=list(map(int,input().split()))
ingredients=list(map(int,input().split()))


def possible(amount):
	requiredK=0
	for i in range(n):
		requiredK+=max(0, amount*ingredientsRequired[i]-ingredients[i])
	return k>=requiredK

left=0
right=int(1e18)
maximo=0
while left<=right:
	mid=left+(right-left)//2
	if possible(mid):
		maximo=max(maximo, mid)
		left=mid+1
	else:
		right=mid-1
print(maximo)