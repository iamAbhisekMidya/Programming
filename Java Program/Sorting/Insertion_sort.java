import java.util.*;
import java.io.*;

class Insertion_sort{
    
    public static void main(String args[])
    {
        //Variable Declararation
        int a[], n, x, i, j;
        
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
        // Insertion Sort 
        for(i=1;i<n;i++)
        {
            x=a[i];
            for(j=i-1;j>=0;j--)
            {
                if(a[j]>x)
                    a[j+1]=a[j];
                else
                    break;    
            }
            a[j+1]=x;
        }
        //Display array after Insertion Sort
        System.out.println("After Insertion sort the data are: ");
        System.out.println();
        for(i=0;i<n;i++)
        {
            System.out.print(a[i]+" ");
        }
        System.out.println();
    }

}
