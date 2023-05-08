#include <stdio.h>
#include <stdlib.h>

void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void quicksort(int arr[],int low,int high){
    int i,j,pivot;
    if(low<=high){
        i=low;
        j=high;
        pivot=low;
        while(i<j){
            while(arr[i]<=arr[pivot] && i<=high){
                i++;
            }
            while(arr[j]>arr[pivot] && j>=low){
                j--;
            }
            if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=arr[pivot];
            }
        }
                int temp=arr[pivot];
                arr[pivot]=arr[j];
                arr[j]=temp;
        
        quicksort(arr,low,j-1);
        quicksort(arr,j+1,high);
    }
}

void merging(int arr[], int low, int mid, int high){
    int i, j, k;
    int b[1000];
    for(i = low, j = mid + 1, k = low; i <= mid && j <= high; k++){
        if(arr[i] <= arr[j]){
            b[k] = arr[i++];
        }
        else{
            b[k] = arr[j++];
        }
    }
    while(i <= mid){
        b[k++] = arr[i++];
    }
    while(j <= high){
        b[k++] = arr[j++];
    }
    for(k = low; k <= high; k++){
        arr[k] = b[k];
    }
}
void mergesort(int arr[],int low,int high){
    if(low<high){
    int mid = (low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merging(arr,low,mid,high);
    }
}

void heapify(int arr[],int n,int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;
    if(arr[left]>arr[largest] && left<n){
        largest=left;
    }
    if(arr[right]>arr[largest] && right<n){
        largest=right;
    }
    if(largest!=i){
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
    }
}
void heapsort(int arr[],int n){
    for(int i=n/2 -1;i>=0;i--){  //building
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){   //deleting
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,i,0);
    }
}

void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>arr[temp]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
            min=j;
            }
        }
        if(min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}
int main(){
    int n;
    printf("enter the value of n ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array ");
    for(int i=0;i<n;i++){  
    scanf("%d",&arr[i]);
    }
    // bubblesort(arr,n);
    // quicksort(arr,0,n-1);
    //mergesort(arr,0,n-1);
    //heapsort(arr,n);
    //insertionsort(arr,n);
    selectionsort(arr,n);
    printf("sorted ");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}