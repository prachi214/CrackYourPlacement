class Solution {
public:
void findAllSubset(int ind, vector<int>&nums, vector<int>&ds,vector<vector<int>>&ans){
    // put ans,  2d vector  stores each 1d 
ans.push_back(ds);
// here loop conditional statement works as base case
for (int i = ind; i <nums.size(); i++)
{
    ds.push_back(nums[i]);
    // recursive call
    findAllSubset(i+1, nums,ds,ans);
    // backtracking
    ds.pop_back();
}
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        findAllSubset(0,nums,ds,ans);
        return ans;
    }
};