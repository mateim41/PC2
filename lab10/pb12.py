for i in range(11):
    print(f"7x{i} = ",7*i,sep="")
print()

preturi = [10.5, 20.0, 33.7, 5.5, 15.0]
a = list(enumerate(preturi,start=1))
for i in a:
    print(f"Produsul {i[0]}: {i[1]} lei")
