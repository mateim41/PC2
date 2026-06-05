# 29 - Sectiunea 8
import statistici_proprii as ownstats
import statistics as stats
import random
numere = list()
for i in range(10):
    nr = random.randint(4,10)
    numere.append(nr)
print(numere)
print(ownstats.mediana(numere),ownstats.medie(numere),ownstats.minim(numere),ownstats.maxim(numere))
print(stats.median(numere),stats.mean(numere),min(numere),max(numere))