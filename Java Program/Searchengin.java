import java.io.*;


class Record{
	
	private String name;
	private int roll;
	private float marks;
	
	Record(){
		name = "";
		roll = -1;
		marks = 0.0f;	
	}

	public void get_data(Record a[], int n) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter Your Name : ");
		name = br.readLine();
		
		while(true){
			System.out.print("\nEnter Your Roll : ");
			int y=0;
			int r = Integer.parseInt(br.readLine());
			for(int i=0;i<n;i++){
				if(r==a[i].roll){
					System.out.print("\nEntered Roll Already Present in Database\n");
					y=1;
					break;
				}
			}
			if(y==0){
				roll=r;
				break;
			}
		}
		
		System.out.print("\nEnter Your Marks in Percentage : ");
		marks = Float.parseFloat(br.readLine());
		System.out.println("\n--------------------------------------\n");
	}

	public void display(){
	
		System.out.println("\n--------------------------------------\n");
		System.out.println("Your Name is : "+name);
		System.out.println("\nYour Roll is : "+roll);
		System.out.println("\nYour Marks is : "+marks);
	}
	
	boolean searchname(String str){
	
		return (name.equalsIgnoreCase(str));
	}
	
	boolean searchroll(int r){
	
		if(roll==r)
			return true;
		else
			return false;
	}
	
	boolean searchmarks(float i, float j){
	
		if(marks>=i && marks<=j)
			return true;
		else
			return false;	
	}
}

class Record_control{

	Record arr[];
	int n;
	
	Record_control(int n){
		this.n = n;
		arr = new Record[n];
		for(int i=0;i<n;i++)
			arr[i] = new Record();
	}
	
	void get_record() throws IOException{
	
		for(int i=0;i<n;i++)
			arr[i].get_data(arr,i);
	}
	
	void display_record(){
	
		for(int i=0;i<n;i++)
			arr[i].display();
	}
	
	void record_search_by_name(String str){
	
		int x = 1;
		
		for(int i=0;i<n;i++){
			if(arr[i].searchname(str)){
				System.out.println("\nRecord of Student Name = "+str+" Founded at "+(i+1)+"th Position.\n\nThe Whole Record is :");
				arr[i].display();
				x = 0;
			}
		}
		if(x==1)
			System.out.println("\nRecord of Student Name = "+str+" Is Not Found in Database.");
	}
	
	void record_search_by_roll(int r){
	
		for(int i=0;i<n;i++){
			if(arr[i].searchroll(r)){
				System.out.println("\nRecord of Student Roll = "+r+" Founded at "+(i+1)+"th Position.\n\nThe Whole Record is :");
				arr[i].display();
				return;
			}
		}
		System.out.println("\nRecord of Student Roll = "+r+" Is Not Found in Database.");
	}
	
	void record_search_by_marks(float l, float u){
	
		int x = 1;
		
		for(int i=0;i<n;i++){
			if(arr[i].searchmarks(l,u)){
				arr[i].display();
				x = 0;
			}
		}
		if(x==1)
			System.out.println("\nRecord of Student Whose Marks Lies Between [ "+l+" And "+u+" ] Is Not Found in Database.");
	}
	
}

class Searchengin{

	public static void main(String args[]) throws IOException{
	
		int record_no, sroll, x;
		String sname;
		float ml, mu;
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter The Number of Students : ");
		record_no = Integer.parseInt(br.readLine());
		
		if(record_no<1)
			return;
			
		Record_control obj = new Record_control(record_no);
		System.out.println("\n--------------------------------------\n");
		obj.get_record();
		
		while(true){
			System.out.println("--------------------------------------");
			System.out.println("| 1. Display All Records.             |");
			System.out.println("| 2. Search Record By Name.           |");
			System.out.println("| 3. Search Record By Roll.           |");
			System.out.println("| 4. Search Record By Marks.          |");
			System.out.println("| 5. Exit.                            |");
			System.out.println("--------------------------------------");
			System.out.print("Enter Your Choice : ");
			x = Integer.parseInt(br.readLine());
			
			switch(x){
				case 1:
						System.out.println("\nAll Records Are :");
						obj.display_record();
						System.out.println();
						break;
				case 2:
						System.out.print("\nEnter The Name : ");
						sname = br.readLine();
						obj.record_search_by_name(sname);
						System.out.println();
						break;
				case 3:
						System.out.print("\nEnter The Roll of The Student : ");
						sroll = Integer.parseInt(br.readLine());
						obj.record_search_by_roll(sroll);
						System.out.println();
						break;
				case 4:
						System.out.print("\nEnter The Lower Bound of The Marks : ");
						ml = Float.parseFloat(br.readLine());
						System.out.print("\nEnter The Upper Bound of The Marks : ");
						mu = Float.parseFloat(br.readLine());
						obj.record_search_by_marks(ml,mu);
						System.out.println();
						break;
				case 5:
						return;
				default: 
						System.out.print("\nWrong Choice......\n\n");
			}
		}
	}
}
