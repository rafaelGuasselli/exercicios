valoresPrimeiraCharrete = list(map(lambda a: int(a), input().split()))
valoresSegundaCharrete = list(map(lambda a: int(a), input().split()))

codigoPrimeiraCharrete = valoresPrimeiraCharrete[0]
codigoSegundaCharrete = valoresSegundaCharrete[0]

distanciaQueFaltaPrimeiraCharrete = valoresPrimeiraCharrete[1]
distanciaQueFaltaSegundaCharrete = valoresSegundaCharrete[1]

velocidadeDaPrimeiraCharreteEmMetrosPorSegundo = valoresPrimeiraCharrete[2]/3.6
velocidadeDaSegundaCharreteEmMetrosPorSegundo = valoresSegundaCharrete[2]/3.6

tempoQueFaltaPraPrimeiraCharrete = distanciaQueFaltaPrimeiraCharrete/velocidadeDaPrimeiraCharreteEmMetrosPorSegundo
tempoQueFaltaPraSegundaCharrete = distanciaQueFaltaSegundaCharrete/velocidadeDaSegundaCharreteEmMetrosPorSegundo

if tempoQueFaltaPraPrimeiraCharrete < tempoQueFaltaPraSegundaCharrete:
    print(codigoPrimeiraCharrete)
else:
    print(codigoSegundaCharrete)