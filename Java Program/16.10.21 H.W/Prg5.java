import java.io.*;

class PatternSearch{
    public int psearch(String str1, String str2){

        int c=0;
        int x=-1;

        while (true){
            x=str1.indexOf(str2, x+1);
            if(x==-1)
                break;
            c++;
        }
        return c;
    } 
}
public class Prg5 {
    public static void main(String[] args)throws IOException {
        
        String str1, str2;
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        System.out.print("\nEnter the Main String : ");
        str1=br.readLine();
        
        System.out.print("\nEnter the Sub String : ");
        str2=br.readLine();

        PatternSearch obj = new PatternSearch();
        int r = obj.psearch(str1,str2);

        if (r==0){
            System.out.println("\nThe Substring [ "+str2+" ] could not found in the Mainstring.\n");
        } 
        else{
            System.out.println("\nThe Substring [ "+str2+" ] found in the Mainstring "+r+" times.\n");
        }
    }
}