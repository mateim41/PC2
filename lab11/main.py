import math

a,b,c=int(input().split(" "))
s = a+b+c
print(f"{a} + {b} + {c} = {s}") 

zile = ["Lu", "Ma", "Mi", "Jo", "Vi", "Sa", "Du"]
print(" | ".join(zile),end="\n\n")
#
for i in range(21):
    if i%2==0:
        print(i,end=", ")
    else:
        print(i,end=" ")
print()
#
puncte =[(1,2),(3,4),(5,6)]
for pct in puncte:
    x=pct[0]; y=pct[1]
    print(f"x = {x}, y = {y}")



x = float(input())
print(f"{math.sin(x):.4f}, {math.cos(x):.4f}, {math.tan(x):.4f}")

produse = [("Pâine", 4.5), ("Lapte", 8.993), ("Ouă (10 buc)", 21.5), ("Ciocolată", 6.2)]
print(f"{"Produs":<15}|{"Pret":>8}\n{'-'*15}|{'-'*8}")
for prod, pret in produse:
    print(f"{prod:<15}|{pret:>8,.2f}")

for i in range(0,17):
    print(f"{i}, bin:{i:08b}, hexa:{i:X}, octal:{i:o}")
#
nr = float(input("nr = "))
tva = float(input("tva = "))
print(f"pret net:{nr}\ntva:{tva:.1%}\npret total:{nr*(1+tva)}")

print('*'*10)
for i in range(0,3):
    if i == 1:
        print(f"*{"Python":^8}*")
    else:
        print(f"*{'*':>9}")
print('*'*10)



def patrat(x: int) -> int:
    return x*x
def cub(x):
    return patrat(x)*x
print(patrat(2),cub(3))
#
def este_par(n: int) -> int:
    if(n%2==0):
        return True
    else:
        return False
for i in range(31):
    if este_par(i):
        print(i,end=" ")
print()
#
def factorial(n):
    p = 1
    for i in range(2,n+1):
        p*=i
    return p
def combinari(n,k):
    return factorial(n)/(factorial(k)*factorial(n-k))
print(combinari(5,2), combinari(7,3))
#
def max3(a, b, c: Any) -> Any:
    if a > b > c:
        return a
    elif b > a > c:
        return b
    else:
        return c
#
def aplica_reducere(pret, procent):
    if pret > 0: # pret > 100 initial
        return pret * (1 - procent)
p_final = aplica_reducere(80, 0.10)
print(f"Preț final: {p_final:.2f} lei")



def putere(baza, exponent = 2):
    return baza**exponent
print(putere(5),putere(2,10),putere(exponent=3,baza=4))
#
def incadreaza(text, caracter="*",padding=2):
    print(f"{caracter*(2*padding+len(text))}")
    print(f"{caracter*padding}{text}{caracter*padding}")
    print(f"{caracter*(2*padding+len(text))}")
incadreaza("Ana are mere",padding=5,caracter="-")
#
def adauga_student(nume, clasa=None):
    if clasa is None:
        clasa: dict = {}
    if "studenti" not in clasa:
        clasa["studenti"] = []
    clasa["studenti"].append(nume)
    return clasa
c1 = adauga_student("Ana")
c2 = adauga_student("Ion")
print(c1)
print(c2)



from typing import Optional
def imparte(a: float, b: float) -> Optional[float]:
    if b!=0:
        return a/b
print(imparte(2,0))



def impartire_cu_rest(a, b):
    return a//b, a%b
print(impartire_cu_rest(17,5))
#
txt = "Python este un limbaj de programare foarte popular"
def analizeaza_text(text):
    return len(text), nr_cuvinte(text), nr_vocale(text), cuv_cel_mai_lung(text)
    pass
def nr_cuvinte(text):
    a = text.split(" ")
    return len(a)
def nr_vocale(text: str):
    a = list(text)
    vocale="AEIOUaeiou"
    nr_voc=0
    for i in a:
        if i in vocale:
            nr_voc+=1
    return nr_voc
def cuv_cel_mai_lung(text: str):
    a = list(text.split(" "))
    len_max = len(a[0])
    cuv_max = a[0]
    for i in a:
        if len(i) > len_max:
            len_max = len(i)
            cuv_max = i
    return cuv_max
s = analizeaza_text(txt)
print(s)
#
def puncte_extreme(puncte: list[tuple]):
    pct_min = puncte[0]
    dist_min = math.sqrt(pct_min[0]**2+pct_min[1]**2)
    pct_max = puncte[0]
    dist_max = math.sqrt(pct_max[0]**2+pct_max[1]**2)
    for x, y in puncte:
        dist = math.sqrt(x**2 + y**2)
        if dist > dist_max:
            dist_max = dist
            pct_max = (x, y)
        if dist < dist_min:
            dist_min = dist
            pct_min = (x, y)
    return pct_min, pct_max
pct = [(1,2), (-1, 0.5), (5, 6), (6, 9)]
print(puncte_extreme(pct))



# presupunem ca primim doar numere ca argument
def media(*args):
    nr = len(args)
    if len(args) == 0:
        return 0
    else:
        return sum(args)/nr
print(media(1,2,3,4,5,6,7,8,8))
#
def concateneaza(separator, *texte):
    text = texte[0]
    for i in range(1,len(texte)):
        text = f"{text}{separator}{texte[i]}"
    return text
print(concateneaza(' ',"Matei","se","joaca","si","are","mere"))
#
def creeaza_persoana(**kwargs): # nume, varsta, oras, profesie
    print(f"{'PROFIL':^20}")
    for k, v in kwargs.items():
            print(f"{k:>10} = {v:<10}")
creeaza_persoana(nume="Popescu",prenume="Daniel",varsta=20,oras="Iasi",profesie="Profesor Matematica")
#
def log(nivel, *mesaje, **optiuni):
    print(f"[{nivel}]",end=" ")
    for i in mesaje:
        print(i,end=" ")
    print()
    for k, v in optiuni.items(): # for a in optiuni; a lua doar cheia si faceam optiuni[a]
        print(f"{k} = {v}")
log("EROARE","Conexiune","pierduta",user="ana", ip="192.168.1.5", modul="auth")
#
def apel_print_extins(*args,**kwargs):
    print(*args,**kwargs)
apel_print_extins("a", "b", "c", sep="-", end="!!!\n")