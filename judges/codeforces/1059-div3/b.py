def isPalindrome(s):
	for i in range(0, len(s)/2):
		if s[i] != s[-i-1]:
			return False
	return False

t=int(input())
while t:
	t-=1
	n=int(input())
	a=input()
	