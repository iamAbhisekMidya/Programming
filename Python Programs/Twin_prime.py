import math
def prime(x):
    if(x<2):
        return 0
    for i in range(2,math.floor(math.sqrt(x))+1):
        if x%i == 0:
            return 0
    return 1

l=int(input("Enter the lower bound : "))
u=int(input("Enter the upper bound : "))
print("Twin prime Numbers of the range {0} to {1} are : ".format(l,u),end=" ")
for i in range(l,u-1):
    if prime(i) and prime(i+2) :
        print("({}, {})".format(i,i+2),end=" ")
        i+=2
        
