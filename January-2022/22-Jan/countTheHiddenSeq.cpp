class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        long long first = 0, maxn = 0, minn = 0;
        for (auto diff : differences)
        {
            first += diff;
            maxn = max(maxn, first);
            minn = min(minn, first);
        }

        long long res = (upper - lower) - (maxn - minn) + 1;

        return max(0LL, res);
    }
};

// My understanding

/*

for the difference array -> [3, -1, 5, 1, -2]

if i start with first element x;
then the elements of the array would be [x, x+3, x-1, x+4, x+5, x+3];

here the minimum element is -> x-1;
the maximum element -> x+5

so x-1 >= lower && x+5 <= upper

*/