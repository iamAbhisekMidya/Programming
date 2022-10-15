import java.io.*;

public class Ass13 {

    public static int[] remove(int a[]){
        int n = a.length;
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (a[i]==a[j]) {
                    for (int k = j; k < n-1; k++) {
                        a[k]=a[k+1];
                    }
                    n--;
                    j--;
                }
            }
        }
        int temp[] = new int[n];
        for (int i = 0; i < n; i++) {
            temp[i] = a[i];
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
        arr=remove(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" ");        
        }
    }    
}