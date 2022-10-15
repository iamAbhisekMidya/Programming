import java.io.*;

public class Ass12 {

    public static void dis(int a[]){
        
        for (int i =0 ;i < a.length; i++) {
            for(int j=0;j< a.length;j++) {
                if (i==j) {
                    continue;
                }
                for (int k = 0; k < a.length; k++) {
                    if (a[i]+a[j]==a[k]) {
                        System.out.println("[ ( "+a[i]+" , "+a[j]+" ) "+a[k]+" ]");
                    }
                }
            }
        }
    }
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("\nEnter the number of element : ");        
        int n=Integer.parseInt(br.readLine());
        int arr[]=new int [n];
        for (int i = 0; i < n; i++) {
            System.out.print("\nEnter a["+(i)+"] : ");        
            arr[i]=Integer.parseInt(br.readLine());
        }
        System.out.println("");        
        dis(arr);
        System.out.println(""); 
    }    
}