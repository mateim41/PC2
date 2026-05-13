i = 1
while i:
    i = int(input("i = "))
    if i == 0:
        break
    print(i**2)


n = 21
for d in range(2,n//2+1):
    if n % d == 0:
        print("n nu este prim")
        break
else:
    print("n este prim")

