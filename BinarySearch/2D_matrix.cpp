#include <iostream>
#include <vector>

using namespace std;
class Solution_2D_matrix {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // initialization
        int m = matrix.size(); // get the number of rows
        if( m == 0) return false;
        int n = matrix[0].size(); // get the number of cols
        if(n == 0) return false;

        // check the boundary
        if (matrix[0][0] > target || target > matrix[m-1][n-1])
        {
            return false;
        }

        // binary search on those -  divide by the size of col!!! to get the position
        /* /-- row %-- col*/
        int start = 0;
        int end = m*n - 1;
        int mid;
        int curr_row, curr_col;

        while (start + 1 < end)
        {
            mid = start + (end-start)/2;
            curr_row = mid/n;
            curr_col = mid%n;
            if (matrix[curr_row][curr_col] == target)
            {
                return true;
            }
            else if (matrix[curr_row][curr_col] > target)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }

        if (matrix[start/n][start%n] == target)
        {
            return true;
        }
        else if (matrix[end/n][end%n] == target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};