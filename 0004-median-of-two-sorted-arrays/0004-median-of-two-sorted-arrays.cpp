class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            // Ensure nums1 starts with smaller number
        if (!nums1.empty() && !nums2.empty() && nums1[0] > nums2[0]) {
            swap(nums1, nums2);
        }

        int left = nums1.size() - 1;
        int right = 0;
        int n2 = nums2.size();

        // Balance the arrays so that nums1 has smaller elements
        while (left >= 0 && right < n2) {
            if (nums2[right] < nums1[left]) {
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            } else {
                right++;
            }
        }

        // Sort both arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // Merge both arrays conceptually
        int total = nums1.size() + nums2.size();
        if (total % 2 == 1) {
            // Odd number of elements: return middle
            int medianIndex = total / 2;
            if (medianIndex < nums1.size()) {
                return (double)nums1[medianIndex];
            } else {
                return (double)nums2[medianIndex - nums1.size()];
            }
        } else {
            // Even number of elements: return average of two middles
            int medianIndex1 = total / 2 - 1;
            int medianIndex2 = total / 2;
            int val1, val2;

            if (medianIndex1 < nums1.size()) {
                val1 = nums1[medianIndex1];
            } else {
                val1 = nums2[medianIndex1 - nums1.size()];
            }

            if (medianIndex2 < nums1.size()) {
                val2 = nums1[medianIndex2];
            } else {
                val2 = nums2[medianIndex2 - nums1.size()];
            }

            return ((double)val1 + val2) / 2.0;
        }
    }
};