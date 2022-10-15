import java.io.*;
import java.util.*;

class MyPoint {
    int x;
    int y;

    MyPoint(){
        x=0;
        y=0;
    }

    public void setXY() throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        StringTokenizer stoken =new StringTokenizer(str,",");
        x=Integer.parseInt(stoken.nextToken().trim());
        y=Integer.parseInt(stoken.nextToken().trim());
    }
}

class LineSegment{
    MyPoint a,b;

    LineSegment(){
        a = new MyPoint();
        b = new MyPoint();
    }
    
    void getXY() throws IOException{
        System.out.print("\nEnter The Value For First Point Seperate by Comma (X1,Y1) : ");
        a.setXY();
        System.out.print("\nEnter The Value For Secound Point Seperate by Comma (X2,Y2) : ");
        b.setXY();
    }

    void check_status(LineSegment obj){
        float m1,m2;

        m1=(float)(b.y - a.y)/(b.x - a.x);
        m2=(float)(obj.b.y - obj.a.y)/(obj.b.x - obj.a.x);

        if(m1==m2){
            System.out.println("\nThe Two Lines Are Parallel to Each other.\n");
        }
        else if(m1*m2==-1.0){
            System.out.println("\nThe Two Lines Are Perpendicular to Each other.\n");
        }
        else{
            System.out.println("\nThe Two Lines Are Intersect.\n");
        }
    }
}

class HwLineSegMent {

    public static void main(String[] args)throws IOException {
        LineSegment obj1= new LineSegment();
        LineSegment obj2= new LineSegment();
        
        System.out.println("\nEnter The Values of 1st Straightline: ");
        obj1.getXY();
        System.out.println("\n\nEnter The Values of 2nd Straightline: ");
        obj2.getXY();
        
        obj1.check_status(obj2);
    }
}