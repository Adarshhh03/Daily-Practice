class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mpp;
            for (int j = i; j < n; j++) {
                mpp[s[j]]++;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                for (auto [ch, freq] : mpp) {
                    maxi = max(maxi, freq);
                    mini = min(mini, freq);  // only non-zero freq counted
                }

                ans += (maxi - mini);
            }
        }
        return ans;
    }
};
