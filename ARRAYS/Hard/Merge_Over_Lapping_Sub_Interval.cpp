// Merge Intervals
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
// 1.Brute Force - Sort and then on the basics of each element chekc if that comes in overlapping and increases the end via max and do this for all using 2 Loop;
// TC - O(NlogN) + O(N^2) (For Sorting and 2 Loops)
// Sc - O(N)
// 2. Optimal-
// Why 2 Loops  cehck it in oen as soon foudn not overlooping make that as a new interval and other max thing is same and also do not forget to sort in starting.
// TC - O(NlogN) + O(N) (For Sorting and 1 Loops)
// Sc - O(N)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        int n = interval.size();
        sort(interval.begin(),interval.end());
        int start = interval[0][0];
        int end = interval[0][1];
        vector<vector<int>>ans;
        for(int i=0;i<=n-1;i++){
            if(interval[i][0]<=end){
                end = max(end,interval[i][1]);
            }
            else{
                ans.push_back({start,end});
                start = interval[i][0];
                end = interval[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};