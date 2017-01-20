#include <iostream>
#include <vector>

using namespace std;

class house_robber_1 {
public:
    int rob(vector<int>& nums) {
        /* boundary condition */
        int n = nums.size();
        if (n < 1)
        { return 0;}

        if (n == 1)
        { return nums[0];}

        // main construction
        vector<int> res(n+1,0);
        res[0] = 0;
        res[1] = nums[0];
        for (int i = 2; i <= n; i++)
        {
            res[i] = max(res[i-1], res[i-2] + nums[i-1]);
        }

        // return res[n];
        return *max_element(res.begin(), res.end()); // get the max_element of a given array
    }
};

// case where the last house and first house are connected
class house_robber_2 {
public:
    int rob(vector<int>& nums) {
            /* boundary condition */
            int n = nums.size();
            if (n < 1)
            { return 0;}

            if (n == 1)
            { return nums[0];}

            // main construction
            vector<int> res(n+1,0);

            /* the key is to seperate the calculation of the first element
             */
            res[0] = 0;
            res[1] = nums[0];
            for (int i = 2; i < n; i++)
            {
                    res[i] = max(res[i-1], res[i-2] + nums[i-1]);
            }

            int ans = res[n-1]; // exclude the last element

            res[0] = 0;
            res[1] = 0;
            for (int i = 2; i <= n; i++)
            {
                    res[i] = max(res[i-1], res[i-2] + nums[i-1]);
            } // here exclude the 1st element - set the res[1]=0

            return max(ans, res[n]);

    }
};

