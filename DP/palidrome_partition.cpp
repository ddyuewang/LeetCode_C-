#include <iostream>
#include <vector>

using namespace std;
int minCut(string s) {

    /*f[i] i-th pos as ending, min cut
    f[i] = min(f[j]+1) for j-i is also a palindrome*/

    // remark: string can be treated as array with direct partition
    int n = s.length();
    if ((n==0) || (n==1)) return 0;

    bool isPalid[n][n]; // pre-processing
    int f[n]; // result

    /*pre-processing*/
    for (int i = 0; i<n; i++)
    {
        isPalid[i][i] = true;
        if (i+1 <n)
        {
            isPalid[i][i+1] = (s[i] == s[i+1]);
        }
    }

    for(int i = n-1; i>=0; i--)
    {
        for(int j = i+2; j<n; j++)
        {
            isPalid[i][j] = isPalid[i+1][j-1] && (s[i]==s[j]); // very beatiful
        }
    }

    // the main update
    f[0] = 0; // notice the sample solution is given by f[0] = -1
    for (int i = 1; i <= n; i++) {
        f[i] = i - 1;
        for (int j = 0; j < i; j++) {
            if (isPalid[j][i - 1]) {
                f[i] = min(f[i], f[j] + 1);
            }
        }
    }

    return f[n];
}

int main()
{

    std::string Something = "Some text";
    int res = minCut(Something);
    cout << res << endl;
}