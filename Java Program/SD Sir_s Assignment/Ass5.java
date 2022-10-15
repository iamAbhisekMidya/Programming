/**
 * Ass5
 */
import java.io.*;

class Person {

    private String name;
    private String address;

    Person(){
        name="";
        address="";
    }

    void setPerson(String name, String address){
        this.name=name;
        this.address=address;
    }

    void tostring(){
        System.out.print("\nPerson[ name = "+name+", address = "+address);
    } 
}

class Student extends Person{
    
    private String program;
    private String year;
    private double fees;

    Student(){
        super();
        program="";
        year="";
        fees=0.0;
    }

    void setStudent(String name, String address, String program, String year, double fees){
        super.setPerson(name, address);
        this.program=program;
        this.year=year;
        this.fees=fees;
    } 

    void tostring(){
        super.tostring();
        System.out.println(", Program = "+program+", Year = "+year+" Fees = "+fees+" ]\n");
    } 
}

class Staff extends Person{
    
    private String school;
    private double pay;

    Staff(){
        super();
        school="";
        pay=0.0;
    }

    void setStaff(String name, String address, String school, double pay){
        super.setPerson(name, address);
        this.school=school;
        this.pay=pay;
    } 

    void tostring(){
        super.tostring();
        System.out.println(", School = "+school+", Pay = "+pay+" ]\n");
    } 
}

class Ass5{
    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String name, address, program, year, school;
        Double fees, pay;

        System.out.println("\n1. For Student");
        System.out.println("2. For Stuff");
        System.out.print("Enter your choice : ");
        int x=Integer.parseInt(br.readLine());

        switch (x) {
            case 1:
                Student obj1 = new Student();

                System.out.print("\nEnter your name: ");
                name=br.readLine();
                System.out.print("\nEnter your address: ");
                address=br.readLine();
                System.out.print("\nEnter your program: ");
                program=br.readLine();
                System.out.print("\nEnter your year: ");
                year=br.readLine();
                System.out.print("\nEnter your fees: ");
                fees= Double.parseDouble(br.readLine());
                
                obj1.setStudent(name, address, program, year, fees);;
                obj1.tostring();

                break;

            case 2:
                Staff obj2 = new Staff();

                System.out.print("\nEnter your name: ");
                name=br.readLine();
                System.out.print("\nEnter your address: ");
                address=br.readLine();
                System.out.print("\nEnter your school: ");
                school=br.readLine();
                System.out.print("\nEnter your pay: ");
                pay= Double.parseDouble(br.readLine());
                
                obj2.setStaff(name, address, school, pay);
                obj2.tostring();

                break;
        
            default:
                System.out.println("\nWrong choise...\n");
        }

    }
}