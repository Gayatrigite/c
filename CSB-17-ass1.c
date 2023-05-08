// WAP to implement Quick, Merge, and Heap Sort on 1d array of employee structure
//(contains employee_name, emp_no, emp_salary), with keys as emp_no. And count the number of swap performed

#include <stdio.h>
#include <stdlib.h>
struct employee{
    int emp_no;
    int emp_salary;
    char emp_name[50];
};
int count = 0;
void swap(struct employee l[],int i,int j){
    struct employee temp = l[i];
    l[i] = l[j];
    l[j] = temp;
    count++;
}
void bubblesort(struct employee l[],int n){
    struct employee temp;
    for(int i=0; i<n; i++){ //'i' is used to determine the number of iterations of the outer loop(iterates n times)
        for(int j=0; j<n-1; j++){ //'j' is used to compare each pair of adjacent elements in the array. inner loop iterates n-1 times as the last element is already sorted after each iteration of outer loop
            if(l[j].emp_no > l[j+1].emp_no){
                swap(l,j,j+1);
            }
        }
    }
}
void quicksort(struct employee l[],int low,int high){
    int i,j,pivot;
    struct employee temp;
    pivot = low;
    i = low;
    j = high;
    while(i<j){
        if(l[i].emp_no < l[pivot].emp_no && i<high){
            i++;
        }
        if(l[j].emp_no > l[pivot].emp_no){
            j--;
        }
        if(i<j){
          swap(l,i,j);
        }
        struct employee temp1;//'if' condition of the inner loop, we are comparing two 'struct stud' elements based on their 'rollno' member.Therefore, in order to swap the two 'struct stud' elements, we need to use a temporary variable of type 'struct stud'
        swap(l,pivot,j);

        quicksort(l,low,j-1);
        quicksort(l,j+1,high);
    }
}
void merging(struct employee l[],int low,int mid,int high){
    int i,j,k;
    struct employee b[10];
    for(i=low,j=mid+1,k=low;i<=mid && j<high;k++){
        if(l[i].emp_no<=l[j].emp_no){
        b[k].emp_no=l[i++].emp_no;
        }
        else{
            b[k].emp_no=l[j++].emp_no;
        }
    }
    while(i <= mid)    
      b[k++].emp_no = l[i++].emp_no;

   while(j <= high)   
      b[k++].emp_no = l[j++].emp_no;

   for(k = low; k <= high; k++)
      l[k].emp_no = b[k].emp_no;
}
void mergesort(struct employee l[],int low, int high) {
   int mid;  
   if(low < high) {
      mid = (low + high) / 2;
      mergesort(l,low, mid);
      mergesort(l,mid+1, high);
      merging(l,low, mid, high);
   } else { 
      return;
   }   
}

void heapify(struct employee l[],int n,int i){
    int largest,temp;
    largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && l[left].emp_no>l[largest].emp_no){
        largest=left;
    }
     if(right<n && l[right].emp_no>l[largest].emp_no){
        largest=right;
    }
    if(largest!=i){
        swap(l,i,largest);
        heapify(l,n,largest);
    }
}
void heapsort(struct employee l[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(l,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(l,0,i);
        heapify(l,i,0);
    }
}
void Print(struct employee l[],int n){
    printf("\n\nName\tsalary\temp no\n");
    for(int i=0;i<n;i++){
        printf("%s\t%d\t%d\n",l[i].emp_name,l[i].emp_salary,l[i].emp_no);
    }
}
int main(){
    struct employee l[10];
    int n; 
    printf("enter number of records: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\n Enter employee record %d :",i+1);
        printf("\n Enter name: ");
        scanf("%s",&l[i].emp_name);
        
        printf("\n Enter salary: ");
        scanf("%d",&l[i].emp_salary);
    
        printf("\n Enter emp no: ");
        scanf("%d",&l[i].emp_no);
        
    }
    printf("Before sorting: ");
    printf("\n\nName\tsalary\temp no\n");
    for(int i=0;i<n;i++){
        printf("%s\t%d\t%d\n",l[i].emp_name,l[i].emp_salary,l[i].emp_no);
    }
    printf("After sorting with bubble sort: ");
    bubblesort(l,n);
    Print(l,n);
    printf("After sorting with Quick sort: ");
    quicksort(l,0,n-1);
    Print(l,n);
    printf("After sorting with Merge sort: ");
    mergesort(l,0,n-1);
    Print(l,n); 
    printf("After sorting with Heap sort: ");
    heapsort(l,n);
    Print(l,n);
}