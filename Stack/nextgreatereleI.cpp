class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
  unordered_map<int, int> nextGreaterMap;
        stack<int> s;
        //  nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            // elements in decreasing order in the stack
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            // If stack is empty, there is no greater element on the right
            if (s.empty()) {
                nextGreaterMap[nums2[i]] = -1;
            } else {
                nextGreaterMap[nums2[i]] = s.top();
            }
            // Push current element to the stack
            s.push(nums2[i]);
        } 
    vector<int> ans;
        // Use the precomputed next greater elements from the map
        for (int num : nums1) {
            ans.push_back(nextGreaterMap[num]);
        }
        return ans;
}
};