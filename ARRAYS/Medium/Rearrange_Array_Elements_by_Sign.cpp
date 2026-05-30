// Rearrange Array Elements by Sign
// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
// You should return the array of nums such that the array follows the given conditions:
// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
// 1.Brute Force Approach
// I iterate through the array, separating the positive and negative elements into two distinct lists while maintaining their original order. Then, I loop through these positive and negative elements to merge them back into the original array, ensuring that the positive elements are placed at even indices (0, 2, 4).
// TC - O(3N/2)
// SC - O(N) (As storing all Postives and Negatives) 
// 2.Optimal Approach
// To optimize the solution to O(n) time complexity using a single iteration, we can use an auxiliary array to store the result. As we traverse the original array, whenever we encounter a positive element, we place it at the next available even index of the result array. Conversely, when we encounter a negative element, we place it at the next available odd index.
// TC - O(N)
// SC - O(N) (As storing all Postives and Negatives) 
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        int positive=0;
        int negative=1;
        for(int i=0;i<=nums.size()-1;i++){
            if(nums[i]>=0){
                ans[positive]=nums[i];
                positive+=2;
            }
            else{
                ans[negative]=nums[i];
                negative+=2;
            }
        }
        return ans;
    }
};


// Variety 2
// Since leftover elements must be appended to the end, the number of positive and negative elements is clearly unequal. This means the optimal solution from Variety 1 cannot be applied, so we fall back to a brute-force approach using extra space. We alternate elements up to the size of the smaller group, and then use a separate loop to append the remaining leftover elements at the end.
// TC O(N) + O(min(positives,negatives)) + O(Left Overs)
// Here Talking about this O(min(positives,negatives)) + O(Left Overs) if all are postives or negatives min would be 0 and Left Overs would be N Hence O(min(positives,negatives)) = O(0) and O(Left Overs) = O(N) 
// Hence in worst Case the TC O(2N)
// and talking about best case is both are equal psotives and negatives i.e. N/2.
// Hence O(min(positives,negatives)) = O(N/2) and O(Left Overs) = O(0).
// The TC O(3N/2) i.e. Question reduced to variety 1 type.
// SC O(N) (As storing all Postives and Negatives) 
vector<int> alternateNumbers(vector<int>&a) {
    vector<int> pos, neg;
    int n = a.size();
    
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) {
            pos.push_back(a[i]);
        }
        else {
            neg.push_back(a[i]);
        }
    }

    if(pos.size() > neg.size()) {
        for(int i = 0; i < neg.size(); i++) {
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        
        int index = neg.size() * 2;
        for(int i = neg.size(); i < pos.size(); i++) {
            a[index] = pos[i];
            index++;
        }
    }
    else {
        for(int i = 0; i < pos.size(); i++) {
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        
        int index = pos.size() * 2;
        for(int i = pos.size(); i < neg.size(); i++) {
            a[index] = neg[i];
            index++;
        }
    }
    
    return a; 
}