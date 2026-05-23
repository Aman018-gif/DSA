#include<bits/stdc++.h>
using namespace std;
//only lowercase letters
int main() {
	cout<<"enter a string ";
	string s;
	cin>>s;
	//pre compute
	int hash[26]= {0};
	for(int i=0; i<s.size(); i++) {
		hash[s[i]-'a']++;
	}

	cout<<"enter the number of inputs ";
	int q;
	cin>>q;
	while(q--) {
		char c;
		cout<<"enter the character ";
		cin>>c;
		//fetch
		cout<<"the count of"<<c<<"is "<<hash[c-'a']<<endl;

	}
}