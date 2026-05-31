// Replace Elements with Greatest Element on Right Side
// Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.
// After doing so, return the array.
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max1 = -1;
        int n =arr.size();
        for(int i=n-1;i>=0;i--){
                int temp;
                temp = arr[i];
                arr[i]=max1;
                max1 =max(max1,temp);
    }
        return arr;}
};