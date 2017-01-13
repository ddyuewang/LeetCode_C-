#include <iostream>
#include <vector>

using namespace std;

class Solution_jump_game {
public:
    bool canJump(vector<int>& nums) {
        // define the state f[i] - from start, - doable to get to the ith position
        int n = nums.size();
        int f[n+1] = {}; //default to 0
        f[1] = 1;// set the 1st position to be true

        for(int i=2; i<=n; i++)
        {
            for(int j=i-1; j>=1; j--)
            {
                if(f[j] == 1 && j+nums[j-1] >= i) // trick is to go from i-1
                {
                    f[i] = 1;
                    break;
                }
            }
        }
        return f[n]==1;
    }
};


class Solution_jump_gameII_DP {
public:
    int jump(vector<int>& nums) { // dynamic progrming will exceed the time limit
        // define the state f[i] - from start, - doable to get to the ith position
        int n = nums.size();
        if (n==1) return 0; // boundary case
        int f[n+1] = {};
        std::fill_n(f, n+1, INT_MAX);
        f[0] = 0;
        f[1] = 0;

        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<i; j++)
            {
                if(f[j] != INT_MAX && j+nums[j-1] >= i) // trick is to go from i-1
                {
                    f[i] = min(f[i], f[j]+1);
                }
            }
        }
        return f[n];
    }
};

class Solution_jump_gameII_greedy {
public:
    int jump(vector<int> &nums) { // greedy algorithm

        int cur = 0;
        int last = 0;
        int ret = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > last) {
                last = cur;
                ++ret; // as your last position wouldn't be cover the currnent i, coverage moves...
            }

            cur = max(cur, i + nums[i]);
        }

        return ret;

    }
};
