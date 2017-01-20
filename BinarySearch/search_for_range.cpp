#include <iostream>
#include <vector>

using namespace std;

class Solution {
    /**
     * lintcode: http://www.lintcode.com/en/problem/search-for-a-range/
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // binary search twice - one for the start pos
        // -one for the end pos

        // check the input
        int n = A.size();
        vector<int> res = {-1, -1};
        if (n == 0) return res;
        if (target < A[0] || target > A[n-1]) return res;

        // main lookup
        int start = 0;
        int end = n-1;
        int mid;


        while (start+1 < end)
        {
            mid = start + (end - start)/2;
            if(A[mid] >= target)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }

        if (A[start] == target)
        {
            res[0] = start;
        }
        else if(A[end] == target)
        {
            res[0] = end;
        }
        else
        {
            return res;
        }

        start = 0;
        end = n-1;
        mid;

        while (start+1 < end)
        {
            mid = start + (end - start)/2;
            if(A[mid] <= target)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }

        if (A[end] == target)
        {
            res[1] = end;
        }
        else if(A[start] == target)
        {
            res[1] = start;
        }
        else
        {
            return res;
        }

        return res;

    }
};