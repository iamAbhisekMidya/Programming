import java.util.*;
import java.io.*;

class Quick_sort{
    
    int partition(int a[], int left, int right)
    {
        int pos, t;
        
        pos=left;
        while(left<=right)
        {
            while(a[pos]<=a[right]&&pos!=right)
            {
                right--;
            }
            if(pos==right)
                return (pos);
            else
            {
                t=a[pos];
                a[pos]=a[right];
                a[right]=t;
                pos=right;
            }
            while(a[left]<=a[pos]&&pos!=left)
            {
                left++;
            }
            if(pos==left)
                return (pos);
            else
            {
                t=a[pos];
                a[pos]=a[left];
                a[left]=t;
                pos=left;
            }
        }
        return (pos);
    }
    
    void quick_sort_rc(int a[], int l, int r)
    {
        int i;
        if(l<r)
        {
            i=partition(a, l, r);
            quick_sort_rc(a,l,i-1);
            quick_sort_rc(a, i+1, r);
        }
    }
    
    void display(int a[], int n)
    {
        int i;
        System.out.println("The array after quick sort is : \n");

        for(i=0;i<n;i++)
        {
            System.out.print(a[i]+" ");
        }
        System.out.println("\n");
    }
    
    public static void main(String args[])
    {
        int a[], n, i;
        
        Quick_sort obj = new Quick_sort();
        
        Scanner sc= new Scanner(System.in);
        
        System.out.print("\nEnter the number of element: ");
        
        n=sc.nextInt();
        
        a=new int[n];
        
        System.out.println();
        for(i=0;i<n;i++)
        {
            System.out.print("Enter a["+i+"] : ");
            a[i]=sc.nextInt();
            System.out.println();
        }
        
        //Quick Sort
        
        obj.quick_sort_rc(a,0,n-1);
        obj.display(a,n);
    
    }

}
