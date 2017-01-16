#include <vector>
#include <string>

using namespace std;
class Solution_longgest_common_subsequence {
public:
    //http://www.lintcode.com/en/problem/longest-common-subsequence/

    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // f[i][j]
        // f[i][j] = max(f[i-1][j], f[i][j-1], f[i-1][j-1] + 1) if(A[i-1] == B[j-1])
        // f[i][j] = max(f[i-1][j], f[i][j-1]) else

        // initialization
        int m = A.length();
        int n = B.length();
        int f[m+1][n+1];

        // update 1st col
        for(int i =0; i<m+1; i++)
        {
            f[i][0] = 0;
        }

        // update 1st row
        for(int i =0; i<n+1; i++)
        {
            f[0][i] = 0;
        }

        // main update
        for (int i = 1; i < m+1 ; i++)
        {
            for ( int j= 1; j <n+1 ; j++)
            {
                if(A[i-1]==B[j-1])
                {
                    f[i][j] = std::max(f[i-1][j], f[i][j-1]);
                    f[i][j] = std::max(f[i][j], f[i-1][j-1] + 1);
                }
                else
                {
                    f[i][j] = max(f[i-1][j], f[i][j-1]);
                }

            }
        }

        return f[m][n];
    }
};
