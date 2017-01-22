#include <iostream>
#include <vector>

using namespace std;
bool isBadVersion(int version);

class Solution_first_bad_version {
public:
    int firstBadVersion(int n) {
        // check boundary
        if (n<=0) return 0;

        int start = 1;
        int end = n;
        int mid;

        while(start + 1 < end)
        {
            mid = start + (end - start)/2;
            if (isBadVersion(mid))
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }

        if (isBadVersion(start))
        {
            return start;
        }
        else if (isBadVersion(end))
        {
            return end;
        }
        else
        {
            return n;
        }
    }
};
