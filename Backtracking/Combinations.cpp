class Solution {
public:
    void   makeCombinations(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; ++i) {
            current.push_back(i);           
              makeCombinations(i + 1, n, k, current, result); 
            current.pop_back();              
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
          makeCombinations(1, n, k, current, result); 
        return result;
    }
};