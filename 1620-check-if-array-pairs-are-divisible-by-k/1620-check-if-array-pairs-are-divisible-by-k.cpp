
#include <vector>
using namespace std;

/*
 The code will run faster with ios::sync_with_stdio(0).
 However, this should not be used in production code and interactive problems.
 In this particular problem, it is ok to apply ios::sync_with_stdio(0).

 Many of the top-ranked C++ solutions for time on leetcode apply this trick,
 so, for a fairer assessment of the time percentile of my code
 you could outcomment the lambda expression below for a faster run.
*/

/*
 const static auto speedup = [] {
    ios::sync_with_stdio(0);
    return nullptr;
}();
*/

class Solution {

public:
    bool canArrange(const vector<int>& input, int divisor) const {
        vector<int> frequency(divisor + 1);
        for (const auto& value : input) {
            int remainder = ((value % divisor) + divisor) % divisor;
            ++frequency[remainder];
        }

        if (frequency[0] % 2 != 0) {
            return false;
        }
        for (int i = divisor / 2; i >= 1; --i) {
            if (frequency[i] != frequency[divisor - i]) {
                return false;
            }
        }

        return true;
    }
};