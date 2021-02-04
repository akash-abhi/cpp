#include<iostream>
using namespace std;

string reverseWord(string str){
    string rev;
    int len=str.length();

    while(len>0){
        rev.push_back(str[len-1]);
        len--;
    }
    return rev;
}

string reversebySwap(string str){
    int len=str.length();
    int i=0;
    while(i!=(len/2)){
        char c;
        c=str.at(i);
        str.at(i)=str.at(len-i-1);
        str.at(len-i-1)=c;
        i++;
    }

    return str;
}


int main(){
    cout<<reverseWord("Akash");
    cout<<endl;
    cout<<reversebySwap("abcd");
    
}