#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(n < k || n <= 0 || k <0) return result; // boundary case
        vector<int> path;
        dfs(result,path,1, n, k);
        return result;
    }

    void dfs(vector<vector<int> >& result, vector<int>& path, int step, int n, int k)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }

        for (int i = step; i<=n; i++)
        {
            path.push_back(i);
            dfs(result,path,i+1, n, k);
            path.pop_back();
        }
    }
};

class Solution_combination_sum {
public:
    /* need to think why this one generate the duplicate*/
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // big difference is here - each element could be used multiple times
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        dfs(result,candidates,path,target, 0, 0);
        return result;
    }

    void dfs(vector<vector<int> >& result, vector<int>& candidates,  vector<int>& path, int target, int step, int level)
    {
        if (step == target)
        {
            result.push_back(path);
            return;
        }

        for (int i = level; i< candidates.size(); i++)
        {
            if(step+candidates[i] <= target)
            {
                path.push_back(candidates[i]);
                dfs(result,candidates,path,target,step+candidates[i],i); // here if i is replaced by level then the order matters !!! very very important!!!!
                path.pop_back();
            }
            else
            {
                return;
            }
        }
    }

};

class Solution_combination_sumII{
public:
    // if only once, we can use subsets
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        int n = candidates.size();
        if (n <=0) return result;
        sort(candidates.begin(), candidates.end());
        dfs(result, candidates, path, 0, 0, target);
        return result;
    }

    void dfs(vector<vector<int>> & result, vector<int>& candidates, vector<int>&path, int step, int level, int target)
    {
        if(step == target)
        {
            result.push_back(path);
            return;
        }
        for(int i=level; i<candidates.size(); i++)
        {
            if( i>level && candidates[i] == candidates[i-1])
            {
                continue; // the way to get rid of duplicates!!!
            }

            if(step+candidates[i] <= target)
            {
                path.push_back(candidates[i]);
                dfs(result, candidates, path, step+candidates[i], i+1, target); // notice here i doesnt work
                path.pop_back();
            }
        }
    }

};