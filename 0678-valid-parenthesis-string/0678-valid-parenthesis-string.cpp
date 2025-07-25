class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0; // min and max number of open brackets
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else { // c == '*'
                minOpen--;  // treat * as )
                maxOpen++;  // treat * as (
            }

            if (maxOpen < 0) return false; // too many closing
            if (minOpen < 0) minOpen = 0;  // open can't be negative,means we cant take it as ),so we consider it is empty
        }
        return minOpen == 0;
    }
};
