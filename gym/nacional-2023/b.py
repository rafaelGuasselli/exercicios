n = int(input())
a = list(map(int, input().split()))

freq = {}
for i in a:
    freq[i] = (freq.get(i) or 0)+1

if all(freq[x]%3==0 for x in freq):
    print("N")
else:
    print("Y")