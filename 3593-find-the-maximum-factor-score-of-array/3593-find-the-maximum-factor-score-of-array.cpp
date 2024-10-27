class Solution {
public:
    long long maxScore(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return static_cast<long long>(nums[0]) * nums[0];

        // Function to calculate LCM of two numbers
        auto lcm = [](long long a, long long b) {
            return (a * b) / std::gcd(a, b);
        };

        // Calculate the overall GCD and LCM of the entire array
        long long totalGCD = nums[0];
        long long totalLCM = nums[0];
        for (int i = 1; i < n; ++i) {
            totalGCD = std::gcd(totalGCD, nums[i]);
            totalLCM = lcm(totalLCM, nums[i]);
        }

        // Start with the score without removing any element
        long long maxScore = totalGCD * totalLCM;

        // Check max score for the array with each element removed
        for (int i = 0; i < n; ++i) {
            long long currGCD = 0, currLCM = 1;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                currGCD = currGCD == 0 ? nums[j] : std::gcd(currGCD, nums[j]);
                currLCM = lcm(currLCM, nums[j]);
            }
            maxScore = std::max(maxScore, currGCD * currLCM);
        }

        return maxScore;
    }
};