
def calculeaza_comanda(*preturi, reducere=0):
    total = sum(preturi) * (1 - reducere/100) # daca presupunem ca reducere > 1
    if 0 <= reducere <= 100:
        return min(preturi), max(preturi), total
    elif reducere < 0:
        return min(preturi), max(preturi), sum(preturi)
    else:
        return min(preturi), max(preturi), 0    


provideri_email = set()
comenzi_procesate = list()
status = list()
cea_mai_valoroasa = None
total_max = 0

while True:
    x = input()
    if x.upper() == "FINAL":
        break
    if x == "":
        continue
    titlu, email, preturi_str = x.split('|')
    username, provider = email.split('@')
    preturi_str = preturi_str.split(',')
    preturi_float = list(map(float, preturi_str))
    minim, maxim, total = calculeaza_comanda(*preturi_float)

    status.append("Premium" if total>=100 else "Standard")
    if cea_mai_valoroasa is None:
        total_max = total
        cea_mai_valoroasa = titlu
    elif total > total_max:
        total_max = total
        cea_mai_valoroasa = titlu
    comenzi_procesate.append((titlu, username, total))
    provideri_email.add(provider)

print(f"{'='*50}\nRAPORT FINAL COMENZI\n{'='*50}")
for i, v in enumerate(comenzi_procesate, start=1):
    print(f"{i}. {v[0]} ({v[1]})s - Total: {v[2]:.2f} lei [{status[i-1]}]")
print(f"{'-'*50}\nSTATISTICI GENERALE:\nCea mai valoroasa comanda: {cea_mai_valoroasa}")
print(f"Provideri email unici: {', '.join(provideri_email)}\n{'='*50}")