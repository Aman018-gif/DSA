// Set Matrix Zeroes
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// 1.Brute Force Approach
// In the brute-force approach, we iterate through the array, and as soon as we encounter a zero, we mark all the other elements in that respective row and column as -1. After completing this step, we iterate through the array a second time and change all the -1 values to 0. Conversely, in the better approach, we optimize this process by using two separate arrays to keep track of the specific rows and columns that need to be updated.
// TC - O(N*M)*O(N+M)+O(N*M) Roughly O(N^3) 
// SC - O(1)
// 2.Better Approach
// In the better approach, we optimize the process by maintaining two separate arrays for marking the rows and columns. As we iterate through the matrix, whenever we find an element that is zero, we mark its respective row index and column index in these separate row and column arrays. Afterwards, we iterate through the matrix one more time and update the elements to zero based on the markings in our row and column arrays.
// TC - O(2*N*M) roughly O(N^2)
// SC - O(N)+O(M)
// 3.Optimal Approach
// In the optimal approach, while the time complexity cannot be reduced further, we can optimize the space complexity. Instead of allocating two separate arrays, we use the first row and the first column of the matrix itself to keep track of the zeroes. However, because the top-left element overlaps as the start of both the first row and the first column, it creates a conflict. To resolve this, we use an additional variable (like col0) specifically to track the state of the first column, while the top-left element is used to track the first row. The rest of the marking and updating process then remains the same as the previous approach.
// TC - O(2*N*M) roughly O(N^2)
// SC - O(1) (not considering and int col0 variable space)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1;
        int rows = matrix.size();
        int cols = rows ? matrix[0].size() : 0;
        for(int i =0;i<=rows-1;i++){
            for(int j=0;j<=cols-1;j++){
                if(matrix[i][j]==0){
                    //marking the ith row
                    matrix[i][0]=0;
                    //marking the jth column
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{
                        col0=0;
                    }
                }
            }
        }

        //updating the middle matrix
        for(int i =1;i<=rows-1;i++){
            for(int j=1;j<=cols-1;j++){
                if(matrix[i][j]!=0){
                    //check col and row
                    if(matrix[i][0]==0 || matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<=cols-1;j++){
                matrix[0][j]=0;
            }
        }
        if(col0==0){
            for(int i=0;i<=rows-1;i++){
                matrix[i][0]=0;
            }
        }
    }
};