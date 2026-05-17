import math

x = float(input())
print(f"sin(x)={math.sin(x):.4f}\ncos(x)={math.cos(x):.4f}\ntg(x)={math.tan(x):.4f}")

produse =  [("Pâine", 4.5), ("Lapte", 8.992), ("Ouă (10 buc)", 21.5), ("Ciocolată", 6.2)]
print(f"{'Produs':<15}|{'Pret':>8}")
for produs, pret in produse:
    print(f"{produs:<15}|{pret:>8.2f}")
print()
for i in range(17):
    print(f"{i}, bin:{i:08b}, hexa:{i:X}, oct:{i:o}")

pret = float(input("Pret = "))
tva = float(input("TVA = "))
pret_total = pret + pret*tva
print(f"{pret:>10.2f} {tva:>10.1%} {pret_total:>10.2f}")

print('*'*10)
for i in range(3):
    if i!=1:
        print(f"{'*':<9}*")
    else:
        print(f"*{'Python':^8}*")  
print('*'*10)