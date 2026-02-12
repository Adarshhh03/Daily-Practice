class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int numJobs = profit.size(); // Number of jobs
        vector<tuple<int, int, int>> jobs(numJobs);
      
        for (int i = 0; i < numJobs; ++i) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
      
        sort(jobs.begin(), jobs.end());   //sort by start time
        vector<int> dp(numJobs + 1);
      
        for (int i = 0; i < numJobs; ++i) {
            auto [endTime, startTime, profit] = jobs[i];
          
          // gives index of first job with endTime > startTime, so we consider a job with endTime <= current startTime
          /*
uper_bound returns the first job where endTime > startTime.
But that is exactly what we need.
Reason:
Jobs are sorted by endTime.
Suppose binary search gives index = k.
That means:
jobs[0] … jobs[k-1] → endTime ≤ startTime
jobs[k] → endTime > startTime
So the previous job with
endTime ≤ startTime
is at index k-1.
But notice:
We are not trying to access job k-1 directly.
We are using:
dp[latestNonConflictJobIndex]
And dp meaning is:
dp[x] = maximum profit using first x jobs.
So:
dp[k]
already represents the best profit among
jobs[0] … jobs[k-1]
Which are exactly the compatible jobs.
That is why we do NOT subtract 1.
Binary search gives the boundary.
DP array is built to use that boundary directly.
Key mapping:
Jobs index: 0 1 2 3 4
DP index: 1 2 3 4 5
dp[i] uses first i jobs.
So if binary search returns k,
dp[k] automatically means:
"Best profit from all jobs with endTime ≤ startTime"
No adjustment needed.
The confusion comes from mixing:
*/
            int latestNonConflictJobIndex = upper_bound(jobs.begin(), jobs.begin() + i, startTime, [&](int time, const auto& job) -> bool {
                return time < get<0>(job);
            }) - jobs.begin();  
          
            dp[i + 1] = max(dp[i], dp[latestNonConflictJobIndex] + profit);
        }
      
        return dp[numJobs];
    }
};