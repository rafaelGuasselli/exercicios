QUANTIDADES_DE_DIAS_PASSADOS_NO_INICIO_DO_MES = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334]

inicioDia, inicioMes = map(int, input().split())
fimDia, fimMes = map(int, input().split())

inicioDiasPassados = QUANTIDADES_DE_DIAS_PASSADOS_NO_INICIO_DO_MES[inicioMes-1] + inicioDia
fimDiasPassados = QUANTIDADES_DE_DIAS_PASSADOS_NO_INICIO_DO_MES[fimMes-1] + fimDia

print(fimDiasPassados - inicioDiasPassados)