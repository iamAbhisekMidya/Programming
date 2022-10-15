import math
def prime(x):
    if(x<2):
        return
    for i in range(2,math.floor(math.sqrt(x))+1):
        if x%i == 0:
            return
    print(x,end=" ")

l=int(input("Enter the lower bound : "))
u=int(input("Enter the upper bound : "))
print("Prime Numbers of the range {0} to {1} are : ".format(l,u),end=" ")
for i in range(l,u+1):
    prime(i)
