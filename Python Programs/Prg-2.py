lst=[]

n=int(input("How Many Student Data You Want To Insert : "))

print("\n----------------------------------------------\n")

for i in range(n):
    name=input("Enter Full Name: ")
    data=[float(y) for y in input("\nEnter the Marks of All (1-6) Semisters seperate by coma : ").split(",")]
    data.append(sum(data)/len(data))
    data.append(name)
    lst.append(data)

    print("\n----------------------------------------------\n")

print("Full_Name\tSem-1\tSem-2\tSem-3\tSem-4\tSem-5\tSem-6\tAvg\tSGPA\n")    

for i in range(len(lst)):
    print(lst[i][-1],end="\t")
    for j in range(len(lst[i])-2):
        print("%.2f"%lst[i][j],end="\t")
    
    print("%.2f\t%.2f"%(lst[i][-2],lst[i][-2]/10),"\n")
