class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        
        int pivot = -1;
        int l = 0;
        int h = n - 1;
        int last_el = nums[n - 1]; 

        while (l <= h) {
            int mid = l + (h - l) / 2;
            
            if (nums[mid] > last_el) {
                
                l = mid + 1;
            } else {
                
                pivot = mid; 
                h = mid - 1;
            }
        }
        
        
        l = 0;
        h = n - 1;
        
        
        if (pivot > 0) {
            if (target >= nums[pivot] && target <= last_el) {
                l = pivot;
            } else {
                h = pivot - 1;
            }
        }
        
        
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) return mid;
            
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        
        return -1;
    }
};