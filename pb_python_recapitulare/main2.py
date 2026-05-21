from statistics import mean
def calculeaza_statistici(*bilete, bonus = 0):
    medie = mean(bilete) * (1+bonus)
    if 0<=medie<=250:
        return min(bilete), max(bilete), medie
    elif medie<0:
        return min(bilete), max(bilete), 0
    elif medie>250:
        return min(bilete), max(bilete), 250


studiouri: set = set()
filme_procesate: list[tuple] = list() # (titlu, director, medie)
cel_mai_bun_film = None
status = list()

while True:
    x = input()
    if x.upper()=="STOP":
        break
    if x=="":
        continue
    titlu, email, bilete_str = x.split(';')
    director, studio = email.split('@')
    bilete_str = bilete_str.split(',')
    bilete_int = list(map(int,bilete_str))

    minim, maxim, medie = calculeaza_statistici(*bilete_int)
    status.append("Blockbuster" if medie>=150 else "Slab")
    
    if cel_mai_bun_film is None:
        medie_max = medie
        cel_mai_bun_film = titlu
    elif medie > medie_max:
        medie_max = medie
        cel_mai_bun_film = titlu
    
    studiouri.add(studio)
    filme_procesate.append((titlu, director, medie))

print('='*50)
print("RAPORT VANZARI CINEMA")
print('='*50)
for i, v in enumerate(filme_procesate,start=1):
    print(f"{i}. {v[0]:<20}({v[1]:<12}) - Medie: {v[2]:.2f} [{status[i-1]}]")
    pass
print('-'*50,"STATISTICI GENERALE",sep='\n')
print(f"Cel mai bun film: {cel_mai_bun_film}\nStudiouri unice: ",end="")
print(*studiouri,sep=', ',end='\n\n') # nu este nevoie sa transform setul in lista pentru a accesa cu []
# list_studiouri = list(studiouri)
# for i in range(0,len(studiouri)):
#     if i!=len(list_studiouri)-1:
#         print(list_studiouri[i],end=", ")
#     else:
#         print(list_studiouri[i])

copie_filme_procesate = filme_procesate.copy()
print(copie_filme_procesate is filme_procesate) # False
copie_filme_procesate[0] = (copie_filme_procesate[0][0], copie_filme_procesate[0][1], 200.69)
print(f"Element lista originala: {filme_procesate[0]}\nElement lista copiata:{copie_filme_procesate[0]}")

# Inception;c.nolan@warnerbros.com;180,165,195
# Interstellar;c.nolan@paramount.com;220,198,176,201
# La La Land;d.chazelle@lionsgate.com;120,98,145
# stop