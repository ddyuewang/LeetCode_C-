#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        // binary search
        int n = nums.size();

        //boundary condition
        if (n <= 0) return -1;
        if (n == 1) return nums[0];

        int start = 0;
        int end = n-1;
        int mid;

        while (start + 1 < end)
        {
            mid = start + (end - start)/2;
            if(nums[mid] < nums[end])
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }

        if(nums[start]<nums[end])
        {
            return nums[start];
        }
        else
        {
            return nums[end];
        }

    }
};