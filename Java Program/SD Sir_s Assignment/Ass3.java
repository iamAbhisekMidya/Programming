import java.io.*;
/**
 *3. Write a program in java to delete all consonants from an input string and print the result string.
 */
class Remove_Consonants {
    
    public char[] remove(char s[]){

        char str[]=new char[s.length];
        int n=0;

        for(int i=0;i<s.length;i++){
            if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U'||s[i]==' '||s[i]==','||s[i]=='.'){
                str[n++]=s[i];
            }
        }
        str[n]='\0';
        
        return str;
    }
}

class Ass3 {
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the String : ");
        String str = br.readLine();
        Remove_Consonants obj = new Remove_Consonants();
        int n=str.length();
        char st[]=new char[n];
        str.getChars(0, n, st, 0);
        System.out.println("After Deleting the Consonants the String Becomes : \n");
        st=obj.remove(st);
        System.out.println(st);
    }
}