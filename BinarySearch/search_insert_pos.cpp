#include <iostream>
#include <vector>

using namespace std;

class Solution_insert_pos {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 1st position > target or last position < target
        // check the boundary
        int n = nums.size();
        if (n == 0 ) return 0;
        if (target < nums[0]) return 0;
        if (target > nums[n-1]) return n;

        // routine binary search
        int start = 0;
        int end = n-1;
        int mid;

        while (start + 1 < end)
        {
            mid = start + (end - start)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }

        if (nums[start] == target)
        { return start;}
        else if (nums[end] == target)
        { return end;}
        else
        { return end;} // keep in mind its between start and end, so return end
    }
};