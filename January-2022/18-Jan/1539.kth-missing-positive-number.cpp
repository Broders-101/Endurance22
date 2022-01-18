/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 *
 * https://leetcode.com/problems/kth-missing-positive-number/description/
 *
 * algorithms
 * Easy (55.03%)
 * Likes:    1930
 * Dislikes: 136
 * Total Accepted:    134.5K
 * Total Submissions: 244K
 * Testcase Example:  '[2,3,4,7,11]\n5'
 *
 * Given an array arr of positive integers sorted in a strictly increasing
 * order, and an integer k.
 *
 * Find the k^th positive integer that is missing from this array.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [2,3,4,7,11], k = 5
 * Output: 9
 * Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The
 * 5^th missing positive integer is 9.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [1,2,3,4], k = 2
 * Output: 6
 * Explanation: The missing positive integers are [5,6,7,...]. The 2^nd missing
 * positive integer is 6.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 1000
 * 1 <= arr[i] <= 1000
 * 1 <= k <= 1000
 * arr[i] < arr[j] for 1 <= i < j <= arr.length
 *
 *
 */

// @lc code=start

// using Binary Search

class Solution
{
public:
    int findKthPositive(vector<int> &a, int k)
    {
        int res, low = 0, high = a.size() - 1, mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            int missed = a[mid] - mid - 1;

            if (missed >= k)
            {
                res = a[mid] - (missed - k) - 1;
                high = mid - 1;
            }
            if (missed < k)
            {
                low = mid + 1;
                res = a[mid] + k - missed;
            }
        }

        return res;
    }
};

// USING HASHING

// class Solution
// {
// public:
//     int findKthPositive(vector<int> &arr, int k)
//     {
//         bool hash[2002] = {false};

//         for (auto x : arr)
//         {
//             hash[x] = true;
//         }
//         int count = 0;
//         for (int i = 1; i < 2002; i++)
//         {
//             if (!hash[i])
//             {
//                 count++;
//                 if (count == k)
//                 {
//                     return i;
//                 }
//             }
//         }

//         return 0;
//     }
// };
// @lc code=end
