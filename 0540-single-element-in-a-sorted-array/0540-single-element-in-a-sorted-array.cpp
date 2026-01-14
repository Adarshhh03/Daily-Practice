class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        // Initialize search space (excluding first and last elements, which are checked separately)
        int low = 1;
        int high = nums.size() - 2;

        // Edge case: If there's only one element, return it
        if (nums.size() == 1) return nums[0];

        // Check if the first element is the single element
        if (nums[0] != nums[1])
            return nums[0];

        // Check if the last element is the single element
        if (nums[high] != nums[high + 1])
            return nums[high + 1];

        // Perform binary search
        while (low <= high) {
            int mid = (low + high) / 2;

            // Check if mid is the single non-duplicate element
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            // If mid is even
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) {
                    // If mid and mid+1 are equal, the unique element must be on the right,as pairs start at even index,the next element would be same
                    low = mid + 1;
                } else {
                    // Otherwise, the unique element is on the left
                    high = mid - 1;
                }
            }
            // If mid is odd
            else {
                if (nums[mid] == nums[mid - 1]) {
                    // If mid and mid-1 are equal, the unique element must be on the right,as the 2nd element will be on odd position it should be on left and the answer will be in the riht part
                    low = mid + 1;
                } else {
                    // Otherwise, the unique element is on the left
                    high = mid - 1;
                }
            }
        }

        // This line should never be reached because a unique element is guaranteed to exist
        return -1;
    }
};
