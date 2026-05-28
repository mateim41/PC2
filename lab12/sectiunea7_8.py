# 24 - Sectiunea 7
mesaj = "hello"
def afiseaza_mesaj():
    print(mesaj)
def schimba_mesaj():
    global mesaj
    mesaj = "bye"
schimba_mesaj()
afiseaza_mesaj()

# 25 - Sectiunea 7
x = "global"
def test_legb():
    # global x
    # x = "test" - asa voi modifica x si imi afiseaza test
    x = "test"
    def afiseaza():
        print(x)
    return afiseaza()
test_legb()
print(x)

# 26 - Sectiunea 7
def creeaza_contor(start = 0):
    cnt = start
    def incrementeaza():
        nonlocal cnt
        cnt+=1
        return cnt
    return incrementeaza()
print(creeaza_contor(1))
print(creeaza_contor(1))

# 27 - Sectiunea 7
def creeaza_sumator(n):
    def aduna(x):
        return x + n
    return aduna
aduna5 = creeaza_sumator(5)
print(aduna5(3))

# 28 - Sectiunea 7
total = 0
def aduna(x):
    total = total + x
    return total
print(aduna(5))
# total nu o fost initializat, fiind o variabila locala; varianta corecta jos
total = 0
def aduna(x):
    global total
    total += x
    return total
print(aduna(5), aduna(6))