int linearsearch(int arr[],int n, int element){
    for(int i=0;i<n;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
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
    int arr[]={7,9,2,1,4,3,5};
    int n = sizeof(arr)/sizeof(int);
    int element =1;
    int j = linearsearch(arr,n,element);
    int k = binarysearch(arr,n,element);
    printf("The element %d was found at %d\n",element,j);
    printf("The element %d was found at %d",element,k);
}