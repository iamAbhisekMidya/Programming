import java.io.*;

class Patt{

    public void dispstr(String str){

        int i, j;
    
        int l = str.length();
        System.out.println();
        
        if(l%2==0){
            i=l/2-1;
            j=l/2+1;
        }
        else{
            i=l/2;
            j=l/2+1;
        }
            
        while(i>=0&&j<str.length()){           
            System.out.print(str.subSequence(0, i));
            for (int k = i; k < j; k++) {
                System.out.print(" ");
            }
            System.out.println(str.subSequence(j, str.length()));
            i--;
            j++;
        }    
        System.out.println();
    }
} 

class Prg3b {
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Patt obj = new Patt();
        System.out.print("\nEnter the String : ");
        String str = br.readLine();
        obj.dispstr(str);
    }
}