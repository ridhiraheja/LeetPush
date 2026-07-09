class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        // We stop when low == high, which points to the single element
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // Check if mid is in the left half or right half
            if (nums[mid] == nums[mid ^ 1]) {
                // Left half pattern matches, single element is on the right
                low = mid + 1;
            } else {
                // Pattern broken, single element is to the left (or is mid itself)
                high = mid;
            }
        }
        
        return nums[low];
    }
};