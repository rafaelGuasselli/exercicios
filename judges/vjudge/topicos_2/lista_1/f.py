def toFahrenheit(celsius):
    return 9/5*celsius+32

def toCelsius(fahrenheit):
    return (fahrenheit-32)*5/9



qtdTestes = int(input())
for i in range(qtdTestes):
    celsius, aumento = map(int, input().split())
    fahrenheit = toFahrenheit(celsius) + aumento
    celsius = toCelsius(fahrenheit)
    print("Case {:n}: {:.2f}".format(i+1, celsius))
