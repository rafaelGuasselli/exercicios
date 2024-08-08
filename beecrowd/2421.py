alturaDoQuadro, larguraDoQuadro = map(int, input().split())
alturaDaFoto1, larguraDaFoto1 = map(int, input().split())
alturaDaFoto2, larguraDaFoto2 = map(int, input().split())

cabeNaLargura = (larguraDaFoto1 + larguraDaFoto2) <= larguraDoQuadro and max(alturaDaFoto1, alturaDaFoto2) <= alturaDoQuadro
cabeNaAltura = (alturaDaFoto1 + alturaDaFoto2) <= alturaDoQuadro and max(larguraDaFoto1, larguraDaFoto2) <= larguraDoQuadro

cabeNaDiagonal1 = (alturaDaFoto1 + larguraDaFoto2) <= alturaDoQuadro and max(larguraDaFoto1, alturaDaFoto2) <= larguraDoQuadro
cabeNaDiagonal2 = (larguraDaFoto1 + alturaDaFoto2) <= alturaDoQuadro and max(alturaDaFoto1, larguraDaFoto2) <= larguraDoQuadro

cabeNaDiagonal3 = (alturaDaFoto1 + larguraDaFoto2) <= larguraDoQuadro and max(larguraDaFoto1, alturaDaFoto2) <= alturaDoQuadro
cabeNaDiagonal4 = (larguraDaFoto1 + alturaDaFoto2) <= larguraDoQuadro and max(alturaDaFoto1, larguraDaFoto2) <= alturaDoQuadro

cabeNoQuadro = cabeNaLargura or cabeNaAltura or cabeNaDiagonal1  or cabeNaDiagonal2 or cabeNaDiagonal3 or cabeNaDiagonal4

print("S" if cabeNoQuadro else "N")