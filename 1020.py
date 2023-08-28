from math import floor

dias = int(input())
anos = floor(dias/365)
meses = floor((dias%365)/30)
dias = dias - anos * 365 - meses * 30

print("{:n} ano(s)".format(anos))
print("{:n} mes(es)".format(meses))
print("{:n} dia(s)".format(dias))