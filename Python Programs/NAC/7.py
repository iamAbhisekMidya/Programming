import math
def prime(x):
    if(x<2):
        return 0
    for i in range(2,math.floor(math.sqrt(x))+1):
        if x%i == 0:
            return 0
    return 1

def palindrome(x):
    x=str(x)
    r=x[-1::-1]
    if r==x:
        return 1
    else:
        return 0

lst=eval(input("Enter a list of integers : "))
print("Prime palindrome numbers are : ",end=" ")
for i in lst:
    if prime(i) and palindrome(i):
        print(i,end=" ")
