from datetime import datetime, timedelta
qtdTestes = int(input())

for i in range(qtdTestes):
    data = input()
    passarKDias = int(input())

    data = datetime.strptime(data, "%Y-%B-%d")
    data = data + timedelta(days=passarKDias)
    print("Case {:n}: {:s}".format(i+1, data.strftime("%Y-%B-%d")))