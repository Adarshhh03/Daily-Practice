
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[low]==nums[mid]&&nums[mid]==nums[high]){
                high=high-1;
                low=low+1;
                continue;
            }

            if(nums[low]<=nums[mid]){
                if(nums[low]<=target&&nums[mid]>target){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else{
                if (nums[mid] < target && target <= nums[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};