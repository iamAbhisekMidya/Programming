import java.util.*;
import java.io.*;

class Bubble_sort{
    
    public static void main(String args[])
    {
        //Variable Declararation
        int a[], n, t, i, j;
        
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
        // Bubble Sort 
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
            }
        }
        //Display array after Bubble Sort
        System.out.println("After Bubble sort the data are: ");
        System.out.println();
        for(i=0;i<n;i++)
        {
            System.out.print(a[i]+" ");
        }
        System.out.println();
    }

}
