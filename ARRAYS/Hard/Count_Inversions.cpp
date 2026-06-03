// Count inversions in an array
// Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).
// Inversion of an array: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].
// 1.Brute Force Approach 
// An inversion in an array is defined as a pair of indices (i, j) such that i < j and a[i] > a[j]. This measures how far the array is from being sorted. To count inversions, the brute force way is to compare every element with all elements to its right and increment the counter whenever we find an inversion.
// Initialize a counter cnt = 0.
// Use two nested loops:
// Outer loop runs for each element a[i].
// Inner loop checks all elements a[j] where j > i.
// If a[i] > a[j], increment cnt.
// After traversing all pairs, return cnt as the number of inversions.
// Time Complexity: O(N^2)
// Space Complexity: O(1)
int numberOfInversions(vector<int>& a, int n) {
    int cnt = 0; // Initialize inversion count
    // Check all pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) cnt++; // Increment count if inversion found
        }
    }
    return cnt; // Return total inversions
}
// 2. Optimal Approach - Using Merge Sort and 2 Pointer TEchnique;
// The brute force approach compares all pairs, but that takes O(N2) time. We can optimize this using the merge sort algorithm. While merging two sorted halves, if an element in the left half is greater than an element in the right half, then all remaining elements in the left half will also be greater than that right element. This allows us to count multiple inversions in one step, instead of checking each pair individually.
// Apply merge sort recursively to divide the array into two halves.
// During the merge step:
// If arr[left] <= arr[right], place arr[left] into the temp array and move left++.
// Otherwise, place arr[right] into the temp array. Since arr[left] > arr[right], all elements from arr[left] to arr[mid] form inversions with arr[right]. So add (mid - left + 1) to the inversion count.
// Copy the merged elements back into the original array.
// The total inversion count is the sum of:
// Inversions in the left half
// Inversions in the right half
// Inversions across the halves (counted during merge)
// Time Complexity: O(N*logN)
// Space Complexity: O(N)
class Solution {
public:
// int cnt=0; if recommonded not to keep a global variable in interiview
    int merge(vector<int>&nums,int low,int mid,int high){
        int cnt=0;
        vector<int>temp;
        int left = low;
        int right = mid +1;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
                cnt+=mid-left+1;    
            }

        }

        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        return cnt;
    }

    int  ms(vector<int> &nums,int low,int high){
        int cnt=0;
        if(low>=high) return cnt;
        int mid = (low+high)/2;
        cnt+=ms(nums,low,mid);
        cnt+=ms(nums,mid+1,high);
        cnt += merge(nums,low,mid,high);
        return cnt;
    }
       long long int numberOfInversions(vector<int> nums) {
        int cnt =0;
        cnt = ms(nums,0,nums.size()-1);
        return cnt;
    }
};
