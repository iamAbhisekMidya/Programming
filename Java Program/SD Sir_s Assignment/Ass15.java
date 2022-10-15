import java.io.*;

public class Ass15 {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("\nEnter the number of 1st String : ");        
        String str1=br.readLine();
        System.out.print("\nEnter the number of 1st String : ");   
        String str2=br.readLine();
        int x=str1.compareToIgnoreCase(str2);
        if (x==0)
            System.out.println("\nThe two strings are lexicographically.\n");
        else
            System.out.println("\nThe two strings are not lexicographically.\n");
    }    
}