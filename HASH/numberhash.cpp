#include<bits/stdc++.h>
using namespace std;
// number hashing 
int main() {
	cout<<"enter the size of array ";
	int size;
	cin>>size;
	int arr[size];
	//taking inputs in array
	for(int i=0;i<size;i++){
	    cout<<"enter the "<<i+1<<" element";
	    cin>>arr[i];
	}
	//pre compute
	int hash[size+1]= {0};
	for(int i=0; i<size; i++) {
		hash[arr[i]]++;
	}

	cout<<"enter the number of inputs ";
	int q;
	cin>>q;
	while(q--) {
		int c;
		cout<<"enter the number ";
		cin>>c;
		//fetch
		cout<<"the count of "<<c<<" is "<<hash[c]<<endl;

	}
}