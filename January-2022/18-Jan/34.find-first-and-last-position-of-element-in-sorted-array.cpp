/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (39.11%)
 * Likes:    8606
 * Dislikes: 264
 * Total Accepted:    935.8K
 * Total Submissions: 2.4M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in non-decreasing order, find the
 * starting and ending position of a given target value.
 *
 * If target is not found in the array, return [-1, -1].
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start

// Leetcode Medium

// Lower Upper Bound

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (lower == upper)
        {
            return {-1, -1};
        }
        return {lower, upper - 1};
    }
};

// traditional binary search

/*
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = solve(nums, target, true);
        int end = solve(nums, target, false);

        return {start, end};
    }

private:
    int solve(vector<int> &nums, int target, bool flag)
    {
        int res = -1;
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (target < nums[mid])
            {
                high = mid - 1;
            }
            else if (target > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                res = mid;

                if (flag)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }

        return res;
    }
};

*/
// @lc code=end
