/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
      
    //Function to find the maximum profit and the number of jobs done.
    vector<int>JobScheduling(Job arr[], int n) 
    { 
vector<int>ans;

// sort on the bases of max profit
      sort(arr, arr + n, comparison);
      int maxi = arr[0].dead;
    //   maximumdeadline
      for (int i = 1; i < n; i++) {
         maxi = max(maxi, arr[i].dead);
      }

      int hash[maxi + 1];

      for (int i = 0; i <= maxi; i++)
         hash[i] = -1;

      int countJobs = 0, jobProfit = 0;

      for (int i = 0; i < n; i++) {
        //  do job on max day 
         for (int j = arr[i].dead; j > 0; j--) {
            if (hash[j] == -1) {
               hash[j] = i;
               countJobs++;
               jobProfit += arr[i].profit;
            //    out from loop
               break;
               
            }
         }
      }

ans.push_back(countJobs);
ans.push_back(jobProfit);
      return ans;
    } 
};
