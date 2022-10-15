lst=eval(input("Enter a list of numbers : "))
d={}
while True:
    if len(lst)<1:
        break
    x=lst[0]
    c=lst.count(x)
    print(c)
    d[x]=c
    lst.remove(x)
print(d.items())
