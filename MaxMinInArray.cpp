#include<iostream>
using namespace std;

struct mpair{
    int max;
    int min;
};

struct mpair findMaxMin(int arr[],int n){
    struct mpair myPair;
    
    if(n==1){
        myPair.max=arr[0];
        myPair.min=arr[0];
        return myPair;
    }

    if(arr[0]>arr[1]){
        myPair.max=arr[0];
        myPair.min=arr[1];
    }
    else{
         myPair.max=arr[1];
        myPair.min=arr[0];
    }

    for(int i=2;i<n;i++){
        if(arr[i]>myPair.max)
            myPair.max = arr[i];
        else if(arr[i]<myPair.min)
            myPair.min = arr[i];
    }
    return myPair;
}

int main(){
    int arr[] = {11,55,22,6,33,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    struct mpair x = findMaxMin(arr,size);
    cout<<"\n Min = "<<x.min;
    cout<<"\n Max = "<<x.max;    
    return 0;
}