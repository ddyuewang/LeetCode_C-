#include <iostream>
#include <vector>

using namespace std;

class Solution_traverse {
    /* traverse  - doesnt have return value - void method
     * here best is global variable
     * */
public:
    void traverse(int x, int y, int sum, int & best, int & n, vector<vector<int>>& triangle)
    {
        if(x==n)
        {
            if(sum < best)
            {best = sum;}
            return;
        }
        traverse(x+1, y, sum + triangle[x][y], best, n, triangle);
        traverse(x+1, y+1, sum + triangle[x][y], best, n, triangle);
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        int best = INT_MAX;
        traverse(0,0,0,best,n,triangle);
        return best;
    }

};

class Solution_divide_conquer {
public:
    int dfs(int x, int y, int &n, vector<vector<int>> &triangle) {
        if (x == n) {
            return 0;
        }
        return min(dfs(x + 1, y, n, triangle), dfs(x + 1, y + 1, n, triangle)) + triangle[x][y];
    }

    int minimumTotal(vector<vector<int>> &triangle) {
        // divide and conquer version of triangle
        int n = triangle.size();
        int best = dfs(0, 0, n, triangle);
        return best;
    }
};

// remark: instead of using hashmap/std::map - its painful to use it to deal with pair values as key
//         using vector of vector directly
class Solution_divide_conquer_memo {
public:

    //divide and conquer with memorization
    int dfs(int x, int y, int &n, vector<vector<int>> &triangle, vector<vector<int>> &res) {
        if (x == n) {
            return 0;
        }

        if (res[x][y] != -1) {
            return res[x][y];
        }
        else {
            res[x][y] = min(dfs(x + 1, y, n, triangle, res), dfs(x + 1, y + 1, n, triangle, res)) + triangle[x][y];
            return res[x][y];
        }

    }

    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<vector<int>> res(n, std::vector<int>(m, -1));
        int best = dfs(0, 0, n, triangle, res);
        return best;
    }
};



//int main() {
//    cout << "Hello, World!" << endl;
//    return 0;
//    }
