import java.io.*;

/** 
 * 1. Write a program in java that sorts half of element in ascending and rest half of the elements in descending order. 
 */

class Input_Array{
    
    int arr[];

    Input_Array(){
        arr = new int[0];
    }
    
    Input_Array(int n){
        arr = new int[n];
    }

    void get_data(int n) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("\nEnter the elements : ");
        for(int i=0;i<n;i++){
            System.out.print("\nEnter Array["+(i+1)+"] = ");
            arr[i]=Integer.parseInt(br.readLine());
        }
    }

    void display(){
        int n=arr.length;
        for(int i=0;i<n;i++){
            System.out.print("["+arr[i]+"]  ");
        }
        System.out.println("\n");
    }

    public void sort(){
        int n = arr.length;
        int x = n/2;
        for(int i=0;i<x-1;i++){
            for(int j=0;j<x-i-1;j++){
                if(arr[j]>arr[j+1]){
                    int t = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = t;
                }
            }
        }
        for(int i=x;i<n-1;i++){
            for(int j=x;j<n-1;j++){
                if(arr[j]<arr[j+1]){
                    int t = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = t;
                }
            }
        }
    }

}

class Ass1{
    public static void main(String args[]) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter Number of Elements: ");
        int n = Integer.parseInt(br.readLine());

        Input_Array obj = new Input_Array(n);
        obj.get_data(n);
        obj.sort();
        System.out.println("\nAfter Sorting The Array is:\n ");
        obj.display();
    }
}