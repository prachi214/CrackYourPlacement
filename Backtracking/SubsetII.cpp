class Solution {
public:
void findAllUniqueSubset(int ind, vector<int>&nums, vector<int>&ds,vector<vector<int>>&ans){

ans.push_back(ds);

// here loop conditional statement works as base case
for (int i = ind; i <nums.size(); i++)
{
// for avoiding duplicate subsets
        if(i!= ind && nums[i] == nums[i-1]) continue;
    ds.push_back(nums[i]);
    // recursive call
    findAllUniqueSubset(i+1, nums,ds,ans);
    // backtracking
    ds.pop_back();
}
}
    vector<vector<int>>subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        // bcoz we want duplicate elements present together
        sort(nums.begin(), nums.end());
        findAllUniqueSubset(0,nums,ds,ans);
        return ans;
    }
};