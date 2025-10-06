class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();

        unordered_map<int,int> mp;  //sum,count
        mp[0]=1;

        int count=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            int x=sum-k;

            if(mp.find(x) != mp.end()){
            count+=mp[x];
            }

            mp[sum]++;
        }

        return count;
    }
};