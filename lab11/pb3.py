def patrat(x: int) -> int:
    return x*x
def cub(x: int) -> int:
    return patrat(x)*x
x=3
print(patrat(x))
print(cub(x))

def este_par(n: int) -> bool:
    if divmod(n,2)[1]==0:
        return True
    else:
        return False
for i in range(31):
    if(este_par(i)):
        print(i,end=" ")
print()

def factorial(n):
    f=1
    for i in range(1,n+1):
        f*=i
    return f

def combinari(n, k):
    return factorial(n) / (factorial(k)*factorial(n-k))

print(combinari(5,3))

def max3(a,b,c):
    if a > b > c: # a > b && a > c
        return a
    elif b > a > c: # b > a && b > c
        return b
    else:           # c > a && c > b
        return c
# identifica problema si rezolv-o
def aplica_reducere(pret, procent):
    if pret > 0: # pret > 100; nu se aplica reducere pentru preturi mai mici ca 100
        return pret * (1 - procent)
p_final = aplica_reducere(80, 0.10)
print(f"Preț final: {p_final:.2f} lei")