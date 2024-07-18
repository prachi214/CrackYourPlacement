//Maximum Points You Can Obtain from Cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

       int leftSum = 0, rightSum = 0, maxSum = 0;
    //    left part
       for(int i=0;i<k;i++) {
leftSum+= cardPoints[i];
       }
       maxSum = leftSum;
      int  rightIndex = cardPoints.size() - 1;
    //    right part

       for(int i = k-1;i>=0;i--){
        leftSum-= cardPoints[i];
        rightSum+= cardPoints[rightIndex];
        rightIndex--;
        maxSum= max(maxSum, leftSum + rightSum);
       }
       
return maxSum;
    }
};