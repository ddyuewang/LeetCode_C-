#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // 经典问题
        int m = s1.length();
        int n = s2.length();
        if (m+n != s3.length()) return false; // check the boundary cases

        // initilization
        bool f[m+1][n+1];
        f[0][0] = true;
        for (int i= 1; i< m+1; i++)
        {
            f[i][0] = (f[i-1][0] && s1[i-1] == s3[i-1]);
        }

        for (int i= 1; i< n+1; i++)
        {
            f[0][i] = (f[0][i-1] && s2[i-1] == s3[i-1]);
        }
        // main update
        for (int i=1; i < m+1; i++)
        {
            for (int j=1; j< n+1; j++)
            {
                /* mandatory update ??!! */
                f[i][j] = false;

                if (s1[i-1]==s3[i+j-1]) // index is tricky
                {
                    f[i][j] = f[i][j] || f[i-1][j];
                }

                if (s2[j-1]==s3[i+j-1]) // cant use else if I guess
                {
                    f[i][j] = f[i][j] || f[i][j-1];
                }

                /*Here is very important aspect of the code
                what happens if f[i][j] is true originally and f[i-1][j] - the dependant stage turns out to be wrong*/
                // keep in mind the solution on the update stage has to be f[i][j] || f[i-1][j] !!!!! very crucial !!!
            }
        }

        return f[m][n];
    }
};