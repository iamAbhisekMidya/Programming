import java.io.*;
class Square{

    private double side;
    
    Square(double side){
        this.side=side;
    }

    public double squ(){
        return(side*side);
    }

    public void getVolume(){

        double volume = squ();
        volume = volume*side;
        System.out.println("\nThe Volume of the Square is "+volume);
    }
}

class Cylinder extends Square{

    private double height;

    Cylinder(double side, double height){
        super(side);
        this.height=height;
    }

    public void getVolume(){

        super.getVolume();
        double cyvol = squ();
        cyvol = cyvol*3.14*height;
        System.out.println("\nThe Volume of the Cylinder is "+cyvol);
    }
}

class Ass6{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("\nEnter the value of Side : ");
        double side = Double.parseDouble(br.readLine());
        System.out.print("\nEnter the value of Height : ");
        double height = Double.parseDouble(br.readLine());

        Cylinder obj = new Cylinder(side,height);
        obj.getVolume();
    }
}