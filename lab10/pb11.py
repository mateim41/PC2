numere =[1, 2, 2, 3, 4, 4, 4, 5]
a = numere[1:7][:3][::-1]
print(a)


numere = list(set(numere))
print(numere)

vocale={'a','e','i','o','u'}
litere = set("programare")
print(vocale & litere)
print(litere - vocale)