
class Solution{
bool static myComparator(vector<int>a, vector<int>b){
	// compare 2nd ele of given each pair
	return a[1]<b[1];
}
public:

int eraseOverlapIntervals(vector<vector<int>>&intervals) {
    // sort bases of end time 
    sort(intervals.begin(), intervals.end(), myComparator);

    int cnt = 1;
    int lastEndTime = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= lastEndTime) {
            cnt += 1;
            lastEndTime = intervals[i][1];
        }
    }

    return intervals.size() - cnt;
}
};
