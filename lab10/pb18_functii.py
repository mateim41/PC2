import numpy as np

def saluta(nume, salut="Salut"):
    print(f"{salut}, {nume}!")
saluta("Matei","Ziua bună")

def statistici(numere):
    return min(numere),max(numere),np.mean(numere)

a = statistici([4, 8,15,16,23,42])
print(*a)