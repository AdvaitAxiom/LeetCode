https://leetcode.com/problems/clear-digits/description/

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;  // Stack to store non-digit characters

    for (char ch : s) {
        if (isdigit(ch)) {
            // Remove the closest non-digit character to the left
            if (!st.empty() && !isdigit(st.top())) {
                st.pop();
            }
        } else {
            // Push non-digit characters onto the stack
            st.push(ch);
        }
    }

    // Reconstruct the final string
    string result;
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;
    }
};