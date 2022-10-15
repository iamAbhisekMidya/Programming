import java.io.*;

public class Ass11 {

    public static int[] addeli(int a[],int x,int v){
        int temp[]=new int[a.length+1];
        if(x>a.length||x<0)
            x=a.length;
        for (int i = 0; i < x; i++) {
            temp[i]=a[i];
        }
        temp[x]=v;
        for (int i = x+1; i <= a.length; i++) {
            temp[i]=a[i-1];
        }
        return temp; 
    }
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("\nEnter the number of element : ");        
        int n=Integer.parseInt(br.readLine());
        int arr[]=new int [n];
        for (int i = 0; i < n; i++) {
            System.out.print("Enter a["+(i)+"] : ");        
            arr[i]=Integer.parseInt(br.readLine());
        }
        System.out.print("\nEnter the index number : ");        
        int x=Integer.parseInt(br.readLine());
        System.out.print("\nEnter the value : ");        
        int v=Integer.parseInt(br.readLine());
        arr=addeli(arr,x,v);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" ");        
        }
    }    
}