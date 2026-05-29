// Longest subarray with sum K
// Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.
// 1.Brute Force Approach
// Simple 3 loop generate all the possible subarray and check sum if sum is equals to given number and at last return maxium length. 
// TC - O(N^3) (Worst Case) 
// This Brute Force Approach can be optimized to TC O(N^2) by removing the inner most loop as the sum caluation in every iteration sum prev plus the next elemets so why to iterate whole array again.
// 2.Better Approach
// Hashing Approach 
// TC - (O(NlogN) this is for ordered map) or (O(N*1) in worst case O(N^2) this is for unordered map) 
// SC - O(N) (As using Hash Array)
//code
int longestsubarraywithsumk(vector<int> a,long long k){
    map<long long, int>presummap;
    long long sum =0;
    int maxlength=0;
    for(int i=0;i<=a.size()-1;i++){
        sum+=a[i];
        if(sum==k) maxlength = max(maxlength,i+1);
        // reverse enggnering
        itn rem = sum -k;
        if(presummap.find(rem) != presummap.end()){
            int len = i - presummap.find(rem);
            maxlength = max(maxlength,len);
        }
        //for zero do not have to update hash map
        if(presummap.find(sum)==presummap.end()){
            presummap[sum]=i;
        }
        return maxlength;
    }
}

// 3.Optimal Approach
// Using 2 Pointer Approach
// TC - O(2N)
// SC - O(1)
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
       int left =0;
       int right =0;
       int n =nums.size();
       long long sum = nums[0];
       int maxlen=0;
       while(right<n){
        while(left<=right &&  sum>k){
            sum-=nums[left];
            left++;
        }
        if(sum==k){
            maxlen=max(maxlen,right-left+1);
        }
        right++;
        if(right<n) sum+=nums[right];
       }
       return maxlen; 
    }
};
