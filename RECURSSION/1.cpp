#include<bits/stdc++.h>
using namespace std;
int sum(int n){
    if(n<1) return 0;
    return n+sum(n-1);
}

int fact(int n){
    if(n==1) return 1;
    return n*fact(n-1);
}

int fibo(int n){
    if(n<2) return n;
    return fibo(n-1)+fibo(n-2);
}
void swap(int *f, int *s){
    *f=(*f)^(*s);
    *s=(*f)^(*s);
    *f=(*f)^(*s);
}
void reverse(int a[],int l,int r){
    if(l>=r) return;
    swap(&a[l],&a[r]);
    reverse(a,l+1,r-1);
}

void reverse1(int a[],int i, int n){
    if(i>=n/2) return;
    swap(&a[i],&a[n-i-1]);
    reverse1(a,i+1,n);
}

bool check_palindrome(string s,int i){
    int len = s.length();
    if(i>=len/2) return true;
    if(s[i]!=s[len-i-1]) return false;
    return check_palindrome(s,i+1);

}

int main(){
    int n;
    //revusrrion(1,3);
    //cout<<fibo(6);
    // int a[5]={1,2,3,4,5};
    // reverse1(a,0,5);
    // for(int i=0;i<5;i++){
    //     cout<<a[i] <<" ";
    // }
    string s = "MADAM";
    cout<<check_palindrome(s,0);
    return 0;
}






















