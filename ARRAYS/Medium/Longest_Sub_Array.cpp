// Longest Consecutive Sequence
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.
// 1.Brute Force Approach
// Use 2 Loop and check and get the longest sequence/
// TC - O(N^2) 
// SC - O(1)
// 2.Better Approach
// Idea: A better approach is to first sort the given array. Then, we initialize a few tracking variables: a current sequence counter, a longest sequence counter, and a variable to store the last visited element. Next, we iterate through the array. During the iteration, we check if the current element minus one is equal to the value stored in our last visited element variable. If it is, we increment the current sequence counter and update the last visited element to be the current element. If the current element is exactly the same as the last visited element, we do nothing and simply skip it. Otherwise, if the current element is not consecutive to the last visited element, we reset our tracking variables.
// TC - O(NlogN) + O(N)
// SC - O(1)
// 3.Optimal Approach
// using an unordered set (assuming no collisons)
// TC - O(3N)
// SC - O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        unordered_set<int> st;
        for(int i=0;i<=nums.size()-1;i++){
            st.insert(nums[i]);
        }
        int cnt =0;
        int longest=0;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                cnt=1;
                while(st.find(it+1)!=st.end()){
                    cnt++;
                    it++;
                }
                longest=max(cnt,longest);
            }
        }
        return longest;
    }
};