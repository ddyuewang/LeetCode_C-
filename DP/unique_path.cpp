#include <iostream>
#include <vector>

using namespace std;

class Solution_path_I {
public:
    int uniquePaths(int m, int n) {
        // DP f[x][y]
        // initialization
        int f[m][n];
        for (int i = 0; i <m; i++)
        {
            f[i][0] = 1;
        }
        for (int i = 0; i <n; i++)
        {
            f[0][i] = 1;
        }
        // main update
        for (int i =1; i <m; i++)
            for (int j =1; j <n; j++)
                f[i][j] = f[i][j-1] +f[i-1][j];

        return f[m-1][n-1];
    }
};

class Solution_path_II {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // DP f[x][y]
        // initialization
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int f[m][n] = {};
        for (int i = 0; i <m; i++)
        {
            if(obstacleGrid[i][0]==0)
            {f[i][0] = 1;}
            else
            {break;}
        }
        for (int i = 0; i <n; i++)
        {
            if(obstacleGrid[0][i]==0)
            {f[0][i] = 1;}
            else
            {break;}
        }
        // main update
        for (int i =1; i <m; i++){
            for (int j =1; j <n; j++)
            { if (obstacleGrid[i][j]==0)
                {f[i][j] = f[i][j-1] +f[i-1][j];}
                else
                {f[i][j] =0;}
            }
        }
        return f[m-1][n-1];
    }
};