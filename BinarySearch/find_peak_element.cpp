#include <iostream>
#include <vector>

using namespace std;

class Solution_find_peak_element {
public:
    int findPeakElement(vector<int>& nums) {
        // binary search
        int n = nums.size();

        if (n <= 0) return -1;
        if (n==1) return 0;

        int start = 0;
        int end = n-1;
        int mid;

        while(start+1 < end)
        {
            mid = start + (end - start)/2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            {
                return mid;
            }
            else if (nums[mid-1] < nums[mid]  && nums[mid] < nums[mid+1])
            {
                start = mid;
            }
            else if (nums[mid-1] > nums[mid]  && nums[mid] > nums[mid+1])
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }

        if(nums[start] > nums[end])
        { return start;}
        else
        { return end; }
    }
};