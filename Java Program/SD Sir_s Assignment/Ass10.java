import java.io.*;

public class Ass10 {

    public static int[] deleli(int a[],int x){
        if(x>a.length){
            System.out.println("\nIndex not found\n");
            return a;
        }
        int temp[]=new int[a.length-1];
        for (int i = 0; i < x; i++) {
            temp[i]=a[i];
        }
        for (int i = x; i < a.length-1; i++) {
            temp[i]=a[i+1];
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
        arr=deleli(arr,x);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" ");        
        }
    }    
}