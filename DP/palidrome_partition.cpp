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


int backPack(int m, vector<int> A) {
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

int main()
{

//    std::vector<int> A {81,112,609,341,164,601,97,709,944,828,627,730,
//                        460,523,643,901,602,508,401,442,738,443,555,471,
//                        97,644,184,964,418,492,920,897,99,711,916,178,189,
//                        202,72,692,86,716,588,297,512,605,209,100,107,938,
//                        246,251,921,767,825,133,465,224,807,455,179,436,201,
//                        842,325,694,132,891,973,107,284,203,272,538,137,248,
//                        329,234,175,108,745,708,453,101,823,937,639,485,524,
//                        660,873,367,153,191,756,162,50,267,166,996,552,675,
//                        383,615,985,339,868,393,178,932};
    std::vector<int> A {3,4,8,5};
    int res = backPack(10,A);
    cout << res << endl;

}