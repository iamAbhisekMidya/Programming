import java.io.*;
class Array_details{
    int arr[][];

    Array_details()
    {
        arr=new int[0][0];
    }
    
    Array_details(int r, int c)
    {
        arr=new int[r][c];
    }

    void getdata(int row, int col) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("\nEnter the elements : ");
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                System.out.print("\nEnter Array["+(i+1)+"]["+(j+1)+"] = ");
                arr[i][j]=Integer.parseInt(br.readLine());
            }
        }
    }

    void display()
    {
        int r=arr.length;
        if (r>0)
        {
            for(int i=0;i<r;i++)
	        {
	            int c=arr[i].length;
	            for(int j=0;j<c;j++)
		            System.out.print("   " + arr[i][j]);
	            System.out.println();
	        }
        }	
    }  
    
    void multipication(Array_details obj1,Array_details obj2,int r1,int r2,int c2){
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                arr[i][j]=0;
                for(int k=0;k<r2;k++){
                    arr[i][j]=arr[i][j]+obj1.arr[i][k]*obj2.arr[k][j];
                }
            }
        }

    }
}


class Matrix_Multipication
{
    public static void main(String args[]) throws IOException 
	{ 
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("For First Array\n");
        System.out.print("Enter the Number of Rows : ");
        int r1=Integer.parseInt(br.readLine());
        System.out.print("\nEnter the Number of Columns : ");
        int c1=Integer.parseInt(br.readLine());

        System.out.println("\nFor Secound Array\n");
        System.out.print("Enter the Number of Rows : ");
        int r2=Integer.parseInt(br.readLine());
        System.out.print("\nEnter the Number of Columns : ");
        int c2=Integer.parseInt(br.readLine());

        if(c1!=r2){
            System.out.println("\nMatrix Multipication can Not be Done.\n");
            return;
        }

        Array_details obj1 = new Array_details(r1,c1);
        System.out.println("\nEnter Data for First Array:\n");
        obj1.getdata(r1,c1);

        Array_details obj2 = new Array_details(r2,c2);
        System.out.println("\nEnter Data for Secound Array:\n");
        obj2.getdata(r2,c2);
        
        System.out.println("\nThe Content of The First Array is:\n");
        obj1.display();

        System.out.println("\nThe Content of The Secound Array is:\n");
        obj2.display();

        Array_details obj3 = new Array_details(r1,c2);
        obj3.multipication(obj1,obj2,r1,r2,c2);
        System.out.println("\nThe Multipication is:\n");
        obj3.display();
        System.out.println();
	}
}

