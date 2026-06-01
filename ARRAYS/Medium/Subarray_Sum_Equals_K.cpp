// Subarray Sum Equals K
// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.
// 1. Brute Force 
// All Generate and find count 
// TC- O(N^3)
// 2.Better Approach 
// TC- O(N^2)
// 3.Optimal Approach
// Uses Idea of Prefix Sum
// TC - O(N * log(N)) if ordered map
// SC- O(N) (worst case all prefix sum diferent)
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt =0;
        int prefix_sum=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<=nums.size()-1;i++){
            prefix_sum+=nums[i];
            int rem = prefix_sum-k;
            cnt+=mpp[rem];
            mpp[prefix_sum]+=1;
        }
        return cnt;
    }
};