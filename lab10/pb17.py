# a = [1, 2, 3]
# b = a
# b[0] = 99
# print(a)

# c = [1, 2, 3]
# d = c.copy()
# d[0] = 99
# print(c)


persoane = [("Alin",10),("Cosmin",2),("Alex",3)]

def m(x):
    return x[1]
    # daca am un obiect pot sa sortez dupa x.get_nota()
    # sau x.get_nume()

persoane = sorted(persoane, key=m,reverse=True) # ii dau tot o functie de comparere, dar de fapt e de mapare
print(persoane)