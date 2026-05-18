import statistics as stats
nume = "Matei"
varsta = 20
an_curent = 2026
print(f"{nume}\n{varsta}\n{an_curent}")



nota = 8
if nota < 5:
    print("Insuficient")
elif 5 <= nota <= 6:
    print("Suficient")
elif 7 <= nota <= 8:
    print("Bine")
else:
    print("Foarte bine")



nr = 2
semn = "pozitiv" if nr>0 else "zero" if nr==0 else "negativ"
print(semn)


a = -2; b = 3
x = 2.56
print(a <= x <= b)



rezultat = 42
if(rezultat==None):
    print("Inca nu exista rezultat")
else:
    print(rezultat)



v = [{1,2,2,2,2,3}]
print(v,type(v))



a = int(input("a = "))
b = int(input("b = "))
print(a+b, a-b, a/b, a//b, a%b, a**b, sep="\n")
print(2**1000)



cuvant = "Ana SE JOAcA si are Mere si Prune si Portocale SI STruGURI" # input()
print(len(cuvant), cuvant.upper(), cuvant[::-1], cuvant[:3], cuvant[(len(cuvant)-3):], sep="\n")
email = "ana.popescu@academic.tuiasi.ro"
print(email.split("@"))


def min_max(a):
    return min(a), max(a)
lista = list(range(11))
print(f"Suma: {sum(lista)}, Min/Max: {min_max(lista)[0]}/{min_max(lista)[1]}")
for i in range(0,len(lista)):
    if i%2==0:
        print(lista[i],end=" ")
print()
for i in range(len(lista)-1, -1, -1):
    print(lista[i], end=" ")
print()



numere = [1, 2, 2, 3, 4, 4, 4, 5]
numere = list(set(numere))
print(numere)
vocale = {"a", "e", "i", "o", "u"}
litere = set("programare")
print(litere & vocale, litere - vocale, sep = "\n")



for i in range(1,11):
    print(f"7 x {i} = {7*i}")
preturi = [10.5, 20.0, 33.7, 5.5, 15.0]
for i, x in enumerate(preturi):
    print(f"Produsul {i}: {x} lei")



def patrat(x):
    return x * x
while True:
    i = int(input())
    if i != 0:
        print(patrat(i))
    else:
        break
n = 29
for d in range(2,n//2+1):
    if n%d==0:
        print("n nu este prim")
        break
else:
    print("n este prim") # se executa doar daca nu se intalneste break



numere = [10, 20, 30, 40, 50]
p, *r, u = numere
print(p, r, u)



c = input()
vocale="AEIOUaeiou"
if c in vocale:
    print(f"Caracterul {c} este vocala")
else:
    print(f"Caracterul {c} este consoana")



print('-'*10)
for i in range(0,3):
    if i==1:
        print(f"|{'Salut!':^8}|")
    else:
        print(f"{'|':<9}|")
print('-'*10)
x = list("0"*100)



a = [1, 2, 3]
b = a
b[0] = 99
print(a,end="\n\n")
#
b = a.copy()
b[0] = 101
print(a,b,sep="\n")



def saluta(nume, salut="Salut"):
    print(f"{salut}, {nume}!")
saluta("Ana","Buna ziua")
#
def statistici(numere):
    return min(numere), max(numere), stats.mean(numere)
l = [4, 8, 15, 16, 23, 42]
mi, ma, med = statistici(l)
print(mi, ma, med)
#
def arie_dreptunghi(latime = 1, lungime = 1):
    return latime * lungime
print(arie_dreptunghi())
print(arie_dreptunghi(lungime = 3.5))
print(arie_dreptunghi(lungime = 3.25, latime = 2.69))