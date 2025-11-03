n = int(input())

words = {}
secret = input()

for i in range(n-1):
    word = input()
    id = ""
    for j in range(len(word)):
        if word[j] == secret[j]:
            id += "*"
        elif secret.find(word[j]) != -1:
            id += "!"
        else:
            id += "X"

    words[id] = (words.get(id) or 0) + 1

words["*****"] = 1
g = int(input())
for i in range(g):
    id = input()
    print(words[id])
