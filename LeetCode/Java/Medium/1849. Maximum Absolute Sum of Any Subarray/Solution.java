
class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int maxSum = 0;
        int minSum = 0;

        int currMax = 0;
        int currMin = 0;

        for (int num : nums) {
            currMax = Math.max(0, currMax + num);
            currMin = Math.min(0, currMin + num);

            maxSum = Math.max(maxSum, currMax);
            minSum = Math.min(minSum, currMin);
        }

        return Math.max(maxSum, Math.abs(minSum));
    }
}
