import java.io.*;

class Box{
    private float l;
    private float b;
    private float h;

    Box(float l,float b,float h){
        this.l=l;
        this.b=b;
        this.h=h;
    }

    public float volume(){
        return(l*b*h);
    }
}

public class Ass19 {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("\nEnter length : ");
        float l = Float.parseFloat(br.readLine());
        System.out.print("\nEnter breadth : ");
        float b = Float.parseFloat(br.readLine());
        System.out.print("\nEnter height : ");
        float h = Float.parseFloat(br.readLine());
        Box obj = new Box(l,b,h);
        float x = obj.volume();
        System.out.println("\nThe volume of the box is "+x);
    }
}