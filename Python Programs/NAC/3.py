x=13
n=int(input("Enter the number of element : "))
for i in range(n):
    print(x,end=" ")
    r=x%10
    x=x+r
