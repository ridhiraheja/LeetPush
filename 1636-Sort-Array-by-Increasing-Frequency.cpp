class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int, int> freq;

        // Count frequency
        for (int num : nums) {
            freq[num]++;
        }

        // Sort according to the rules
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b]) {
                return a > b;      // Same frequency -> larger number first
            }
            return freq[a] < freq[b]; // Smaller frequency first
        });

        return nums;
        
    }
};