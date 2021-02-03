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

int main(){
    cout<<reverseWord("Akash");
}