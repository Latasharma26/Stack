#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <limits>

class Solution {
public:
    int longestSquareStreak(std::vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        std::sort(nums.begin(), nums.end());

        int maxLength = 0;

        for (int num : nums) {
            int currentLength = 1;
            long long currentNum = num;

            // Continue as long as the square of currentNum exists in the set and avoid overflow
            while (currentNum <= std::numeric_limits<int>::max() / currentNum && numSet.find(currentNum * currentNum) != numSet.end()) {
                currentNum = currentNum * currentNum;
                currentLength++;
            }

            // Update maxLength if a longer streak is found
            maxLength = std::max(maxLength, currentLength);
        }

        return maxLength >= 2 ? maxLength : -1;
    }
};
