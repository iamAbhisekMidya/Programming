import java.util.*;
import java.io.*;

class Display_array
{
    public void display(int array[], int n)
    {
        int i;
        System.out.print("\nThe content of the array is: ");
        for(i=0;i<n-1;i++)
            System.out.print(array[i]+", ");
            
        System.out.println(array[i]+".\n");    
    }
    
    public void display1(int array[], int n)
    {
        int i;
        System.out.print("\nThe content of the array is: ");
        for(i=1;i<n;i++)
            System.out.print(array[i]+", ");
            
        System.out.println(array[i]+".\n");    
    }
    
    public void display_steps(int array[], int n)
    {
        int i;
        System.out.println();
        for(i=0;i<n;i++)
            System.out.print(array[i]+" "); 
        System.out.println();       
    }
    
    public void display_steps1(int array[], int n)
    {
        int i;
        System.out.println();
        for(i=1;i<=n;i++)
            System.out.print(array[i]+" "); 
        System.out.println();       
    }
}

class Sorting
{    
    Display_array obd = new Display_array();
    int qn, qm;
      
    public void bubble_sort(int a[], int n)
    {
        int i, j, temp;
        
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
            
            obd.display_steps(a,n);
        }
    }
    
    public void modified_bubble_sort(int a[], int n)
    {
        int i, j, temp, flag=1;
        
        for(i=0;i<n-1&&flag==1;i++)
        {
            flag=0;
            for(j=0;j<n-i-1;j++)
            {   
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    flag=1;
                }
            }
            
            obd.display_steps(a,n);
        }
    }
    
    public void insertion_sort(int a[], int n)
    {
        int i, j, x;
        
        for(i=1;i<n;i++)
        {
            x=a[i];
            for(j=i-1;j>=0;j--)
            {
                if(a[j]>x)
                    a[j+1]=a[j];
                else
                    break;    
            }
            a[j+1]=x;
            
            obd.display_steps(a,n);
        }
    }
    
    public void selection_sort(int a[], int n)
    {
        int i, j, min, temp;
        
        for(i=0;i<n-1;i++)
        {
            min=i;
            for(j=i+1;j<n;j++)
            {
                if(a[min]>a[j])
                    min=j;    
            }
            if(min!=i)
            {
                temp=a[min];
                a[min]=a[i];
                a[i]=temp;
            }
            
            obd.display_steps(a,n);    
        }
    }
    
    public int partition(int a[], int left, int right)
    {
        int pos, t;
        
        pos=left;
        while(left<=right)
        {
            while(a[pos]<=a[right]&&pos!=right)
            {
                right--;
            }
            if(pos==right)
                return (pos);
            else
            {
                t=a[pos];
                a[pos]=a[right];
                a[right]=t;
                pos=right;
            }
            while(a[left]<=a[pos]&&pos!=left)
            {
                left++;
            }
            if(pos==left)
                return (pos);
            else
            {
                t=a[pos];
                a[pos]=a[left];
                a[left]=t;
                pos=left;
            }
        }
        return (pos);
    }
    
    public void quick_sort_rc(int a[], int l, int r)
    {
        int i;
               
        if(l<r)
        { 
            
            obd.display_steps(a, qn);
            
            i=partition(a, l, r);  
            quick_sort_rc(a,l,(i-1));
            quick_sort_rc(a, (i+1), r);
        }  
    }
    
    public void quick_sort(int a[], int n)
    {
        int lower[] = new int [n];
        int upper[] = new int [n];
        int pos,beg,end,top=-1;
        
	    if(n<=1)
		    return;
		    
	    top=top+1;
	    lower[top]=0;
	    upper[top]=(n-1);
	    while(top!=(-1))
	    {
		    beg=lower[top];
		    end=upper[top];
		    top=(top-1);
		    pos=partition(a,beg,end);
		    if((beg+1)<pos)
		    {
			    top=(top+1);
			    lower[top]=beg;
			    upper[top]=(pos-1);
		    }
		    if(end>(pos+1))
		    {
			    top=(top+1);
			    lower[top]=(pos+1);
			    upper[top]=end;
		    }
		    
		    obd.display_steps(a,n);
	    }	   
    }
    
    public void merge(int a[], int low, int mid, int high)
    {
	    int b[] = new int[high];
	    int i, j, k, h;
	    
	    i=low;               
	    h=low;             
	    k=(mid+1);         
	    while(h<=mid && k<=high)
	    {
		    if(a[h]<=a[k])
		    {
			    b[i]=a[h];
			    h++;
		    }
		    else
		    {
			    b[i]=a[k];
			    k++;
		    }
		    i++;
	    }
	    if(h>mid)     
	    {		
		    for(j=k;j<=high;j++)
		    {
			    b[i]=a[j];
			    i++;
		    }
	    }
	    else
	    {			
		    for(j=h;j<=mid;j++)
		    {
			    b[i]=a[j];
			    i++;
		    }
	    }	
	    for(j=low;j<=high;j++)
	    {
		    a[j]=b[j];
	    }
    }
    
    public void merge_sort_rc(int a[], int low, int high)
    {
	    int mid;
	    
	    if(low<high)
	    {
		    mid=(low+high)/2;
		    merge_sort_rc(a,low,mid);
		    merge_sort_rc(a,mid+1,high);
		    merge(a,low,mid,high);
		    
		    obd.display_steps(a,qn);
	    }	
    }
    
    void merge_sort(int a[], int n)
    {
	    int b[] = new int [n];
	    int i, j, k, m, l1, l2, u1, u2, size=1;
	    
	    while(size<n)
	    {
		    k=0;
		    l1=0;
		    while((l1+size)<n)
		    {
			    l2=l1+size;
			    u1=l2-1;
			    if((l2+size-1)<n)
				    u2=(l2+size-1);
			    else
				    u2=n-1;
			    i=l1;
			    j=l2;
			    while(i<=u1 && j<=u2)
			    {
				    if(a[i]<a[j])
				    {
					    b[k]=a[i];
					    i++;
				    }
				    else
				    {
					    b[k]=a[j];
					    j++;
				    }
				    k++;
			    }
			    while(i<=u1)
			    {
				    b[k]=a[i];
				    k++;
				    i++;
			    }
			    while(j<=u2)
			    {
				    b[k]=a[j];
				    k++;
				    j++;
			    }
			    l1=u2+1;	
		    }
		    for(m=0;m<k;m++)
		    {
			    a[m]=b[m];
		    }
		    size=size*2;
		    
		    obd.display_steps(a, qn);
	    }
    }
    
    public void create_max_heap(int a[],int n,int item)
    {
	    int ptr,par;
	    
	    ptr=n;
	    while(ptr!=1)
	    {
		    par=ptr/2;
		    if(a[par]<item)
			    a[ptr]=a[par];
		    else
			    break;
		    ptr=par;		
	    }
	    a[ptr]=item;
    }
    
    public void del_max_heap(int a[],int n)
    {
	    int ptr,item;
	    
	    item=a[n];
	    a[n]=a[1];
	    n=n-1;
	    ptr=1;
	    while(2*ptr+1<=n)
	    {
		    if(item>a[2*ptr]&&item>a[2*ptr+1])
			    break;
		    else if(a[2*ptr]>a[2*ptr+1])	
		    {
			    a[ptr]=a[2*ptr];
			    ptr=ptr*2;
		    }
		    else
		    {
			    a[ptr]=a[2*ptr+1];
			    ptr=2*ptr+1;
		    }
	    }
	    if(2*ptr>n)
		    a[ptr]=item;
	    else if(item>a[2*ptr])
		    a[ptr]=item;
	    else
	    {
		    a[ptr]=a[2*ptr];
		    a[2*ptr]=item;
	    }
	    
	    obd.display_steps1(a, qm);
    }
    
    public void create_min_heap(int a[],int n,int item)
    {
	    int ptr,par;
	    
	    ptr=n;
	    while(ptr!=1)
	    {
		    par=ptr/2;
		    if(a[par]>item)
			    a[ptr]=a[par];
		    else
			    break;
		    ptr=par;		
	    }
	    a[ptr]=item;
    }
    
    public void del_min_heap(int a[],int n)
    {
	    int ptr,item;
	    
	    item=a[n];
	    a[n]=a[1];
	    n=n-1;
	    ptr=1;
	    while(2*ptr+1<=n)
	    {
		    if(item<a[2*ptr]&&item<a[2*ptr+1])
			    break;
		    else if(a[2*ptr]<a[2*ptr+1])	
		    {
			    a[ptr]=a[2*ptr];
			    ptr=ptr*2;
		    }
		    else
		    {
			    a[ptr]=a[2*ptr+1];
			    ptr=2*ptr+1;
		    }
	    }
	    if(2*ptr>n)
		    a[ptr]=item;
	    else if(item<a[2*ptr])
		    a[ptr]=item;
	    else
	    {
		    a[ptr]=a[2*ptr];
		    a[2*ptr]=item;
	    }
	    
	    obd.display_steps1(a, qm);
    }
    
    public void radix_sort(int a[], int n, int len)
    {
	    int b[][], top[], i, j, k, l, pos;
	    
	    b=new int[10][n];
	    top=new int[10];
	    
	    //Radix sort technique
	    for(i=0;i<len;i++)
	    {
		    //initialize the stack
		    for(j=0;j<10;j++)
		    {
			    top[j]=(-1);
		    }
		    //separate digits from number and put into stack
		    for(k=0;k<n;k++)
		    {
			    pos=(int)(a[k]/Math.pow(10,i))%10;
			    b[pos][++top[pos]]=a[k];
		    }
		    //collect elements from stacks to array b
		    l=(-1);
		    for(j=0;j<10;j++)
		    {
			    for(k=0;k<=top[j];k++)
			    {
				    a[++l]=b[j][k];
			    }
		    }
		    
		    obd.display_steps(a, n);
	    }
    }
    
    public void shell_sort(int a[],int n)
    {
	    int gap,i,j,t;
	    /* started with a larger gap, then reduce the gap to 1. We take gap sequence in order of n/2, n/4,n/8, ...1 */
	    for(gap=n/2;gap>0;gap=gap/2)
	    {
		    /* we perform gapped inertion sort for this gap size. The fiest gap elements a[0...gap-1] are already in gapped order 
		    keep adding one more element until the entire array is gap sorted */
		    for(i=gap;i<n;i++)
		    {
			    //store a[i] in t and make a hole at position i
			    t=a[i];
			    //shift earlier gap sorted elements up until the correct location for a[i] is found
			    for(j=i;j>=gap&&a[j-gap]>t;j=j-gap)
			    {
				    a[j]=a[j-gap];
			    }
			    //put t (the original a[i] in its correct location)
			    a[j]=t;
		    }
		    
		    obd.display_steps(a, n);
        }
    }
    
}

