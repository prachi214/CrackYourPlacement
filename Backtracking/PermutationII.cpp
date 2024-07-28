class Solution
{
public:
    void uniquePermutation(vector<int> &nums, vector<vector<int>> &ans, int start)
    {
        if (start == nums.size())
        {
            // base
            ans.push_back(nums);
            return;
        }

        unordered_map<int, bool> visited;
        for (int i = start; i < nums.size(); i++)
        {
            // if key present on map
            if (visited.find(nums[i]) != visited.end())
            {
                continue;
            }
            visited[nums[i]] = true;
            swap(nums[i], nums[start]);
            uniquePermutation(nums, ans, start + 1);
            //  backtracking
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        uniquePermutation(nums, ans, 0);
        return ans;
    }
};