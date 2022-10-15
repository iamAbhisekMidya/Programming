import java.util.*;
import java.io.*;

class Bubble_sort_1{
    
    //Variable Declararation
    int a[], n, t, i, j;
    
    public static void main(String args[])
    {
        Bubble_sort_1 obj = new Bubble_sort_1();
        
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
        // Bubble Sort 
        for(obj.i=0;obj.i<obj.n-1;obj.i++)
        {
            for(obj.j=0;obj.j<obj.n-obj.i-1;obj.j++)
            {
                if(obj.a[obj.j]>obj.a[obj.j+1])
                {
                    obj.t=obj.a[obj.j];
                    obj.a[obj.j]=obj.a[obj.j+1];
                    obj.a[obj.j+1]=obj.t;
                }
            }
        }
        //Display array after Bubble Sort
        System.out.println("After Bubble sort the data are: ");
        System.out.println();
        for(obj.i=0;obj.i<obj.n;obj.i++)
        {
            System.out.print(obj.a[obj.i]+" ");
        }
        System.out.println();
    }

}
