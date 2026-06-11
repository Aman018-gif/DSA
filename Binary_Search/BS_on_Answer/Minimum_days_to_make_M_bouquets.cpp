// Minimum days to make M bouquets
// Problem Statement: You are given 'N’ roses and you are also given an array 'arr' where 'arr[i]' denotes that the 'ith' rose will bloom on the 'arr[i]th' day. You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet. Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.
// Brute Force Approach-Algorithm
// If the total number of flowers required to make all bouquets is more than the flowers available, it is not possible to make the bouquets. So, return -1.
// Loop through each day starting from the earliest bloom day to the latest bloom day to test all possible answers.
// For each day, check if it's possible to make the required number of bouquets using the flowers that have bloomed by that day. If yes, return that day as the answer.
// If no suitable day is found after checking all possibilities, it means it's impossible to make the bouquets. So, return -1.
// Time Complexity: O((max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
// Space Complexity : O(1) as we are not using any extra space to solve this problem.
// Optimal Approach-Algorithm
// If m*k > arr.size: This means we have insufficient flowers. So, it is impossible to make m bouquets and we will return -1.
// Next, we will find the maximum element i.e. max(arr[]), and the minimum element i.e. min(arr[]) in the array.
// Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to min(arr[]) and the high will point to max(arr[]).
// Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula: mid = (low+high) // 2 ( ‘//’ refers to integer division)
// Eliminate the halves based on the value returned by possible(): We will pass the potential answer, represented by the variable 'mid' (which corresponds to a specific day), to the 'possible()' function.
// If possible() returns true: On satisfying this condition, we can conclude that the number ‘mid’ is one of our possible answers. But we want the minimum number. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
// Otherwise, the value mid is smaller than the number we want. This means the numbers greater than ‘mid’ should be considered and the right half of ‘mid’ consists of such numbers. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
// Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.
// Time Complexity: O(1) O(log(max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
// Space Complexity : O(h)O(1) as we are not using any extra space to solve this problem.
class Solution {
public:
    bool check(vector<int>& bloomDay,int m,int k ,int days){
        int cnt=0;
        int no_of_bloom_days=0;
        for(int i=0;i<=bloomDay.size()-1;i++){
            if(bloomDay[i]<=days) cnt++;
            else{
                no_of_bloom_days+=cnt/k;
                cnt=0;
            }
        }
        no_of_bloom_days+=cnt/k;
        if(no_of_bloom_days>=m) return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL *m*k>bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid = low + (high - low)/2;
            if(check(bloomDay,m,k,mid)) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};