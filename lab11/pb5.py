from math import sqrt
from typing import Optional

def imparte(a:float,b:float)->Optional[float]:
    if b!=0:
        return a/b
print(imparte(2,0),end="\n\n")


def impartire_cu_rest(a,b):
    return a//b,a%b
a, b = impartire_cu_rest(3,2)
# print(a,b)


def analizeaza_text(text: str)->tuple[int]:
    return len(text), nr_cuvinte(text), nr_vocale(text), cuvant_max(text)

def nr_cuvinte(text):
    cuv = text.split(" ")
    return len(cuv)
def nr_vocale(text):
    voc = "AEIOUaeiou"
    nrvoc = 0
    for i in text:
        if i in voc:
            nrvoc += 1
    return nrvoc
def cuvant_max(text):
    cuv = text.split(" ")
    d: dict = {}
    for i in cuv:
        d.update({len(i): i})
    imax = -1
    for i in d.keys():
        if i > imax:
            cuv_max = d[i]
            imax=i
    return cuv_max

# text = "Python este un limbaj de programare foarte popular"
# a = analizeaza_text(text)
# print(f"lungime={a[0]}\nnr_cuvinte={a[1]}\nnr_vocale={a[2]}\ncuvantul cel mai lung={a[3]}")

def puncte_extreme(puncte: list[tuple])->tuple[int]:
    distante: dict ={}
    for x,y in puncte:
        distante = distante | {(x,y): sqrt(x*x+y*y)} 
    # for i in puncte:
    #   x=i[0]
    #   y=i[1]
    distmax = 0
    punct_max = puncte[0]
    distmin = distante[puncte[0]]
    punct_min = puncte[0]
    for i in distante.keys():
        if distante[i] > distmax:
            distmax = distante[i]
            punct_max = i
        if distante[i] < distmin:
            distmin = distante[i]
            punct_min = i
    return punct_max, punct_min
    
pct = [(1,4),(6,9),(6,7),(9,8)]
print(puncte_extreme(pct))