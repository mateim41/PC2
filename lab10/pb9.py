string = str(input("sir = "))
print(string)
print(len(string))

a = string.upper()
print(a)
a = a.lower()
print(a)
print(a[::-1])
print(a[:3])
x = len(a) - 3
print(a[x:])

string2 = "ana.popescu@academic.tuiasi.ro"
print(string2.split("@"))