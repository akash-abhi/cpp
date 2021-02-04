#include<iostream>
using namespace std;

struct mpair{
    int max;
    int min;
};


//method 1 : linear searching
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


//method 2 : by recursion
struct mpair findbyRec(int arr[],int low,int high){
    struct mpair minmax,ml,mr;

    //for 1 element
    if(low==high){
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
    }
    
    //for 2 element
    if(high==low+1){
        if(arr[low]>arr[high]){
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        else{
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    //for >2 elements
    int mid = (low+high)/2;
    ml = findbyRec(arr,low,mid);
    mr = findbyRec(arr,mid+1,high);

    //comparision for minimum among left and right
    if(ml.min < mr.min){
        minmax.min = ml.min;
    }
    else{
        minmax.min = mr.min;
    }

    //comparision for maximum among left and right
    if(ml.max > mr.max){
        minmax.max = ml.max;
    }
    else{
        minmax.max = mr.max;
    }
    return minmax;
}

//method 3 : by comparision in pairs
struct mpair getMinMax(int arr[], int n) 
{ 
    struct mpair minmax;     
    int i; 
     
    // If array has even number of elements 
    // then initialize the first two elements 
    // as minimum and maximum 
    if (n % 2 == 0) 
    { 
        if (arr[0] > arr[1])     
        { 
            minmax.max = arr[0]; 
            minmax.min = arr[1]; 
        } 
        else
        { 
            minmax.min = arr[0]; 
            minmax.max = arr[1]; 
        } 
         
        // Set the starting index for loop 
        i = 2; 
    } 
     
    // If array has odd number of elements 
    // then initialize the first element as 
    // minimum and maximum 
    else
    { 
        minmax.min = arr[0]; 
        minmax.max = arr[0]; 
         
        // Set the starting index for loop 
        i = 1; 
    } 
     
    // In the while loop, pick elements in 
    // pair and compare the pair with max 
    // and min so far 
    while (i < n - 1) 
    {         
        if (arr[i] > arr[i + 1])         
        { 
            if(arr[i] > minmax.max)     
                minmax.max = arr[i]; 
                 
            if(arr[i + 1] < minmax.min)         
                minmax.min = arr[i + 1];     
        } 
        else       
        { 
            if (arr[i + 1] > minmax.max)     
                minmax.max = arr[i + 1]; 
                 
            if (arr[i] < minmax.min)         
                minmax.min = arr[i];     
        } 
         
        // Increment the index by 2 as 
        // two elements are processed in loop 
        i += 2; 
    }         
    return minmax; 
} 
int main(){
    int arr[] = {11,55,22,6,33,8};
    int size = sizeof(arr)/sizeof(arr[0]);
   
  //  struct mpair x = findMaxMin(arr,size);
   // struct mpair x = findbyRec(arr,0,size-1);
   
   struct mpair x = getMinMax(arr,size);
   
    cout<<"\n Min = "<<x.min;
    cout<<"\n Max = "<<x.max;    
    return 0;
}