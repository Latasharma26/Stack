#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Stack to keep track of opening brackets
        stack<char> st;
        
        // Mapping of closing to opening brackets
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        // Iterate over each character in the string
        for (char c : s) {
            // If it's a closing bracket
            if (bracketMap.count(c)) {
                // Check if stack is empty or top of stack does not match
                if (st.empty() || st.top() != bracketMap[c]) {
                    return false;
                }
                // If matched, pop the stack
                st.pop();
            } 
            // Otherwise, it's an opening bracket, so push to stack
            else {
                st.push(c);
            }
        }
        
        // In the end, stack should be empty if all brackets are balanced
        return st.empty();
    }
};
