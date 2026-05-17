
def f(x):
    return int(x)

x = list(map(f, input().split(" ")))
print(*x,sep=" + ",end=" = ")
# s = 0
# for i in x:
#     s += int(i)
# ^ daca nu fac cu map
print(sum(x))


# zile = ["Lu", "Ma", "Mi", "Jo", "Vi", "Sa", "Du"]
# print(*zile,sep="|")

# for i in range(0,21):
#     if i%2==0:
#         print(i,end=", ")
#     elif i%2==1:
#         print(i,end=" ")
# print("\n")

# puncte = [(1,2), (3,4), (5,6)]
# for pct in puncte:
#     print(f"x={pct[0]}, y={pct[1]}")
# print()
# # sau pot face asa
# for x, y in puncte:
#     print(f"x={x}, y={y}")
# print()

# d: dict = {
#     "Key": [1,2,3],
#     (1,2): "ceva",
#     1:{1,2,3}
# } # dictionar

# for key in d:
#     print(f"{key}, {d[key]}")