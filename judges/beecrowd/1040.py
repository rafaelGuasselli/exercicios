
PESOA = 2
PESOB = 3
PESOC = 4
PESOD = 1


a, b, c, d = map(lambda a: float(a), input().split())

media = (PESOA * a + PESOB * b + PESOC * c + PESOD * d) / (PESOA + PESOB + PESOC + PESOD)
print("Media: {:.1f}".format(media))

if media < 5:
    print("Aluno reprovado.")
elif media < 7:
    print("Aluno em exame.")
    e = float(input())

    print("Nota do exame: {:.1f}".format(e))
    media = (media + e) / 2
    if media < 5:
        print("Aluno reprovado.")
    else: 
        print("Aluno aprovado.")

    print("Media final: {:.1f}".format(media))
else:
    print("Aluno aprovado.")
