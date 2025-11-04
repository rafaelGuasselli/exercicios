valToChar=["a", "b", "c", "d", "e", "f", "g", "h", "i", "j"]
def encodeNumber(n):
	s=list("aaaaaaaaaa")
	ind=0
	while n > 0:
		val=n%10
		s[ind] = valToChar[val]
		n//=10
		ind+=1
	return "".join(s)

def decodeString(s):
    num=0
    for i in range(10):
        num+=pow(10, i) * (ord(s[i])-ord("a"))
    return num


s=input()
if s == "first":
    n = int(input())
    a = list(map(int, input().split()))
    r = ""
    for i in a:
        r+=encodeNumber(i)
    
    print(r)
else:
    a = input()
    lista=[]
    for i in range(len(a)//10):
        lista.append(decodeString(a[i*10:(i+1)*10]))
    print(len(lista))
    print(*lista)