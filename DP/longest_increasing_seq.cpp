#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // define state f[i] being as i the position being the end, whats the LIS
        // f[i] = max(f[j] + 1) for all j <i && nums[j] < nums[i]
        int n = nums.size();
        // boundary
        if (n==0) return 0;

        int f[n] = {};
        std::fill_n(f, n, 1);
        int res = 1;

        for (int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[j] < nums[i])
                {
                    f[i] = max(f[i],f[j]+1);
                }
                res = max(res,f[i]); // keep track the largest
            }
        }
        //notice to retrun max(f[0,1,....n-1]) instead of f[n-1]
        return res;
    }
};