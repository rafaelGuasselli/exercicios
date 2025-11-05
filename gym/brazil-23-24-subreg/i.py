n=int(input())
a=list(map(int, input().split()))
dp=[0, 0]
count=0

for i in a:
	if i == 1:
		dp[0], dp[1] = dp[1], dp[0]+1
	else:
		dp[0] += 1
	count+=dp[1]
print(count)
	