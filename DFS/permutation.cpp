// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
class Solution_permutation {
public:
    // DFS
    /* 1.without hashtable */
    //     vector<vector<int>> permute(vector<int>& nums)
    //     {
    //         // sort(nums.begin(), nums.end());
    //         vector<vector<int> > result;
    //         vector<int> path; // temp result
    //         dfs(nums, path, result);
    //         return result;
    //     }
    // void dfs(vector<int>& nums,vector<int>& path, vector<vector<int> > & result)
    //     {
    //         if (path.size()==nums.size())
    //         {
    //             result.push_back(path);
    //             return;
    //         }

    //         // main loop to update
    //         for (int i = 0; i< nums.size(); i++)
    //         {
    //           // check if current path contains the current elements
    //           if(std::find(path.begin(), path.end(), nums[i]) != path.end()) {continue;}
    //           path.push_back(nums[i]);
    //           dfs(nums, path, result); // biggest difference is no increment
    //           path.pop_back();
    //         }
    //     }
    /* 2. with hashtable*/
    vector<vector<int>> permute(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        vector<int> path; // temp result
        vector<bool> isVisited(nums.size(), false);
        // very important !!! using this bool type array to check whether or not the elments has been visit (stored the index rather than the value )
        dfs(nums, path, result, isVisited);
        return result;
    }
    void dfs(vector<int>& nums,vector<int>& path, vector<vector<int> >& result, vector<bool>& isVisited)
    {
        if (path.size()==nums.size())
        {
            result.push_back(path);
            return;
        }

        // main loop to update
        for (int i = 0; i< nums.size(); i++)
        {
            // check if current path contains the current elements
            if (isVisited[i] == false)
            {
                path.push_back(nums[i]);
                isVisited[i] = true;
                dfs(nums, path, result, isVisited); // biggest difference is no increment
                isVisited[i] = false;
                path.pop_back();

            }
        }
    }
};

class Solution_permutation_II{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        vector<int> path; // temp result
        vector<bool> isVisited(nums.size(), false);
        // very important !!! using this bool type array to check whether or not the elments has been visit (stored the index rather than the value )
        dfs(nums, path, result, isVisited);
        return result;
    }
    void dfs(vector<int>& nums,vector<int>& path, vector<vector<int> > & result, vector<bool>& isVisited)
    {
        if (path.size()==nums.size())
        {
            result.push_back(path);
            return;
        }



        // main loop to update
        for (int i = 0; i< nums.size(); i++)
        {
            if( i != 0 && nums[i] == nums[i-1] && isVisited[i-1] == false)
            {
                continue; // 经典的判断
            }
            // check if current path contains the current elements
            if (isVisited[i] == false)
            {
                path.push_back(nums[i]);
                isVisited[i] = true;
                dfs(nums, path, result, isVisited); // biggest difference is no increment
                isVisited[i] = false;
                path.pop_back();
            }
        }
    }
};


