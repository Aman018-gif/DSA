// Capacity to Ship Packages within D Days
// Problem Statement: You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days. The weights of the packages are given in an array 'of weights'. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship. Find out the least-weight capacity so that you can ship all the packages within 'd' days .
// Optimal Approach
// Algorithm
// We want to find the minimum ship capacity that allows shipping all packages within the given number of days. The capacity must be at least the heaviest package because you can’t split a package. At the same time, the capacity can be at most the sum of all packages (if you ship everything in one day). So the answer lies between these two extremes. Using binary search on this range lets us efficiently find the smallest capacity that works. For each candidate capacity, we check if it’s possible to ship all packages within the given days by greedily accumulating package weights until we reach capacity, then moving to the next day.
// Set the lower bound as the maximum weight in the packages.
// Set the upper bound as the sum of all package weights.
// While the lower bound is less than or equal to the upper bound, do:
// Pick the middle value between lower and upper bounds as the candidate capacity.
// Simulate shipping with this capacity: accumulate package weights until capacity is reached, then count a day and reset accumulation.
// If the number of days used is within the allowed days, move the upper bound down to try smaller capacities.
// If the number of days exceeds the allowed days, increase the lower bound to try larger capacities.
// Return the lower bound when the search finishes as the minimum capacity needed.
// Time Complexity: O(N * log(S)), where N is number of packages and S is the search space (sum_weights - max_weight). Each binary search step takes O(N), repeated O(log S) times.
// Space Complexity: O(1), constant extra space used.
class Solution {
public:
    bool check(vector<int>& weights, int days,int capacity){
        int sum =0;
        int cnt=0;
        for(int i=0;i<=weights.size()-1;i++){
            sum+=weights[i];
            if(sum>capacity){
                cnt++;
                sum = weights[i];
            }
        }
        if(sum) cnt++;
        if(cnt<=days) return true;
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(weights,days,mid)) high = mid -1;
            else{
                low = mid +1;
            }
        }
        return low;
    }
};