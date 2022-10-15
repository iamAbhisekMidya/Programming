import java.util.*;
import java.io.*;

class Selection_sort{
    
    public static void main(String args[])
    {
        //Variable Declararation
        int a[], n, min, i, j, t;
        
        Scanner sc=new Scanner(System.in);
        
        System.out.print("\nEnter the number of element: ");
        n=sc.nextInt();
        
        System.out.println(); //use for create a gap between two lines
        
        a=new int[n];  //Allocate memory for the Array
        //Array Input
        for(i=0;i<n;i++)
        {
            System.out.print("Enter a["+(i+1)+"] : ");
            a[i]=sc.nextInt();
            System.out.println();
        }
        // Selection Sort 
        for(i=0;i<n-1;i++)
        {
            min=i;
            for(j=i+1;j<n;j++)
            {
                if(a[min]>a[j])
                    min=j;    
            }
            if(min!=i)
            {
                t=a[min];
                a[min]=a[i];
                a[i]=t;
            }
        }
        //Display array after Selection Sort
        System.out.println("After Selection sort the data are: ");
        System.out.println();
        for(i=0;i<n;i++)
        {
            System.out.print(a[i]+" ");
        }
        System.out.println();
    }

}
