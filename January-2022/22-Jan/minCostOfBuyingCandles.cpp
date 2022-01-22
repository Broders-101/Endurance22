class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        if (cost.size() == 1)
        {
            return cost[0];
        }
        else if (cost.size() == 2)
        {
            return (cost[0] + cost[1]);
        }

        sort(cost.begin(), cost.end());

        int j;
        int res = 0;
        int n = cost.size();
        for (int i = 0; i < n; i++)
        {
            j = n - i - 1;

            if (j != 0)
            {
                res += cost[j] + cost[j - 1];
            }
            else if (j == 0)
            {
                res += cost[j];
                break;
            }
            i += 2;
            // int hell = min(cost[j], cost[j-1]);
        }

        return res;
    }
};