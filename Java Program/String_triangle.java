import java.util.*;

class String_triangle
{
    public static void main(String args[])
    {
        int t=10,i,j,n,k;
        
        Scanner sc=new Scanner(System.in);
        
        System.out.print("Enter your string : ");
        
        String str=sc.nextLine();
        n=str.length();
        
        System.out.println();
        
        for(i=0,j=n;i<=j;i++,j--)
        {
            for(k=1;k<t;k++)
            {
                System.out.print(" ");
            }
            t++;
            System.out.println(str.substring(i,j));
        }
        
        System.out.println();
    }
}
