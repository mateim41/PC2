# # 1
propozitie = "Ana are mere pere struguri si se joaca in parc cu mingea"
propozitie = list(propozitie.split(" "))
nr_cuv = len(propozitie)
cuv_max = max(propozitie,key=len)
propozitie.reverse()
propozitie=" ".join(propozitie)
print(f"Nr cuvinte: {nr_cuv}, cuvant cel mai lung: {cuv_max}\nProp inv: {propozitie}")
print()



# 2
def sortare(x):
    return x[1]
def medie_note(lista_tuple):
    s = 0
    for n, m in lista_tuple:
        s += m
    return s/len(lista_tuple)
studenti: list = [("Matei",10),("Vlad",7.24),("Daniela",8.2),("Ioana",5.6),("Rares",9.15)]
studenti = sorted(studenti,key=sortare,reverse=True)
print(studenti, medie_note(studenti),sep="\n")
print()



# 3
for i in range(101):
    if i%3==0 and i%5!=0:
        print("Fizz")
    elif i%5==0 and i%3!=0:
        print("Buzz")
    elif i%3==0 and i%5==0: # i%3==0 && i%5==0
        print("FizzBuzz")
    else:
        print(i)