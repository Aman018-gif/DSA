// Kth Missing Positive Number
// Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer 'k'. Find the 'kth' positive integer missing from 'vec'.
// Optimal Approach-Algorithm
// We cannot apply binary search on the answer space here as we cannot assure which missing number has the possibility of being the kth missing number. That is why, we will do something different here. We will try to find the closest neighbors (i.e. Present in the array) for the kth missing number by counting the number of missing numbers for each element in the given array.
// Algorithm
// Start by setting two markers: one at the beginning and one at the end of the list.
// Keep checking the middle position between the two markers by taking their average.
// Count how many numbers are missing up to that middle position by subtracting the expected number from the actual number found at that point.
// If the number of missing values is less than the desired position, move your focus to the right side of the list by shifting the beginning marker ahead.
// If not, move your focus to the left side by shifting the end marker backward.
// Once you've narrowed down the search and exited the loop, return the final answer by adding the desired position to the last marker you checked (plus one).
// Time Complexity: O(logn), used for typical binary search
// Space Complexity: O(1), no extra space used
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing(arr.size());
        for(int i =0;i<=arr.size()-1;i++){
            missing[i]= arr[i]-(i+1);
        }
        int low =0;
        int high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(missing[mid]<k) low = mid+1;
            else high = high = mid-1;
        }
        if(high<0) return k;
        return arr[high] + (k-missing[high]);
    }
};