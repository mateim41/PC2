def putere(baza, exponent=2):
    return baza**exponent
print(putere(2),putere(5),putere(11),putere(2,10),putere(exponent=4,baza=5))
print()

def incadreaza(text,caracter='*',padding=2):
    l = len(text)
    print(f"{caracter*(l+2*padding)}\n{caracter*padding}{text}{caracter*padding}\n{caracter*(l+2*padding)}")
incadreaza("Python")


def adauga_student(nume, clasa=None):
    if clasa is None:
        clasa={}
    if "studenti" not in clasa:
        clasa["studenti"] = []
    clasa["studenti"].append(nume)
    return clasa
c1 = adauga_student("Ana")
c2 = adauga_student("Ion")
print(c1)
print(c2)