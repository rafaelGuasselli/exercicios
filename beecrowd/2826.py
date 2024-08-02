palavra1 = input()
palavra2 = input()

array = [palavra1, palavra2]
array.sort()

for i in range(0, 2):
    print(array[i])