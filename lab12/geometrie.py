PI = 3.14159
def arie_cerc(r): return PI*(r^2)
def arie_dreptunghi(a,b): return a*b
def arie_triunghi(b, h): return b*h/2

if __name__ == "__main__":
    print(arie_cerc(2))
    print(arie_dreptunghi(5,6))
    print(arie_triunghi(3,2.598))