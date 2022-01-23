/*
 * @lc app=leetcode id=1291 lang=cpp
 *
 * [1291] Sequential Digits
 *
 * https://leetcode.com/problems/sequential-digits/description/
 *
 * algorithms
 * Medium (57.51%)
 * Likes:    1403
 * Dislikes: 93
 * Total Accepted:    68.5K
 * Total Submissions: 112.5K
 * Testcase Example:  '100\n300'
 *
 * An integer has sequential digits if and only if each digit in the number is
 * one more than the previous digit.
 *
 * Return a sorted list of all the integers in the range [low, high] inclusive
 * that have sequential digits.
 *
 *
 * Example 1:
 * Input: low = 100, high = 300
 * Output: [123,234]
 * Example 2:
 * Input: low = 1000, high = 13000
 * Output: [1234,2345,3456,4567,5678,6789,12345]
 *
 *
 * Constraints:
 *
 *
 * 10 <= low <= high <= 10^9
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> res;

        string s = "123456789";

        int min_len = to_string(low).size();
        int max_len = to_string(high).size();

        for (int i = min_len; i <= max_len; i++)
        {
            for (int j = 0; j < 10 - i; j++)
            {
                int number = stoi(s.substr(j, i));
                if (number >= low && number <= high)
                {
                    res.push_back(number);
                }
            }
        }

        return res;
    }

private:
    int firstDigit(int n)
    {
        while (n >= 10)
        {
            n = n / 10;
        }

        return n;
    }
};
// @lc code=end
