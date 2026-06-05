// Implement Upper Bound
// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.
// What is Upper Bound?
// The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.
// The upper bound is the smallest index, ind, where arr[ind] > x.
// Note Sab kuch same hai lower bound jaise bas >= ki jaagh = lga dena
//ok
class Solution{
public:
    int upperBound(vector<int>& nums, int target) {
        int ans =nums.size();
        int low =0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>target){
                ans = mid;
                high = mid-1;
                }
            else low = mid+1;
        }
        return ans;
    }
};