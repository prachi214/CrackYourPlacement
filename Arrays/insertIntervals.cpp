class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       int i =0, j= 0;
        vector<vector<int>>res;
        int n = intervals.size();
        //left
        while(i<n && intervals[i][1] < newInterval[0]){
res.push_back(intervals[i]);
i++;
        }
        // overlapping part
                while(i<n && intervals[i][0] <= newInterval[1]){
            //start time
newInterval[0]  = min(newInterval[0], intervals[i][0]);
      //end time
newInterval[1]  = max(newInterval[1], intervals[i][1]);
i++;
        }
        res.push_back(newInterval);

//right part
while(i<n){
    res.push_back(intervals[i]);
    i++;
}
return res;
    }
};