#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void uniquePermutation(vector<int>& nums, vector<vector<int>>& ans, int start) {
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }

    
        set<int> visited;
        for (int i = start; i < nums.size(); i++) {
            if (visited.find(nums[i]) != visited.end()) {
                continue;
            }
            visited.insert(nums[i]);
            swap(nums[i], nums[start]);
            uniquePermutation(nums, ans, start + 1);
            // Backtracking
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> uniquePerms(vector<int>& arr, int n) {
        sort(arr.begin(), arr.end());  
        vector<vector<int>> ans;
        uniquePermutation(arr, ans, 0);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> result = sol.uniquePerms(arr, arr.size());

    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}


