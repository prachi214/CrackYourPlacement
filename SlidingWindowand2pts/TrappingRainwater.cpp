class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int leftmax = 0;
        int rightmax = 0;
        int trappingWater = 0;
        // 2 pointer
        int l = 0, r = n - 1;
        while (l < r)
        {

            if (height[l] <= height[r])
            {

                if (leftmax > height[l])
                    trappingWater += leftmax - height[l];

                else
                    leftmax = height[l];
                l = l + 1;
            }

            else
            {
                if (rightmax > height[r])
                    trappingWater += rightmax - height[r];

                else
                    rightmax = height[r];
                r = r - 1;
            }
        }
        return trappingWater;
    }
};