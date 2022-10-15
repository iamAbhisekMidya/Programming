import java.io.*;

class Array_Input{
    
    int arr[][];
    int r[];

    Array_Input(){

        arr = new int[0][0];
        r = new int[0];
    }
    
    Array_Input(int row,int col){

        arr = new int[row][col];
        r = new int[row];
    }

    void get_data(int row, int col) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("\nEnter the elements : ");
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                System.out.print("\nEnter Array["+(i+1)+"]["+(j+1)+"] = ");
                arr[i][j]=Integer.parseInt(br.readLine());
                r[i]=0;
            }
            System.out.println();
        }
    }

    void display(int row, int col){
        if(row>0){
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    System.out.print(" "+arr[i][j]+" ");
                }
                System.out.println();    
            }
            System.out.println("\n");
        }
    }

    void maxmin(int row, int col){
        int max, i ,j;

        if(row<0)
            return;

        for(i=0;i<row;i++){
            r[i]=arr[i][0];
            for(j=0;j<col;j++){
                if(arr[i][j]<r[i]){
                    r[i]=arr[i][j];
                }
            }
        }
        
        System.out.println("The Minimum values of the rows are:\n");
        for (i=0;i<row;i++) {
            System.out.println(r[i]);
        }
        System.out.println();

        max=r[0];
        j=0;
        for(i=1;i<row;i++){
            if(r[i]>max){
                max=r[i];
                j=i;
            }
        }

        System.out.print("The Maximum value of the above number is: "+max+"\n\n");
        System.out.print("The value present in "+(j+1)+"th row and the row is : ");
        
	    for (i = 0; i < arr[j].length; i++){
            System.out.print(arr[j][i]+" ");
        }
        System.out.println("\n");
    }
}

class Prg1{
    public static void main(String args[]) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int r,c;

        System.out.print("Enter Number of Rows : ");
        r = Integer.parseInt(br.readLine());
        System.out.print("\nEnter Number of Column : ");
        c = Integer.parseInt(br.readLine());

        Array_Input obj = new Array_Input(r,c);
        obj.get_data(r,c);
    
        System.out.println("\nThe Array is:\n ");
        obj.display(r,c);

        obj.maxmin(r,c);
    }
}