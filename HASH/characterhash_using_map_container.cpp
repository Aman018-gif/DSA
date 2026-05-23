#include<bits/stdc++.h>
using namespace std;

int main() {
	cout<<"enter a string ";
	string s;
	cin>>s;
	//pre compute
	map<char,int>mpp;
	for(int i=0; i<s.size(); i++) {
		mpp[s[i]]++;
	}

	cout<<"enter the number of inputs ";
	int q;
	cin>>q;
	while(q--) {
		char c;
		cout<<"enter the character ";
		cin>>c;
		//fetch
		cout<<"the count of "<<c<<" is "<<mpp[c]<<endl;

	}
}