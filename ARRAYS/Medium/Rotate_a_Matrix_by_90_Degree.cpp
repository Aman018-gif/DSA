// Rotate matrix by 90 degrees
// Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.
// The rotation must be done in place, meaning the input 2D matrix must be modified directly.
// 1.Brute Force Approach
// Idea: Create a new matrix and iterate in the orignal matrix and put each element in the correct position.
// Observation: 1st Row --> Last Column
//              2nd Row --> 2nd Last Column
//              3rd Row --> 3rd Last Column
//             Last Row --> First Column
//             [1][0]   --> [0][2]
//             [1][1]   --> [1][2]
//             [1][2]   --> [2][2]
//             [1][3]   --> [3][2]
//             Hence any Element At [i][j] position in Original Matrix comes at [i][n-1-i] in Rotated Matrix
// TC - O(N^2)
// SC - O(N^2)
// 2. Optimal Appraoch
// Idea: 1.Take the Transpose of the Original Matrix
//       2. Then Reverse Every Row.
// TC - O(N/2 *N/2) + O(N* N/2) (Reversin use 2 Pointer and TC of it is O(N/2))
// SC - O(1)

class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //Transpose
        for(int i=0;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //Reversing Each Row
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};