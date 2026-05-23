#include<bits/stdc++.h>
using namespace std;
// number hashing using map container
//can also use unorderedmap for better complexity of storing and fetching 
int main() {
	cout<<"enter the size of array ";
	int size;
	cin>>size;
	int arr[size];
	//taking inputs in array
	for(int i=0; i<size; i++) {
		cout<<"enter the "<<i+1<<" element";
		cin>>arr[i];
	}
	//pre compute
	map<int,int>mpp;
	for(int i=0; i<size; i++) {
		mpp[arr[i]]++; //if the elements alredy exists in map mpp its value will be increased by one and if does not exists then new key will be created and its value will be set to one.
	}

	cout<<"enter the number of inputs ";
	int q;
	cin>>q;
	while(q--) {
		int c;
		cout<<"enter the number ";
		cin>>c;
		//fetch
		cout<<"the count of "<<c<<" is "<<mpp[c]<<endl;

	}
}