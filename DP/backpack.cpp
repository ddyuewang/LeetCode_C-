#include <iostream>
#include <vector>

using namespace std;
int backPack_I(int m, vector<int> A) {

    // http://www.lintcode.com/en/problem/backpack/
    /* only only 80% of test code is passed !!! - rethink whats going wrong with it*/

    // f[i][j] - use the 1st i elements to get filled for j values
    // i - 0...n, j - 0...m
    // one of the key construct - bool arrays to track the results
    int n = A.size();
    bool f[n+1][m+1];


    // initialization
    for (int i =0; i< n+1; i++)
    {
        f[i][0] = true;
    }
    for (int i =1; i< m+1; i++)
    {
        f[0][i] = false;
    }


    // main update
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j< m+1; j++)
        {
            f[i][j] = false;
            if (j>= A[i-1])
                {
                    f[i][j] = (f[i][j] || f[i-1][j-A[i-1]]);
                }
            f[i][j] = (f[i][j] || f[i-1][j]);
            // either keep A[i-1] or not
        }
    }

    // get the results
    for(int j=m; j>=0; j--)
    {
        if(f[n][j])
        {
            return j;
        }
    }

    return 0;

}


class Solution_backpackII {
public:
    /**
     * http://www.lintcode.com/en/problem/backpack-ii/
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // need f[i][j] - first i item, size = j 的max value
        // f[i][j] = max f[i-1][j], f[i-1][j-a[i-1] + V[i]]

        int n = A.size();
        int f[n+1][m+1];

        if (m <= 0 || n <=0) return 0;
        // initialization

        f[0][0] = 0;
        for (int i = 1; i < n+1; i++)
        {
            f[i][0] = 0;
            f[0][i] = INT_MIN;
        }
        for (int i = 1; i < m+1; i++)
        {
            f[0][i] = INT_MIN;
        }


        // main udpate
        for (int i = 1; i <n+1; i++)
        {
            for (int j = 1; j < m+1; j++)
            {
                f[i][j] = 0;
                if(j >= A[i-1])
                {
                    f[i][j] = max(f[i][j], f[i-1][j-A[i-1]]+V[i-1]);
                }
                f[i][j] = max(f[i][j], f[i-1][j]);
            }
        }
        // read thru the item-volume pairs to get the values
        int res = 0;
        for (int i = 0; i < m +1; i++)
        {
            res = max(res, f[n][i]);
        }

        return res;
    }

};
