class Solution
{
public:
    void uniquePermutation(vector<int> &nums, set<vector<int>> &ans, int start)
    {
        if (start == nums.size())
        {
            ans.insert(nums);
            return;
        }

        set<int> visited;
        for (int i = start; i < nums.size(); i++)
        {
            if (visited.find(nums[i]) != visited.end())
            {
                continue;
            }
            visited.insert(nums[i]);
            swap(nums[i], nums[start]);
            uniquePermutation(nums, ans, start + 1);
            // Backtracking
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> uniquePerms(vector<int> &arr, int n)
    {
        sort(arr.begin(), arr.end());
        set<vector<int>> ans;
        uniquePermutation(arr, ans, 0);
        vector<vector<int>> val;
        for (auto i : ans)
        {
            val.push_back(i);
        }
        return val;
    }
};
