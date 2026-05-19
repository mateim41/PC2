from statistics import mean
def calculeaza_statistici(*note,bonus=0):
    medie = mean(note) * (1 + bonus)
    if 0 <= medie <= 10:
        return min(note), max(note), medie
    elif medie < 0:
        return min(note), max(note), 0
    elif medie > 10:
        return min(note), max(note), 10

domenii = set()
studenti_procesati = list()
cel_mai_bun_student = None
medie_max = 0
status = list()

while True:
    x = input()
    if x.upper()=="STOP":
        break
    if x == "":
        continue

    nume, email, note_str = x.split(';')
    username, domeniu = email.split('@')
    note_str = note_str.split(',')
    note_int = list(map(int,note_str))

    suma = sum(note_int)/len(note_int)
    *_, medie = calculeaza_statistici(*note_int)
    status.append("Promovat" if medie>=5 else "Restantier")
    if cel_mai_bun_student is None:
        cel_mai_bun_student = nume
        medie_max = medie
    elif medie > medie_max:
        medie_max = medie
        cel_mai_bun_student = nume
    studenti_procesati.append((nume, username, suma))
    domenii.add(domeniu)

print(f"{'-'*50}\n{"RAPORT FINAL STUDENTI":^50}\n{'-'*50}")
for i, date in enumerate(studenti_procesati):
    print(f"{i}. {date[0]} ({date[1]}) - Medie: {date[2]} [{status[i]}]")
print(f"{'-'*50}\n{'STATISTICI GENERALE':^50}")
print(f"Cel mai bun student: {cel_mai_bun_student}\nDomenii de email unice: ",end="")
domenii_list = list(domenii)
for i in range(0,len(domenii_list)):
    if i!=(len(domenii_list)-1):
        print(domenii_list[i],end=", ")
    else:
        print(domenii_list[i])
print('-'*50)


copie = studenti_procesati.copy()
copie[0] = (copie[0][0], copie[0][1], 2)
print(studenti_procesati[0],copie[0],sep="\n")
# se va observa ca media copie[0] este 2


# Mihailov Matei;matei.mihailov@student.tuiasi.ro;10,7,8,9 
# Pascal Ioana;ioana.pascal@yahoo.com;2,4,6,1,2 