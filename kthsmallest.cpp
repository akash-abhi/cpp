#include<iostream>
#include<algorithm>
using namespace std;


int kthSmallest(int arr[], int n, int k) {
    sort(arr,arr+n);
    return arr[k-1];
   
}

int main(){
    int arr[] = {7,10,4,3,20,15};

    cout<<kthSmallest(arr,6,3);
}

