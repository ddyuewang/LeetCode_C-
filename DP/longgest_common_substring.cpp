#include <vector>
#include <string>

using namespace std;
class Solution_longest_common_substring {
public:
    //http://www.lintcode.com/en/problem/longest-common-substring/
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // here f[i][j] up to a[i] & b[j] - here order matters
        // f[i][j] = f[i-1][j-1] + 1 if A[i] = B[j] else 0

        int m = A.length();
        int n = B.length();
        int f[m+1][n+1];

        for (int i = 0; i <=m; i++)
        {
            f[i][0] = 0;
        }

        for (int i = 0; i <=n; i++)
        {
            f[0][i] = 0;
        }

        // main update
        for (int i = 1; i<=m; i++)
        {
            for(int j = 1; j<=n ; j++)
            {
                if (A[i-1] == B[j-1])
                {
                    f[i][j] = f[i-1][j-1] + 1;
                }
                else
                {
                    f[i][j] = 0;
                }
            }
        }


        // - tricky part - finding the maximum
        int res = 0;
        for (int i = 0; i<=m; i++)
        {
            for(int j = 0; j<=n ; j++)
            {
                if(f[i][j] > res)
                {
                    res = f[i][j];
                }
            }
        }

        return res;

    }
};

