# 1 - Sectiunea 1
def factura(client, *preturi, tva=19, **adresa):
    print(f"Client: {client}")
    print(f"Total fara TVA: {sum(preturi)}")
    print(f"Total cu TVA: {sum(preturi) * (1+tva/100)}")
    for k in adresa:
        print(k, adresa[k],sep=": ")
factura("Daniel",1,2,3,7.2,8.9,9.2,tva=21,oras="Iasi",strada="Roman",nr="69",cartier="Tatarasi")



# 4 - Sectiunea 2
def dublu(x):
    return x*2
def triplu(x):
    return x*3
def negativ(x):
    if x<0: return x
    else: return -x
operatii = [dublu, triplu, negativ]
for fct in operatii:
    print(fct(7), end=" | ")
print()



# 6 - Sectiunea 3
nume = ["ana", "ion", "maria"]
nume = list(map(str.upper,nume))
print(nume)

# # 7 - Sectiunea 3
numere = [12, 7, 25, 4, 88, 31, 60, 9]
def div_3(x):
    return x%3==0
numere = list(filter(div_3,numere))
print(numere)

# 8 - Sectiunea 3
from functools import reduce
n = int(input()) # nr pt care aplic factorial
def inmultire(a, b):
    return a*b
# reducere(_, l)
# def f(a, c); a - acumulator, default = 0
# cu al treilea parametru la reduce pot schimba default la acumulator
fac = reduce(inmultire, range(1,n+1))
print(fac)

# 9 - Sectiunea 3
note = [9, 7, 10, 6, 8, 9, 5]
def inmulteste_10(x):
    return x*10
rez = list(map(inmulteste_10,filter(lambda a: a>7, note)))
print(rez)
# solutie cu list comprehension
rez1 = list([x*10 for x in note if x>7])
print(rez1)

# 10 - Sectiunea 3
a = "4312 8364 392 6141 7375 8650 396 4306 4102 6942 9710 6302 604 7173 1202 7534 3603 8767 7225 7930 7824 9432 5424 4246 6190 515 7839 9106 7784 3333 6887 836 4762 9026 7057 1046 7637 878 7103 7807 6293 1317 3873 3241 4455 3067 8365 341 1504 4426 2003 6766 1260 8879 9079 9461 9833 6943 913 8416 9102 7892 3018 7166 2156 8676 5160 8271 8750 769 4356 6249 7015 956 9399 6554 6299 3009 1275 4109 7563 745 6719 7086 9935 1899 7709 3642 3181 7143 8989 8788 8086 3563 716 8440 9396 7492 334 7565 4950 8070 5583 6718 3038 6762 8880 6176 8243 2684 7549 9844 8047 5664 9349 5449 5176 9040 1871 7288 142 9030 9610 2792 5941 8731 8410 221 1662 69 8830 4966 2091 6083 7981 9485 5487 4738 5144 5365 551 9391 607 773 9063 1911 9840 4153 6576 4639 3348 9611 3676 4688 6732 6537 7083 9527 8097 3118 219 8220 1365 5821 6940 2536 647 3735 402 9665 2123 1420 614 5643 8383 7417 1286 2752 8698 861 1927 8979 8967 2480 2987 7778 859 720 5062"
nr = list(map(int,a.split(' ')))
cel_mai_mare = reduce(lambda a,b: a if a>b else b, nr)
print(cel_mai_mare, max(nr))



# 11 - Sectiunea 4
import geometrie
print(geometrie.arie_cerc(5),geometrie.arie_dreptunghi(4,6),geometrie.arie_triunghi(10,7),sep="\n")

# 12 - Sectiunea 4
import random
zar1 = list(random.choice([1,2,3,4,5,6]) for _ in range(1000))
zar2 = list(random.choice([1,2,3,4,5,6]) for _ in range(1000))
nr_sum7 = 0
for i in range(1000):
    if zar1[i]+zar2[i] == 7:
        nr_sum7+=1
print(f"{nr_sum7/10}%") # .../1000 * 100

# 13 - Sectiunea 4
import math
def dist_euclidiana(A: tuple, B: tuple) -> float:
    return math.sqrt((B[0]-A[0])**2 + (B[1]-A[1])**2) # math.dist()
print(dist_euclidiana((1,2),(5,6)))

# 14 - Sectiunea 4
from statistics import mean, median
note = "69, 32, 92, 99, 97, 56, 80, 94, 31, 52, 48, 19, 74, 26, 89, 40, 86, 91, 67, 58, 3, 20, 47, 29, 38, 84, 87, 33, 63, 57, 12, 61, 25, 71, 51, 34, 13, 28, 45, 64, 98, 59, 96, 6, 27, 65, 21, 43, 68, 17, 50, 35, 75, 23, 30, 55, 44, 49, 1, 79, 77, 11, 95, 72, 60, 76, 24, 5, 66, 70, 8, 62, 93, 39, 90, 81, 7, 78, 82, 2, 73, 54, 100, 10, 18, 42, 46, 4, 37, 14, 22, 53, 9, 85, 16, 41, 15, 36, 88, 83"
note = list(map(int,note.split(", ")))
print(min(note),max(note),mean(note),median(note))



# 20 - Sectiunea 6
def hex_la_zecimal(s):
    return int(s,base=16)
print(hex_la_zecimal('1a'),hex_la_zecimal('ff'))

# 21 - Sectiunea 6
def este_gol(x) -> bool: # returnez True daca x este empty
    if x: return False
    else: return True
print(este_gol(0),este_gol([]),este_gol(""),este_gol(None),este_gol("0"),este_gol([0]),este_gol(" "))

# 22 - Sectiunea 6
oLista =  [0, 1, "", "abc", None, [], [1]] 
print(list(filter(None,oLista)))
listaEchivalenta = list([x for x in oLista if x])
print(listaEchivalenta) # acelasi lucru

# 23 - Sectiunea 6
s = "linie1\nlinie2"
print(s,repr(s),sep='\n',end='\n\n')
s2 = "text1\ttext2"
print(s2,repr(s2),sep='\n')