class All_Sorting
{   
    public int array[], array1[], array2[], n, m;
        
    public void create_array()
    {
        Scanner cs = new Scanner(System.in);
        
        System.out.print("\nEnter the number of element: ");
        
        n=cs.nextInt();
        array=new int[n];
        array1=new int[n];
        
        for(int i=0;i<n;i++)
        {
            System.out.print("\nEnter Array ["+(i+1)+"] : ");
            array[i]=cs.nextInt();
            array1[i]=array[i];
        }
        System.out.println();
    }
    
    public static void main(String args[]) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        Sorting sort = new Sorting();
     
        All_Sorting obj = new All_Sorting();
        Display_array disp = new Display_array();
        
        int x, i, len, item;
        
        System.out.println("\n|--------------Creating Array-------------|\n");
        obj.create_array();
        sort.qn=obj.n;
                
        while(true)
        {   
            System.out.println("------------------------------------------|");
            System.out.println("| 1. Create Array.                        |");
            System.out.println("| 2. Display Input Data Of The Array.     |");
            System.out.println("| 3. Bubble Sort.                         |");
            System.out.println("| 4. Modified Bubble Sort.                |");
            System.out.println("| 5. Insertion Sort.                      |");
            System.out.println("| 6. Selection Sort.                      |");
            System.out.println("| 7. Quick Sort [Recursivly].             |");
            System.out.println("| 8. Quick Sort [Non-Recursivly]          |");
            System.out.println("| 9. Marge Sort [Recursivly].             |");
            System.out.println("|10. Marge Sort [Non-Recursivly].         |");
            System.out.println("|11. Heap Sort.                           |");
            System.out.println("|12. Shell Sort.                          |");
            System.out.println("|13. Radix Sort.                          |");
            System.out.println("|14. Exit from program.                   |");
            System.out.println("------------------------------------------|");
            System.out.print("\nEnter your choice : ");
            x=sc.nextInt();
            
            for(i=0;i<obj.n;i++)
                obj.array[i]=obj.array1[i];
            
            switch(x)
            {
                case  1: 
                            obj.create_array();
                            sort.qn=obj.n;
                            break;
                case  2: 
                            disp.display(obj.array,obj.n);
                            break;   
                case  3:    
                            System.out.println("\n|-----------Before Bubble Sort------------|");
                            disp.display(obj.array,obj.n);
                            System.out.println("|----------Appling Bubble Sort------------|");
                            sort.bubble_sort(obj.array,obj.n);
                            System.out.println("\n|------------After Bubble Sort------------|");
                            disp.display(obj.array,obj.n);
                            break;   
                case  4:    
                            System.out.println("\n|-------Before Modified Bubble Sort--------|");
                            disp.display(obj.array,obj.n);
                            System.out.println("|------Appling Modified Bubble Sort--------|");
                            sort.modified_bubble_sort(obj.array,obj.n);
                            System.out.println("\n|--------After Modified Bubble Sort--------|");
                            disp.display(obj.array,obj.n);
                            break;   
                case  5:    
                            System.out.println("\n|----------Before Insertion Sort-----------|");
                            disp.display(obj.array,obj.n);
                            System.out.println("|---------Appling Insertion Sort-----------|");
                            sort.insertion_sort(obj.array,obj.n);
                            System.out.println("\n|-----------After Insertion Sort-----------|");
                            disp.display(obj.array,obj.n);
                            break;     
                case  6:    
                            System.out.println("\n|----------Before Selection Sort-----------|");
                            disp.display(obj.array,obj.n);
                            System.out.println("|---------Appling Selection Sort-----------|");
                            sort.selection_sort(obj.array,obj.n);
                            System.out.println("\n|-----------After Selection Sort-----------|");
                            disp.display(obj.array,obj.n);
                            break;  
                case  7:    
                            System.out.println("\n|-------Before Quick Sort [Recursive]-------|");
                            disp.display(obj.array,obj.n);
                            System.out.println("|------Appling Quick Sort [Recursive]-------|");
                            sort.quick_sort_rc(obj.array,0,(obj.n-1));
                            System.out.println("\n|--------After Quick Sort [Recursive]-------|");
                            disp.display(obj.array,obj.n);
                            break; 
                case  8:    
                            System.out.println("\n|-----------Before Quick Sort------------|");
                            disp.display(obj.array,obj.n);
                            System.out.println("|----------Appling Quick Sort------------|");
                            sort.quick_sort(obj.array,obj.n);
                            System.out.println("\n|------------After Quick Sort------------|");
                            disp.display(obj.array,obj.n);
                            break;    
                case  9:    
                            System.out.println("\n|-------Before Merge Sort [Recursive]-------|");
                            disp.display(obj.array,obj.n);
                            System.out.println("|------Appling Merge Sort [Recursive]-------|");
                            sort.merge_sort_rc(obj.array,0,(obj.n-1));
                            System.out.println("\n|--------After Merge Sort [Recursive]-------|");
                            disp.display(obj.array,obj.n);
                            break;    
                case 10:    
                            System.out.println("\n|-----------Before Merge Sort-------------|");
                            disp.display(obj.array,obj.n);
                            System.out.println("|-----------Appling Merge Sort-----------|");
                            sort.merge_sort(obj.array, obj.n);
                            System.out.println("\n|-------------After Merge Sort------------|");
                            disp.display(obj.array,obj.n);
                            break;  
                case 11: 
                            System.out.println("\n------------------------------------------|");
                            System.out.println("|1. Max Heap Sort.                        |");
                            System.out.println("|2. Min Heap Sort.                        |");
                            System.out.println("|3. Back [ <--- ].                        |");
                            System.out.println("------------------------------------------|");
                            System.out.print("\nEnter your choice : ");
                            x=sc.nextInt();
                            
                            if(x==1)
                            {
                                System.out.print("\nEnter the number of element: ");
                                obj.m=sc.nextInt();
                                sort.qm=obj.m;
                                obj.array2=new int[obj.m+1];
                                System.out.print("\nEnter the root element [1] : ");
                                obj.array2[1]=sc.nextInt();
                                for(i=2;i<=obj.m;i++)
				                {
					                System.out.print("\nEnter the element ["+i+"] : ");
					                item=sc.nextInt();
					                sort.create_max_heap(obj.array2, i, item);
				                }
				                
				                System.out.println("\n|-----------Before Heap Sort-------------|");
                                disp.display1(obj.array2,obj.m);
                                System.out.println("|---------Appling Max Heap Sort----------|");
                                
                                for(i=obj.m;i>1;i--)
					                sort.del_max_heap(obj.array2, i);
                                
                                System.out.println("\n|-------------After Heap Sort------------|");
                                disp.display1(obj.array2,obj.m);
				                
                            }
                            else if(x==2)
                            {
                                System.out.print("\nEnter the number of element: ");
                                obj.m=sc.nextInt();
                                sort.qm=obj.m;
                                obj.array2=new int[obj.m+1];
                                System.out.print("\nEnter the root element [1] : ");
                                obj.array2[1]=sc.nextInt();
                                for(i=2;i<=obj.m;i++)
				                {
					                System.out.print("\nEnter the element ["+i+"] : ");
					                item=sc.nextInt();
					                sort.create_min_heap(obj.array2, i, item);
				                }
				                
				                System.out.println("\n|-----------Before Heap Sort-------------|");
                                disp.display1(obj.array2,obj.m);
                                System.out.println("|---------Appling Min Heap Sort----------|");
                                
                                for(i=obj.m;i>1;i--)
					                sort.del_min_heap(obj.array2, i);
                                
                                System.out.println("\n|-------------After Heap Sort------------|");
                                disp.display1(obj.array2,obj.m);
                            }
                            break;                                                                             
                case 12:    
                            System.out.println("\n|-----------Before Shell Sort-------------|");
                            disp.display(obj.array,obj.n);
                            System.out.println("|-----------Appling Shell Sort-----------|");
                            sort.shell_sort(obj.array, obj.n);
                            System.out.println("\n|-------------After Shell Sort------------|");
                            disp.display(obj.array,obj.n);
                            break;  
                case 13:    
                            System.out.print("\nEnter the highest length of the number: ");
                            len=sc.nextInt();
                            System.out.println("\n\n|-----------Before Radix Sort-------------|");
                            disp.display(obj.array,obj.n);
                            System.out.println("|-----------Appling Radix Sort-----------|");
                            sort.radix_sort(obj.array, obj.n, len);
                            System.out.println("\n|-------------After Radix Sort------------|");
                            disp.display(obj.array,obj.n);
                            break;                                                  
                case 14:
                            System.out.println("\n|--------------------Exited--------------------|\n");
                            return ;     
            }
        }                       
    } 
}
