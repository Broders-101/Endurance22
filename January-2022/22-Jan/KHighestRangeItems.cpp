class Solution
{
public:
    struct node
    {
        int dist;
        int cost;
        int r, c;
    };

    struct compare
    {
        bool operator()(const node &a, const node &b)
        {
            return std::tie(a.dist, a.cost, a.r, a.c) < std::tie(b.dist, b.cost, b.r, b.c);
        }
    };

    vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k)
    {
        int n = grid.size();
        int m = grid[0].size();

        int dir[4][2] = {{-1, 0},
                         {0, 1},
                         {1, 0},
                         {0, -1}};

        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        int len = 0;

        set<pair<int, int>> visited;
        visited.insert({start[0], start[1]});

        int lower = price[0], upper = price[1];

        priority_queue<node, vector<node>, compare> hell;

        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                pair<int, int> p = q.front();
                q.pop();
                int i = p.first, j = p.second;

                if (grid[i][j] != -1)
                {
                    int currCost = grid[i][j];

                    if (currCost >= lower && currCost <= upper)
                    {
                        if (hell.size() < k)
                        {
                            hell.push({len, currCost, i, j});
                        }
                        else if (hell.size() == k)
                        {
                            struct node temp = hell.top();
                            if (temp.dist > len)
                            {
                                hell.pop();
                                hell.push({len, currCost, i, j});
                            }
                            else if (temp.dist == len)
                            {
                                if (temp.cost > currCost)
                                {
                                    hell.pop();
                                    hell.push({len, currCost, i, j});
                                }
                                else if (temp.cost == currCost)
                                {
                                    if (temp.r > i)
                                    {
                                        hell.pop();
                                        hell.push({len, currCost, i, j});
                                    }
                                    else if (temp.r == i && temp.c > j)
                                    {
                                        hell.pop();
                                        hell.push({len, currCost, i, j});
                                    }
                                }
                            }
                        }
                    }
                }

                // moving in the adjacent cell (dfs implementation)

                for (int x = 0; x < 4; x++)
                {
                    int hor = i + dir[x][0], ver = j + dir[x][1];

                    if (hor >= 0 && ver >= 0 && hor < n && ver < m && visited.find({x, y}) == visited.end() && grid[x][y] != 0)
                    {
                        visited.insert({x, y)});
                        q.push({x, y});
                    }
                }
            }
            len++;
        }

        vector<vector<int>> ans;

        while (hell.size() > 0)
        {
            struct node res = hell.top();
            hell.pop();

            ans.push_back({res.r, res.c});
            k--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// can compare like this also
/*

// storing least desired cell at top (max. Heap)

struct compare{
    bool operator()(const node &a, const node &b){
        if(a.dist != b.dist){
            return a.dist < b.dist;
        }else if(a.cost != b.cost){
            return a.cost < b.cost;
        }else if(a.r != b.r){
            return a.r < b.r;
        }
        return a.c < b.c;
    }
};

*/