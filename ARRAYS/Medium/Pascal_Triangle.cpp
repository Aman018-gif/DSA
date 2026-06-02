// Pascal Traingle
// 3 Types 
// Type 1
// Given row and column no and give the element 
// can be done usign formula r-1(C)c-1 which is give that element
// calcualting nCr = (n)!/(n-r)!*(r)! each diffent and putting is very much extreme brute force TC O(n)+O(r)+O(n-r)
// we can do it like n*n-1*n-2 till r places and dive by r!
// TC - O(r)
// SC - O(1)
// Given two integers r and c, return the value at the rth row and cth column (1-indexed) in a Pascal's Triangle.
// In Pascal's triangle:
// The first row contains a single element 1.
// Each row has one more element than the previous row.
// Every row starts and ends with 1.
// For all interior elements (i.e., not at the ends), the value at position (r, c) is computed as the sum of the two elements directly above it from the previous row:
// Pascal[r][c]=Pascal[r−1][c−1]+Pascal[r−1][c]
// where indexing is 1-based
class Solution {
public:
    int pascalTriangleI(int r, int c) {
        int n1 = r-1;
        int c1=c-1;
        long long ans=1;
        for(int i=0;i<c1;i++){
            ans *= (n1-i);
            ans= ans/(i+1);
        }
        return ans;
    }
};
// Type 2 - Given n print that nth row 
// In this brute force would be every element in that row caluclate by using the formula but it led to TC O(n*r) approx. O(n^2)
// Instead we observe a patter in th nth row starting from 1 in each next term it get multiplied by a term which is (row-col)/(col)
// TC-O(n) and SC -O(1)
    void generaterow(vector<int>& temp_ans,int numRows){
        int ans=1;
        for(int i=1;i<=numRows;i++){
            temp_ans.push_back(ans);
            ans*=(numRows-i);
            ans=ans/i;
        }
    }
// Type 3 - Print the complete Pascal Triangle till that nth row given as input 
// Extreme Brute force would be get every element from the formula but led to TC - O(n*n*r) approx. O(n^3) Worst case
// Hence we use the approach of row-col/col used in type 2 to generate nth row and us this for every from till nth row.
// TC - O(n^2)
class Solution {
public:
    vector<int> generaterow(int numRows){
        int ans=1;
        vector<int>temp_ans;
        for(int i=1;i<=numRows;i++){
            temp_ans.push_back(ans);
            ans*=(numRows-i);
            ans=ans/i;
        }
        return temp_ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>final_ans;
        for(int i=1;i<=numRows;i++){
            final_ans.push_back(generaterow(i));
        }
        return final_ans;
    }
};