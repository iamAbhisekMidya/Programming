/**
 * Prg4
 */
import java.io.*;

class StringSort{
    public void strsort(String str[]){

        String s;

        for (int i = 0; i < str.length-1; i++) {
            for (int j = 0; j < str.length-i-1; j++) {
                if (str[j].compareToIgnoreCase(str[j+1])>0) {
                    s=str[j];
                    str[j]=str[j+1];
                    str[j+1]=s;
                }
            }
        }
    }
    public void display(String str[]){
        
        System.out.println("\nAfter Sorting The Array of String becomes:\n");
        for (int i = 0; i < str.length; i++) {
            System.out.println(str[i]);
        }
        System.out.println();
    }
}
class Prg4 {

    public static void main(String[] args)throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        System.out.print("Enter the Number of String : ");
        int n = Integer.parseInt(br.readLine());
        
        String str[] = new String[n];
        for (int i = 0; i < n; i++) {
            System.out.print("\nEnter the String : ");
            str[i]=br.readLine();
        }

        StringSort obj = new StringSort();
        obj.strsort(str);
        obj.display(str);
    }
}
