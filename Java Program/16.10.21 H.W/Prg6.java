import java.io.*;
import java.util.*;

class Record{

    private String name;
    private String cla;
    private int roll;
    private int age;
    private float marks;

    Record(){

        name="";
        cla="";
        roll=0;
        age=0;
        marks=0.0f;
    }

    Record(String name,String cla,int roll,int age,float marks){

        this.name=name;
        this.cla=cla;
        this.roll=roll;
        this.age=age;
        this.marks=marks;
    }

    public void get_data()throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("\nEnter Name, Courses, Roll, Age, Marks (Seperate by comma) : ");
        String str = br.readLine();

        StringTokenizer stoken = new StringTokenizer(str,",");

        name = stoken.nextToken().trim();
        cla = stoken.nextToken().trim();
        roll = Integer.parseInt(stoken.nextToken().trim());
        age = Integer.parseInt(stoken.nextToken().trim());
        marks = Float.parseFloat(stoken.nextToken().trim());

        cla=cla.toUpperCase();
    }

    public void disp(){

        System.out.println(name+"\t"+cla+"\t"+roll+"\t"+age+"\t"+marks+"\n");
    }

    public boolean check_age(Record j){

        if(this.age>j.age)
            return true;
        else
            return false;    
    }

    public boolean check_marks(Record j){

        if(this.marks<j.marks)
            return true;
        else
            return false;    
    }

    public boolean check_name(Record j){

        if(this.name.compareToIgnoreCase(j.name)>0)
            return true;
        else
            return false; 
    }

    public boolean check_class(Record j){

        if(this.cla.compareToIgnoreCase(j.cla)>0)
            return true;
        else
            return false; 
    }

    public String claname(){

        return cla;
    }

    public boolean check_cl(String s){

        if(this.cla.equalsIgnoreCase(s))
            return true;
        else
            return false;
    }
}

class RecordControl{

    Record data[];
    Record temp;

    RecordControl(){

        data=new Record[0];
        data[0] = new Record();
        temp = new Record();
    }

    RecordControl(int n){

        temp = new Record();
		data = new Record[n];
		for(int i=0;i<n;i++)
			data[i] = new Record();
    }

    public void get_record(int n) throws IOException{

        for (int i = 0; i < n; i++) {
            data[i].get_data();
        }
    }

    public void disp_record(){

        System.out.println("\nThe Records are :\n");
        System.out.println("Name\t\tCourses\tRoll\tAge\tMarks\n");
        for (int i = 0; i < data.length; i++) {
            data[i].disp();
        }
    }

    public void age_sort(){

        for (int i = 0; i < data.length-1; i++) {
            for (int j = 0; j < data.length-i-1; j++) {
                if(data[j].check_age(data[j+1])){
                    temp = data[j];
                    data[j]=data[j+1];
                    data[j+1]=temp;
                }
            }
        }
    }

    public void marks_sort(){

        for (int i = 0; i < data.length-1; i++) {
            for (int j = 0; j < data.length-i-1; j++) {
                if(data[j].check_marks(data[j+1])){
                    temp = data[j];
                    data[j]=data[j+1];
                    data[j+1]=temp;
                }
            }
        }
    }

    public void name_sort(){

        for (int i = 0; i < data.length-1; i++) {
            for (int j = 0; j < data.length-i-1; j++) {
                if(data[j].check_name(data[j+1])){
                    temp = data[j];
                    data[j]=data[j+1];
                    data[j+1]=temp;
                }
            }
        }
    }

    public void count_grup_by(){

        for (int i = 0; i < data.length-1; i++) {
            for (int j = 0; j < data.length-i-1; j++) {
                if(data[j].check_class(data[j+1])){
                    temp = data[j];
                    data[j]=data[j+1];
                    data[j+1]=temp;
                }
            }
        }

        int count=1;
        String str=data[0].claname();
        for (int i = 1; i < data.length; i++) {
            if(data[i].check_cl(str)){
                count++;
            }
            else{
                System.out.println("\nStudent of class "+str+" is "+count);
                count=1;
                str=data[i].claname();
            }
        }
        System.out.println("\nStudent of class "+str+" is "+count+"\n");
    }
}

class Prg6 {
    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("\nEnter the Number of Record : ");
        int n = Integer.parseInt(br.readLine());

        RecordControl obj = new RecordControl(n);
        obj.get_record(n);

        while (true) {
            System.out.println("\n-------------------------------------");
            System.out.println("|1. Display Records.                |");
            System.out.println("|2. Sort Name In Ascending Order.   |");
            System.out.println("|3. Sort Age In Ascending Order.    |");
            System.out.println("|4. Sort Marks In Descending Order. |");
            System.out.println("|5. Group By Courses Counting.      |");
            System.out.println("|6. Exit.                           |");
            System.out.println("-------------------------------------");
            System.out.print("| Enter Your Choice : ");
            int ch = Integer.parseInt(br.readLine());
            switch (ch) {
                case 1:
                    obj.disp_record();
                    break;
                case 2:
                    obj.name_sort();
                    System.out.println("\nAfter Name Sorted In Ascending Order");
                    obj.disp_record();
                    break;
                case 3:
                    obj.age_sort();
                    System.out.println("\nAfter Age Sorted In Ascending Order");
                    obj.disp_record();
                    break;
                case 4:
                    obj.marks_sort();
                    System.out.println("\nAfter Marks Sorted In Descending Order");
                    obj.disp_record();
                    break;
                case 5:
                    System.out.println("\nPerforming Group By Courses We Get :");
                    obj.count_grup_by();
                    break;
                case 6:
                    return;
                default:
                    System.out.println("Wrong Choice....");
            }
        }
    }
}