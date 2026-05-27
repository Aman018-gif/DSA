#include<bits/stdc++.h>
using namespace std;

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
	int n = size;
	
	//selection sort
	
	for(int i =0;i<=n-2;i++){
	    
	    int min= arr[i];
	    int min_index = i;
	    for(int j=i;j<=n-1;j++){
	       min_index=min>arr[j]?j:min_index;
	       min = arr[min_index];
	    }
	    int c;
	    c=arr[i];
	    arr[i]=arr[min_index];
	    arr[min_index]=c;
	}
	
	//print sorted array after selection sort
	for(int i=0;i<=n-1;i++){
	    cout<<arr[i]<<" ";
	}
	
}



// from striver a2z dsa sheet

// class Solution {
// public:
//     vector<int> selectionSort(vector<int>& nums) {
//         for(int i=0;i<=nums.size()-2;i++){
//             int min_element = nums[i];
//             int min_element_index = i;
//             for(int j=i;j<=nums.size()-1;j++){
//                 min_element_index=min_element>nums[j]?j:min_element_index;
//                 min_element=nums[min_element_index];
//             }
//             int c;
//             c =nums[i];
//             nums[i]=nums[min_element_index];
//             nums[min_element_index]=c;
//         }
//         return nums;
//     }
// };