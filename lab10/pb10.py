lista = list(range(1,11))
print(sum(lista))
print(min(lista), max(lista))
for i in range(0,10,2):
    print(lista[i],end=" ")
print()

for i in range(9,-1,-1):
    print(lista[i],end=" ")
print()
# sau puteam folosi lista.reverse()
# si foloseam for i in range(10) si afisam



s = "capcana"
s = s[:4][::-1][:2][::-1]
print(f"{s.upper()}{len(s)}") #PC2

## partea2

fructe = ["mere","pere","banane","caise"]
fructe.append("struguri")
print(fructe)
fructe.insert(1,"visine")
print(fructe)
fructe.remove("pere")
print(fructe)

fructe.sort()
print(fructe)