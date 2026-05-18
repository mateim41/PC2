# presupunem ca in optiuni prag va fi Mereu PRIMA cheie
def afiseaza_catalog(titlu,*studenti,**optiuni):
    print(f"{titlu:^27}\n{'Nume':<10}|{'Medie':<10}|{'Status':<10}")
    for i in studenti:
        _, *s = i
        k = list(optiuni.keys())
        # nr_zecimale=optiuni["zecimale"]
        nr_zecimale = optiuni[k[1]]
        print(f"{i[0]:<10}|{calcul_medie(s):<10.{nr_zecimale}f}|",end="")
        if calcul_medie(s)>= optiuni[k[0]]: #optiuni["prag"]:
            print(f"{'Promovat':<10}")
        else:
            print(f"{'Restanta':<10}")
def calcul_medie(note: list):
    nr = len(note)
    return sum(note)/nr
afiseaza_catalog("Catalog",("Matei",7,9,8,5,3,10),("Ioana",7,7,8,9.2,5),("Anca",3.5,7.2,8.5,9.25,10),("Vlad",2.5,7.5,8.25,9.5,7.95),("Robert",2.25,3.9,2.5,4.99,5.24,2.69),prag=5.0,zecimale=4)



# bazele trebuie transmise prin numar
def afiseaza_in_baze(n, *baze):
    print(f"Zecimal: {n}")
    if 2 not in baze:
        print("Binar nu se afla printre bazele selectate")
    else:
        print(f"Binar: {n:08b}")
    if 8 not in baze:
        print("Octal nu se afla printre bazele selectate")
    else:
        print(f"Octal: {n:o}")
    if 16 not in baze:
        print("Hexa nu se afla printre bazele selectate")
    else:
        print(f"Hexa: {n:X}")
    pass
afiseaza_in_baze(12,2,16)



from statistics import mean
# *valori trebuie sa fie un sir de numere
def rezuma(*valori, zecimale=2):
    if valori is None:
        return "Eroare"
    return min(valori), max(valori), mean(valori), sum(valori), len(valori)
minim, maxim, medie, suma, lungime = rezuma(1,2,3,7,9,15,2.5232,3)
print(f"{'Raport':<10}")
print('-'*10)
print(f"{f"Minim: {minim}":<10}")
print(f"{f"Maxim: {maxim}":<10}")
print(f"{f"Media: {medie}":<10}")
print(f"{f"Suma: {suma}":<10}")
print(f"{f"Nr. elemente: {lungime}":<10}")



luni=["Ianuarie","Februarie","Martie","Aprilie","Mai","Iunie","Iulie","August","Septembrie","Octombrie","Noiembrie","Decembrie"]
def raport(date, titlu="Raport vanzari", latime=30):
    print('='*latime)
    print(f"{titlu:^{latime}}")
    for luna, sales in date:
        for cnt in range(0, len(luni)):
            if luna in luni[cnt]:
                luna = luni[cnt]
                break
        print(f"{f"Luna: {luna}; Vanzari: {sales}":^{latime}}")
    print('='*latime)
vanzari = [("Ian", 1500), ("Feb", 2300), ("Mar", 1800), ("Apr", 2100)]
raport(vanzari,latime=30)