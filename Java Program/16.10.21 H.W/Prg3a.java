import java.io.*;

class Patt{

    public void dispstr(String str){

        int i, j, t, p=0;
    
        int l = str.length();

        if(l%2==0){
            l--;
            p=1;
        }     
        
        System.out.println();

        t=l;
        for(i=l/2, j=(l/2)+p;i>=0&&j<str.length();i--, j++){
            for (int s = 0; s < t ; s++) {
                System.out.print(" ");
            }
            t--;

            for (int k = i; k <= j; k++) {
                System.out.print(str.charAt(k));
            }
            System.out.println();
        }    

        System.out.println();
    }
} 

class Prg3a {
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Patt obj = new Patt();
        System.out.print("\nEnter the String : ");
        String str = br.readLine();
        obj.dispstr(str);
    }
}