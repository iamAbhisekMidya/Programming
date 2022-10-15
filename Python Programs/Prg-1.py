def insetdic():
    
    print("\n------------------------------------------\n")
    key=input("Enter Your Student ID : ")
    
    while True:
        if key in d.keys():
            print("\nThis Student Has Already Taken\n\nPlease Enter Another Student Id\n")
            print("------------------------------------------")
            key=input("\nEnter Your Student ID : ")
        else:
            break
        
    name=input("\nEnter Your Full Name : ")
    data=[float(y) for y in input("\nEnter the Marks of All (1-6) Semisters seperate by coma : ").split(",")]
    data.append(sum(data)/(len(data)*10))
    data.append(name)
    d[key]=data
    print("\n------------------------------------------\n")
    return

d={}

n=int(input("Enter the Total Numbers of Students to Store into Database: "))
print("\n------------------------------------------\n")

for i in range(n):
    
    key=input("Enter Your Student ID : ")
    
    while True:
        if key in d.keys():
            print("\nThis Student Has Already Taken\n\nPlease Enter Another Student Id\n")
            print("------------------------------------------")
            key=input("\nEnter Your Student ID : ")
        else:
            break
        
    name=input("\nEnter Your Full Name : ")
    data=[float(y) for y in input("\nEnter the Marks of All (1-6) Semisters seperate by coma : ").split(",")]
    data.append(sum(data)/(len(data)*10))
    data.append(name)
    d[key]=data
    
    print("\n------------------------------------------\n")
    
while True:
    print("-------------------------------------------")
    print("|1. Insert Data in Student Records.       |")
    print("|2. Display All Student Records.          |")
    print("|3. Display a Particular Student Records. |")
    print("|4. Exit.                                 |")
    print("-------------------------------------------")
    n=int(input("\nEnter Your Choice : "))
    
    if n==1:
        insetdic()
    elif n==2:
        print("\nRecords of All Students Are :   ")
        print("\n----------------------------------------------\n")
        print("ID\tFull_Name\tSem-1\tSem-2\tSem-3\tSem-4\tSem-5\tSem-6\tSGPA\n")    
        for i in d.items():
            print(i[0],i[1][-1],sep="\t",end="\t")
            for j in range(len(i[1])-1):
                print("%.2f"%i[1][j],end="\t")
            print("\n")
        print("\n----------------------------------------------\n\n")
    elif n==3:
        print("\n----------------------------------------------\n")
        print("All the Student ID's Are :",end=" ")
        for i in d.keys():
            print(i,end=" ")
        print("\n\n------------------------------------------\n")
        key=input("Enter The Student ID : ")
        if key not in d.keys():
            print("\nThis Student ID is Not Present in Databases\n")
            print("------------------------------------------\n")
        else:
            print("\n----------------------------------------------\n")
            print("ID\tFull_Name\tSem-1\tSem-2\tSem-3\tSem-4\tSem-5\tSem-6\tSGPA\n")    
            print(key,d[key][-1],sep="\t",end="\t")
            for j in range(len(d[key])-1):
                print("%.2f"%d[key][j],end="\t")
            print("\n\n----------------------------------------------\n\n")
    else:
        break
