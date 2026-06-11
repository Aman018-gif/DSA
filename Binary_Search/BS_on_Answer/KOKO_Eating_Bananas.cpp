// Koko Eating Bananas
// Problem Statement: A monkey Koko is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.
// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.
// Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.
// Optimal Approach
// Algorithm
// The naive method checks every speed, which is slow if the piles are large. But the possible answer space (from 1 to the maximum pile size) is sorted, meaning if a certain speed works, then all higher speeds will also work. This allows us to apply Binary Search on the answer space to efficiently find the minimum speed at which Koko can finish the bananas within the given hours.
// First, identify the largest pile size since the eating speed cannot be more than that.
// Set the search range with the lowest speed as 1 and the highest speed as the maximum pile size.
// Use binary search within this range to check possible speeds.
// At each step, take the middle value as the current speed and calculate how many hours it would take to finish all piles at this speed.
// If the total hours are less than or equal to the allowed hours, this speed is a candidate, so try to see if a smaller speed also works by moving left.
// If the total hours exceed the allowed hours, then the speed is too slow, so move right to try higher speeds.
// Continue this process until the range closes, and the smallest valid speed found will be the answer.
// Time Complexity: O(N*log(max(a[]))), we apply binary search on our search space to reduce it into half at every step.
// Space Complexity: O(1), since the algorithm does not use any additional space or data structures.
class Solution {
public:
    int check(vector<int>& piles, int h,int mid){
        int sum =0;
        for(int i =0;i<=piles.size()-1;i++){
            sum += ceil((double)piles[i] / mid);
            if(sum>h) return 2;
        }
        if(sum==h) return 1;
        return 0;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
      int low = 1;
      int high = *max_element(piles.begin(),piles.end());
      int ans = high;
      while(low<=high){
        int mid = low+ (high-low)/2;
        if(check(piles, h,mid)==2) low = mid+1;
        else{
            ans = mid;
            high = mid-1;
        }
      }
      return ans;  
    }
};