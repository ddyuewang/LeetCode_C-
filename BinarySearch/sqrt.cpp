#include <iostream>
#include <vector>

using namespace std;

class Solution_sqrt {
public:
    int mySqrt(int x) {

        // check the boundary
        if (x<0) return -1;
        if (x==0 || x== 1) return x;
        if (x==2 || x== 3) return 1;
        if (x==4) return 2;

        // when x>4, sqrt(x) < x/2; so only need to binary search on number that up to x/2
        // binary search on 3----x/2

        long start = 2;
        long end = x/2;
        long mid;

        while(start + 1 <end)
        {
            mid = start + (end - start)/2;
            if (mid * mid == x)
            { return mid;}
            else if (mid * mid > x)
            {
                end = mid;
            }
            else
            {
                start = mid; // when dealing with no exact answers - need to set start/end = mid TO MAKE It DONT ACROSS (end == start)
            }
        }

        if (start * start == x)
        {
            return start;
        }
        else if (end * end == x)
        {
            return end;
        }
        else
        {
            // return -1;
            return start; // in theory it should return -1;
        }


    }
};

