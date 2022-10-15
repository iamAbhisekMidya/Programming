def fibo(n):
    if n==0 or n==1:
        return n
    else:
        return(fibo(n-1)+fibo(n-2))

def call_fibo(x):
    for i in range(0,x):
        print(fibo(i),end=" ")

v=int(input("Enter the numbers of terms : "))
print("The number are : ",end=" ")
call_fibo(v)
