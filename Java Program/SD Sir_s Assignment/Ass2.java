import java.io.*;
/** 
 *2. Write a program in java that accepts a 2D matrix and prints the matrix with row minimum and column minimum values. 
 */

class Array_Input{
    
    int arr[][];

    Array_Input(){
        arr = new int[0][0];
    }
    
    Array_Input(int row,int col){
        arr = new int[row+1][col+1];
    }

    void get_data(int row, int col) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("\nEnter the elements : ");
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                System.out.print("\nEnter Array["+(i+1)+"]["+(j+1)+"] = ");
                arr[i][j]=Integer.parseInt(br.readLine());
            }
        }
    }

    void display(int row, int col){
        if(row>0){
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    System.out.print(arr[i][j]+" ");
                }
                System.out.println();    
            }
            System.out.println("\n");
        }
    }

    void display1(int row, int col){
        int i,j;
        if(row>0){
            for(i=0;i<row-1;i++){
                for(j=0;j<col-1;j++){
                    System.out.print(+arr[i][j]+" ");
                }
                System.out.print("\t"+arr[i][j]+"\n");    
            }
            System.out.println("\n");
            for(j=0;j<col-1;j++){
                System.out.print(+arr[i][j]+" ");
            }
            System.out.println("\n");
        }
    }



    void rowcolmin(int row, int col){
        int rmin;
        int cmin;
        int i,j;
        
        if(row<0)
            return;


        for(i=0;i<row;i++){
            rmin=arr[i][0];
            for(j=0;j<col;j++){
                if(arr[i][j]<rmin){
                    rmin=arr[i][j];
                }
            }
            arr[i][j]=rmin;
        }
        for(i=0;i<col;i++){
            cmin=arr[0][i];
            for(j=0;j<row;j++){
                if(arr[j][i]<cmin){
                    cmin=arr[j][i];
                }
            }
            arr[j][i]=cmin;
        }

    }

}

class Ass2{
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

        obj.rowcolmin(r,c);

        System.out.println("\nNow the array becomes:\n ");
        obj.display1(r+1,c+1);
    }
}