class Solution {
public:
    int minimumMountainRemovals(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> LIS(n, 1), LDS(n, 1);

        // Calculate Longest Increasing Subsequence (LIS) up to each index
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    LIS[i] = std::max(LIS[i], LIS[j] + 1);
                }
            }
        }

        // Calculate Longest Decreasing Subsequence (LDS) from each index
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    LDS[i] = std::max(LDS[i], LDS[j] + 1);
                }
            }
        }

        // Calculate the minimum removals to make a mountain array
        int minRemovals = n;
        for (int i = 1; i < n - 1; ++i) {
            if (LIS[i] > 1 && LDS[i] > 1) { // valid peak
                int mountainLength = LIS[i] + LDS[i] - 1;
                minRemovals = std::min(minRemovals, n - mountainLength);
            }
        }

        return minRemovals;
    }
};