import java.io.*;

class Pattern{

    public void dispstr(String str){

        int l = str.length();

        System.out.println();

        for(int i = 0; i < l; i++) {
            for(int j = 0; j < l-i; j++) {
                System.out.print(str.charAt(j));
            }  
            System.out.println();                  
        }
        System.out.println();
    }
} 

class Prg2 {
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Pattern obj = new Pattern();
        System.out.print("\nEnter the String : ");
        String str = br.readLine();
        obj.dispstr(str);
    }
}