def medie(x:list):
    s = 0
    for i in x:
        s += i
    return s/len(x)
def mediana(x:list[int|float]): # 1 2 3 4 5 6 7 8
    x = sorted(x)
    if len(x)%2==1:
        return x[len(x)//2]
    else:
        return (x[len(x)//2-1]+x[len(x)//2])/2
def minim(x:list):
    minim = x[0]
    for i in range(1,len(x)):
        if x[i]<minim:
            minim = x[i]
    return minim
def maxim(x:list):
    maxim=x[0]
    for i in range(1,len(x)):
        if x[i]>maxim:
            maxim=x[i]
    return maxim