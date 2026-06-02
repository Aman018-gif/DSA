// Find the repeating and missing number
// Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.
// Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.
// Note: You are not allowed to modify the original array.
// 1, Brute Force Approach - TC - O(N^2) & SC -O(1)
// 2. Better Appraoch - Hashing - TC - O(2N) & SC -O(N)
// 3. Optimal Appraoch - Type 1 Using Mathematics
// Just Read the code comments tell you eveything
// TC - O(N) & SC -O(1)
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        long long n = nums.size();
        // S - Sn = X-Y
        // S2 - S2n
        long long Sn = (n*(n+1))/2;
        long long S2n = (n*(n+1)*(2*n+1))/6;
        long long S =0;
        long long S2=0;
        for(int i=0;i<=n-1;i++){
            S+=nums[i];
            S2+=nums[i]*nums[i];
        }
        int val1= S - Sn; // val1 = X-Y
        int val2 = S2 -S2n; // val 2 = X^2-Y^2 = (X-Y)*(X+Y)
        val2/=val1; // val2 = X+Y
        int X= (val1+val2)/2;
        int Y=X-val1;
        return {X,Y};
    }
};
// 4. Optimal Appraoch - Type 2 XOR
// Just Read the code comments tell you eveything
// 1. DO XOR of all Array Elements and then with all number from 1 to N; It will give X^Y (Where X is Repeating and Y is Missing) (Note 2 Different Number Atleast Differe in 1 Bit)
// 2. Find the Diffrentitating Bit in the Number which - 1st From the Right Most;
// 3. Put them(All Array Elemnets and All Numbers from 1 to N) into 2 Clubs One Zero Club (D. Bit == 0) and another in Ones Club (D. Bit == 1) and XOTR in the Group.
// Now You have 2 Number After Doing XOR in respective Group one of them which is Repeating and another One is Missing.
// 4. Chechk for one by iterating. (Who is Whom?)
// TC - O(N) & SC -O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find repeating and missing numbers
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        
        // size of the array
        int n = nums.size(); 

        int xr = 0;

        for (int i = 0; i < n; i++) {
            // XOR of all elements in nums
            xr = xr ^ nums[i]; 
            
            // XOR of numbers from 1 to n
            xr = xr ^ (i + 1);  
        }

        // Get the rightmost set bit in xr
        int number = (xr & ~(xr - 1));

        //Group the numbers based on the differentiating bit
        // Number that falls into the 0 group
        int zero = 0; 
        
        // Number that falls into the 1 group
        int one = 0;  

        for (int i = 0; i < n; i++) {
            
            /* Check if nums[i] belongs to the 1 group
            based on the differentiating bit*/
            if ((nums[i] & number) != 0) {
                
                // XOR operation to find numbers in the 1 group
                one = one ^ nums[i];
                
            } else {
                // XOR operation to find numbers in the 0 group
                zero = zero ^ nums[i]; 
            }
        }

        // Group numbers from 1 to n based on differentiating bit
        for (int i = 1; i <= n; i++) {
            
            /* Check if i belongs to the 1 group 
            based on the differentiating bit*/
            if ((i & number) != 0) {
                
                // XOR operation to find numbers in the 1 group
                one = one ^ i; 
                
            } else {
                // XOR operation to find numbers in the 0 group
                zero = zero ^ i; 
            }
        }

        // Count occurrences of zero in nums
        int cnt = 0; 

        for (int i = 0; i < n; i++) {
            if (nums[i] == zero) {
                cnt++;
            }
        }

        if (cnt == 2) {
            /*zero is the repeating number,
            one is the missing number*/
            return {zero, one}; 
        }
        
        /* one is the repeating number, 
        zero is the missing number*/
        return {one, zero}; 
    }
};

int main() {
    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};
    
    // Create an instance of Solution class
    Solution sol;

    vector<int> result = sol.findMissingRepeatingNumbers(nums);
    
    // Print the repeating and missing numbers found
    cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";
    
    return 0;
}
