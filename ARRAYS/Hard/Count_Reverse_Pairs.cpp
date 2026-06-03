// ount Reverse Pairs
// Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].
// 1.Brute Force Approach-
// The naive approach is pretty straightforward. We will use nested loops to generate all possible pairs. We know index i must be smaller than index j. So, we will fix i at one index at a time through a loop, and with another loop, we will check(the condition a[i] > 2*a[j]) the elements from index i+1 to N-1  if they can form a pair with a[i].
// Note: For a better understanding of intuition, please watch the video at the bottom of the page.
// Approach:
// The steps are as follows:
// First, we will run a loop(say i) from 0 to N-1 to select the a[i].
// As index j should be greater than index i, inside loop i, we will run another loop i.e. j from i+1 to N-1, and select the element a[j].
// Inside this second loop, we will check if a[i] > 2*a[j] i.e. if a[i] and a[j] can be a pair. If they satisfy the condition, we will increase the count by 1.
// Finally, we will return the count i.e. the number of such pairs.
// Time Complexity: O(N^2)
// Space Complexity: O(1)
int countPairs(vector<int>&a, int n) {

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > 2 * a[j]) cnt++;
        }
    }
    return cnt;
// 2.Optimal Approach-
// In order to solve this problem we will use the merge sort algorithm like we used in the problem count inversion with a slight modification of the merge() function. But in this case, the same logic will not work. In order to understand this, we need to deep dive into the merge() function.
// Why the same logic of count inversion will not work?
// The merge function works by comparing two elements from two halves i.e. arr[left] and arr[right]. Now, the condition in the question was arr[i] > arr[j]. That is why we merged the logic. While comparing the elements, we counted the number of pairs.
// But in this case, the condition is arr[i] > 2*arr[j]. And, we cannot change the condition of comparing the elements in the merge() function. If we change the condition, the merge() function will fail to merge the elements. So, we need to check this condition and count the number of pairs separately.
// Note: This process will work because arr1[1] will always be greater than arr1[0] which concludes if arr2[0] and arr2[1] are making a pair with arr1[0], they will obviously make pairs with a number greater than arr1[0] i.e. arr1[1].
// Thus before the merge step in the merge sort algorithm, we will calculate the total number of pairs each time.
// Approach:
// The steps are basically the same as they are in the case of the merge sort algorithm. The change will be just in the mergeSort() function:
// In order to count the number of pairs, we will keep a count variable, cnt, initialized to 0 beforehand inside the mergeSort().
// We will add the numbers returned by the previous mergeSort() calls.
// Before the merge step, we will count the number of pairs using a function, named countPairs().
// We need to remember that the left half starts from low and ends at mid, and the right half starts from mid+1 and ends at high.
// The steps of the countPairs() function will be as follows:
// We will declare a variable, cnt, initialized with 0.
// We will run a loop from low to mid, to select an element at a time from the left half.
// Inside that loop, we will use another loop to check how many elements from the right half can make a pair.
// Lastly, we will add the total number of elements i.e. (right-(mid+1)) (where right = current index), to the cnt and return it.
// Time Complexity: O(2N*logN)
// Space Complexity: O(N)
class Solution {
public:
    int count_reverse_pair(vector<int>&nums,int low,int mid,int high){
        int cnt =0;
        int left = low ;
        int right = mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && nums[i]>2LL*nums[right]) {right++;}
            cnt+=right - (mid+1);
        }
        return cnt;
    }


// int cnt=0; if recommonded not to keep a global variable in interiview
    void merge(vector<int>&nums,int low,int mid,int high){
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
    }

    int  ms(vector<int> &nums,int low,int high){
        int cnt=0;
        if(low>=high) return cnt;
        int mid = (low+high)/2;
        cnt+=ms(nums,low,mid);
        cnt+=ms(nums,mid+1,high);
        cnt+=count_reverse_pair(nums,low,mid,high);
        merge(nums,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int cnt =0;
        cnt = ms(nums,0,nums.size()-1);
        return cnt;
    }
};
