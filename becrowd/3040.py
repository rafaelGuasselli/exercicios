n=int(input())
for i   in  range(n):       #A quantidade de vezes em que as linhas com as entradas correspondentes a:
    h,d,g=input().split()   #altura da arvore, seu diametro e quantidades de galhos será determinada
    h=int(h)                #pelo valor do input da variavel n
    d=int(d)
    g=int(g)
    if  h<200   or  h>300:
        print("Nao")        #A preferencia da altura da arvore dada pelo Roberto foi de: pelo menos 200cm
    else:                   #e menos que 300cm, caso contrario, nao sera aceito
        if  d<50:           
            print("Nao")    #O diametro da arvore que Roberto deseja nao pode ser menor que 50
        else:
            if  g>=150:     #A quantidade de galhos nao pode ser menor que 150, como Roberto quer
                print("Sim")
            else:
                print("Nao")
