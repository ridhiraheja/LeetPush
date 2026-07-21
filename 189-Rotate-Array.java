class Solution {
    public void rotate(int[] nums, int k) {
        int[] result = new int[nums.length];
        k=k%nums.length;
	    for (int i = 0; i < k; i++) {
            result[i] = nums[nums.length - k + i];
	    }
	    int j = 0;
        for (int i = k; i < nums.length; i++) {
            result[i] = nums[j];
            j++;
        }
        System.arraycopy(result, 0, nums, 0, nums.length);
    }
}