class Solution {
public:

    void mergeSort(vector<int>& nums1, vector<int>& nums2, int i, int j, int k) {
        // Base cases
        if (j < 0) {
            return; // nums2 is exhausted, nothing more to merge
        }
        if (i < 0) {
            while (j >= 0) { // nums1 is exhausted, copy remaining nums2
                nums1[k--] = nums2[j--];
            }
            return;
        }

        // Recursive case
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            mergeSort(nums1, nums2, i - 1, j, k - 1);
        } else {
            nums1[k] = nums2[j];
            mergeSort(nums1, nums2, i, j - 1, k - 1);
        }
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
             mergeSort(nums1, nums2, m - 1, n - 1, m + n - 1); 
    }
};