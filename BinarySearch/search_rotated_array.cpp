#include <iostream>
#include <vector>

using namespace std;

class Solution_search_rotated_array{
public:
    int search(vector<int>& nums, int target) {

        // binary search - pay attention to the scenarios in this case
        int n = nums.size();

        //boundary condition
        if (n <= 0) return -1;
        if (n == 1)
        {
            return target == nums[0] ? 0:-1;
        }

        // initialization
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
            else if ((nums[start] <= target && target <= nums[mid] && nums[mid] > nums[start]) || (nums[mid] < nums[start] && nums[start] <= target )  || (nums[mid] < nums[start] && target <= nums[mid]))
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }

        if(nums[start] == target)
        {
            return start;
        }
        else if(nums[end] == target)
        {
            return end;
        }
        else
        {
            return -1;
        }

    }
};