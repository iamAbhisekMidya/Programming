x=13
n=int(input("Enter the number of element : "))
for i in range(n):
    print(x,end=" ")
    s = list(map(int, str(x)))
    r=sum(s)
    x=x+r
