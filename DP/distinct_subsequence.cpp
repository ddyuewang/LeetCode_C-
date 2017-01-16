#include <vector>
#include <string>

using namespace std;

class Solution_distinct_subsequence {
public:
    // lintcode:http://www.lintcode.com/en/problem/distinct-subsequences/
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // Tricky Question - not sure if I understand the question correctly
        // Given S = "rabbbit", T = "rabbit", return 3.
        // T1-rabbit, T2= rabb, T3= bbit - the three distintct subsequence

        int m = S.length();
        int n = T.length();
        if (n==0) return 1;
        if (m==0) return 0;
        int f[m+1][n+1];

        for (int i = 0; i<m+1; i++)
        {
            f[i][0] = 1; // tricky part
        }

        for (int i = 1; i<n+1; i++)
        {
            f[0][i] = 0;
        }

        // main update
        for (int i = 1; i < m+1; i++)
        {
            for (int j = 1; j< n+1; j++)
            {
                if (S[i-1] == T[j-1])
                {
                    f[i][j] = f[i-1][j-1] + f[i-1][j]; // tricky part as well - need think
                    // what happens if S[i-2] = T[i-1]
                }
                else
                {
                    f[i][j] = f[i-1][j];
                }
            }
        }

        return f[m][n];

    }
};
