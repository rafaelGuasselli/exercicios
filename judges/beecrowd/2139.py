# quantidadeDeDiasEmCadaMes = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
def eofInput():
    try:
        return input()
    except EOFError:
        return False

entrada = eofInput()
while entrada:
    valores = map(int, entrada.split())
    mes, dia = valores

    QUANTIDADE_DE_DIAS_NO_NATAL = 360
    QUANTIDADES_DE_DIAS_PASSADOS_NO_INICIO_DO_MES = [0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335]

    quantidadeDeDiasPassados = QUANTIDADES_DE_DIAS_PASSADOS_NO_INICIO_DO_MES[mes - 1] + dia
    quantidadeDeDiasQueFaltamProNatal = QUANTIDADE_DE_DIAS_NO_NATAL - quantidadeDeDiasPassados

    if quantidadeDeDiasQueFaltamProNatal == 0:
        print("E natal!")
    elif quantidadeDeDiasQueFaltamProNatal == 1:
        print("E vespera de natal!")
    elif quantidadeDeDiasQueFaltamProNatal < 0:
        print("Ja passou!")
    else:
        print("Faltam {:n} dias para o natal!".format(quantidadeDeDiasQueFaltamProNatal))
    entrada = eofInput()
        