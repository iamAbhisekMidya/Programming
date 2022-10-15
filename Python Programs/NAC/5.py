def ss(x):
    s=0
    for i in range(1,x+1):
        s=s+i
    return s

def ps(x):
    s=1
    for i in range(1,x+1):
        s=s*i
    return s

n=int(input("Enter the number of terms : "))

if n<1:
    r=0
else:
    r=1
    
for i in range(2,n+1):
    r=r+(ps(i)/ss(i))
         
print("The Result is : ",r)
