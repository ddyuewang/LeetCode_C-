#include <iostream>
#include <vector>

using namespace std;

class Solution_subset {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> path;
        result.push_back(vector<int>(0)); //initial empty set
        sort(nums.begin(), nums.end());
        dfs(nums, result, 0, path);
        return result;
    }

    void dfs (vector<int>& nums, vector<vector<int>> & result, int pos, vector<int> &path)
    {
        for (int i = pos; i<nums.size(); i++)
        {
            path.push_back(nums[i]);
            result.push_back(path);
            dfs(nums, result, i+1, path);
            path.pop_back();
        }
    }
};

class Solution_subsetII {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> path;
        result.push_back(vector<int>(0)); //initial empty set
        sort(nums.begin(), nums.end());
        dfs(nums, result, 0, path);
        return result;
    }

    void dfs (vector<int>& nums, vector<vector<int>> & result, int pos, vector<int> &path)
    {
        for (int i = pos; i<nums.size(); i++)
        {
            if( i!= pos && nums[i] == nums[i-1]) // here all the repetition work is done by the 1st element
            {
                continue;
            }
            path.push_back(nums[i]);
            result.push_back(path);
            dfs(nums, result, i+1, path);
            path.pop_back();
        }
    }

};

