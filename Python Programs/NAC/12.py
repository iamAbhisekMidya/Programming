s=[x for x in input("Entrt the string : ").split()]
m=[0,0,[]]
c=0
for i in s:
    d=0
    for j in i:
        d+=1
    if d == m[1]:
        m[2].append(c)
    elif d > m[1]:
        m[0]=c
        m[1]=d
        m[2].clear        
    c+=1
print("The longest word(s) is/are :",s[m[0]],end="")
for i in m[2]:
    print(",",s[i],end="")
print("\nThe number of letters is",m[1])
