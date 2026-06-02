// Count subarrays with given xor K
// Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.
// 1.Brute Force - Generate all Subarrays 
// TC - O(N^3)
// SC - O(1)
// 2> Better - REmove Last Loop as next XOR is just previous XOR with next element
// TC - O(N^2)
// SC - O(1)
// 3. Optimal - Using the  x = XR ^ K;
// Tracking Starting XOR;
// Total XOR is XR and required is K with . as ending element so we can in front can be have any XOR as x so yes 
// as X = XR ^ K;X = XR ^ K; XR is total XOR till now;
// TC - O(N) * O(logN)/O(1) (depends which map ordered or unordered)
// SC - O(N)
class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int XOR = 0;
        int cnt=0;
        map<int,int>hashset;
        hashset[0]=1;
        for(int i =0;i<=n-1;i++){
            XOR^=nums[i];
            int x = XOR ^ k;
            if(hashset.find(x)!=hashset.end()){
                cnt+=hashset[x];
            }
            hashset[XOR]++;
        }
        return cnt;
    }
};