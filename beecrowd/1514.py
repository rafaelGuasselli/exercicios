def ex(entrada):
    numParticipantes, numProblemas = map(int, entrada.split())

    participante = [0] * numParticipantes
    problemas = [0] * numProblemas

    for j in range(0, numParticipantes):
        problemasMapa = list(map(int, input().split()))
        for i in range(0, numProblemas):
            participante[j] += problemasMapa[i]
            problemas[i] += problemasMapa[i]

    ninguemResolveuTodosOsProblemas = max(participante) < numProblemas
    todosOsProblemasForamResolvidosPorPeloMenosUmaPessoa = min(problemas) > 0
    naoHaProblemaQueTodosResolveram = max(problemas) < numParticipantes
    todosResolveramAoMenosUmProblema = min(participante) > 0

    totalDeEventos = int(ninguemResolveuTodosOsProblemas) + int(todosOsProblemasForamResolvidosPorPeloMenosUmaPessoa) + int(naoHaProblemaQueTodosResolveram) + int(todosResolveramAoMenosUmProblema)
    print(totalDeEventos)

while True:
    entrada = input()
    if entrada == "0 0":
        break
    ex(entrada)