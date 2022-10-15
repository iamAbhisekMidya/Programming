import java.io.*;

class Shape{

    private float x;

    Shape(){
        x = 0.0f;
    }

    public void get_data() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        x=Float.parseFloat(br.readLine());
    }

    public void circle_area(){
        
        double r = (x*x)*Math.PI;
        System.out.print("\nThe Area of Circle is "+r+"\n");
    }

    public void triangle_area(float h){
        double r = 0.5*h*x;
        System.out.print("\nThe Area of Triangle is "+r+"\n");
    }

    public void square_area(){
        float r = x*x;
        System.out.print("\nThe Area of Square is "+r+"\n");
    }
}

class Area extends Shape{
    
    float h;

    Area(){
        super();
        h = 0.0f;
    }
    public void get_data1() throws IOException{

        System.out.print("\nEnter the Radious of the Circle : ");
        super.get_data();
    }
    public void get_data2() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("\nEnter the Height of the Triangle : ");
        h=Float.parseFloat(br.readLine());
        System.out.print("\nEnter the Base of the Triangle : ");
        super.get_data();
    }
    public void get_data3() throws IOException{

        System.out.print("\nEnter the value of the side of Square : ");
        super.get_data();
    }

}

class Prg7 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Area obj = new Area();

        while (true) {
            System.out.println("\n-------------------------------------");
            System.out.println("|1. Area of Circle.                 |");
            System.out.println("|2. Area of Triangle.               |");
            System.out.println("|3. Area of Square.                 |");
            System.out.println("|4. Exit.                           |");
            System.out.println("-------------------------------------");
            System.out.print("| Enter Your Choice : ");
            int ch = Integer.parseInt(br.readLine());
            switch (ch) {
                case 1:
                    obj.get_data1();
                    obj.circle_area();
                    break;
                case 2:
                    obj.get_data2();
                    obj.triangle_area(obj.h);
                    break;
                case 3:
                    obj.get_data3();
                    obj.square_area();
                    break;
                case 4:
                    return;
                default:
                    System.out.println("\nWrong Choice....");
            }
        }
    }
}
