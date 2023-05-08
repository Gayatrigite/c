#include <stdio.h>
#include <stdlib.h>
// struct myArray{
//     int total_size;
//     int used_size;
//     int *ptr;
// };
// void create(struct myArray * a,int tsize,int usize){
//     a->total_size = tsize;
//     a->used_size = usize;
//     a->ptr = (int *)malloc(tsize*sizeof(int));
// }
// void show(struct myArray *a){
//     for(int i=0;i<a->used_size;i++){
//         printf("%d\n",a->ptr[i]);
//     }
// }
// void set(struct myArray *a){
//     int n;
//     for(int i=0;i<a->used_size;i++){
//     printf("Enter the nos %d :",i);
//     scanf("%d", &n);
//     (a->ptr)[i] = n;
//     }
// }
// int main() {
//     struct myArray marks;
//     create(&marks,10,2);
//     set(&marks);
//     show(&marks);
//     return 0;
// }

// traverse, insert, delete and search in array
// void display(int arr[],int n){
//     for(int i=0;i<n;i++){
//         printf("%d\n",arr[i]);
//     }
// }
// int indinsert(int arr[],int n,int element,int index, int capacity){
//     if(n>=capacity){
//         return -1;
//     }
//     for(int i=n-1;i>=index;i--){
//         arr[i+1]=arr[i];
//     }
//     arr[index] = element;
//     return 1;
// }
// void inddelete(int arr[],int n,int index){
//     for(int i=index;i<n-1;i++){
//         arr[i]=arr[i+1];
//     }
// }
// int main(){
//     int arr[100] = {7,8,23,27,88};
//     printf("traversal\n");
//     display(arr,5);
//     indinsert(arr,5,45,4,100);
//     printf("insert\n");
//     display(arr,6);
//     printf("delete\n");
//     inddelete(arr,5,2);
//     display(arr,4);
// }

//Both searchings are imp
//LinearSearch - BigO(n)
int linearsearch(int arr[],int n,int element){
    for(int i=0;i<n;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
//BinarySearch - BigO(logn) coz here we are converging the array
int binarysearch(int arr[],int n,int element){
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(element==arr[mid]){
          return mid;
        }
        if(element>arr[mid]){
          low=mid+1;
        }
        else{
          high=mid-1;
        }
    }
    return -1;
}
int main(){
    //int arr[] = {7,5,3,9,4,1};
    int arr[] = {1,3,7,8,11,56,89}; //for binearysearch array must be sorted
    int n = sizeof(arr)/sizeof(int);
    int element = 11;
    int j = linearsearch(arr,n,element);
    int k = binarysearch(arr,n,element);
    printf("The element %d was found at %d\n",element,j);
    printf("The element %d was found at %d",element,k);
}