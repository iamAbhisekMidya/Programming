import java.util.*;
import java.io.*;

class Insertion_sort_1{

    //Variable Declararation
    int a[], n, x, i, j;
    
    public static void main(String args[])
    {
        
        Insertion_sort_1 obj = new Insertion_sort_1();
        
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
        // Insertion Sort 
        for(obj.i=1;obj.i<obj.n;obj.i++)
        {
            obj.x=obj.a[obj.i];
            for(obj.j=obj.i-1;obj.j>=0;obj.j--)
            {
                if(obj.a[obj.j]>obj.x)
                    obj.a[obj.j+1]=obj.a[obj.j];
                else
                    break;    
            }
            obj.a[obj.j+1]=obj.x;
        }
        //Display array after Insertion Sort
        System.out.println("After Insertion sort the data are: ");
        System.out.println();
        for(obj.i=0;obj.i<obj.n;obj.i++)
        {
            System.out.print(obj.a[obj.i]+" ");
        }
        System.out.println();
    }

}
