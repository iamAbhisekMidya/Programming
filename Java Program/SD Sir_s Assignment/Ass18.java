import java.io.*;

public class Ass18 {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("\nEnter the String : ");        
        String str=br.readLine();
        int c=0;
        if(str.length()>=1)
            c=1;
        for (int i = 0; i < str.length(); i++) {
            if(str.charAt(i)==' '||str.charAt(i)==',')
                c++;
        }
        System.out.println("\nNumber of words in the string: "+c);
    }    
}