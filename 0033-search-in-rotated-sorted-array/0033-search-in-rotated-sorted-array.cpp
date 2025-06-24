class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
             if(nums[left]==target) return left;
             if(nums[right]==target) return right;
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }

            if(nums[mid]<=nums[left]){   //right part is sorted
                 if(nums[mid]<=target && nums[right]>=target){   
                left=mid+1;
            }
            else{
                right=mid-1;
            }
            }
            else{
            if(nums[left]<=target && nums[mid]>=target){   
                right=mid-1;
            }
            else{
                left=mid+1;
            }
            }
        }

        return -1;
    }
};