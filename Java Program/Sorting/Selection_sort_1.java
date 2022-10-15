import java.util.*;
import java.io.*;

class Selection_sort_1{
    
    //Variable Declararation
    int a[], n, min, i, j, t;
        
    public static void main(String args[])
    {
        Selection_sort_1 obj = new Selection_sort_1();
        
        Scanner sc=new Scanner(System.in);
        
        System.out.print("\nEnter the number of element: ");
        obj.n=sc.nextInt();
        
        System.out.println(); //use for create a gap between two lines
        
        obj.a=new int[obj.n];  //Allocate memory for the Array
        //Array Input
        for(obj.i=0;obj.i<obj.n;obj.i++)
        {
            System.out.print("Enter a["+(obj.i+1)+"] : ");
            obj.a[obj.i]=sc.nextInt();
            System.out.println();
        }
        // Selection Sort 
        for(obj.i=0;obj.i<obj.n-1;obj.i++)
        {
            obj.min=obj.i;
            for(obj.j=obj.i+1;obj.j<obj.n;obj.j++)
            {
                if(obj.a[obj.min]>obj.a[obj.j])
                    obj.min=obj.j;    
            }
            if(obj.min!=obj.i)
            {
                obj.t=obj.a[obj.min];
                obj.a[obj.min]=obj.a[obj.i];
                obj.a[obj.i]=obj.t;
            }
        }
        //Display array after Selection Sort
        System.out.println("After Selection sort the data are: ");
        System.out.println();
        for(obj.i=0;obj.i<obj.n;obj.i++)
        {
            System.out.print(obj.a[obj.i]+" ");
        }
        System.out.println();
    }

}
