def ex(entrada):
    numeroParticipantes, numeroProblemas = map(int, input().split())

    qtdDoQueResolveuMais = 0
    qtdDoQueResolveuMenos = 112387719283789
    ninguemResolveuTodos = True
    todosOsProblemasForaResolvidosPorPeloMenosUm = False
    problemas = [0] * numeroProblemas
    
    for i in range(0, numeroParticipantes):
        problemas = list(map(int, input().split()))
        soma = 0
        for j in range(0, numeroProblemas):
            soma += problemas[j]
        qtdDoQueResolveuMais = max(soma, qtdDoQueResolveuMais)
        qtdDoQueResolveuMenos = min(soma, qtdDoQueResolveuMenos)
        if soma == numeroProblemas:
            ninguemResolveuTodos = False
        
    ninguemResolveuTodos = qtdDoQueResolveuMais < numeroProblemas
    todosResolveramPeloMenosUm = qtdDoQueResolveuMais > 0


            