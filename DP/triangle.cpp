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



//int main() {
//    cout << "Hello, World!" << endl;
//    return 0;
//    }
