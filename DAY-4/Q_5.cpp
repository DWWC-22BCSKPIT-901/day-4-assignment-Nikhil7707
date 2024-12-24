/*Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
Example 1:
Input: s = "(()"
Output: 2
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int maxLength = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            
            if (st.empty()) {
                st.push(i);
            } else {
                maxLength = max(maxLength, i - st.top());
            }
        }
    }

    return maxLength;
}

int main() {
    string s;
    cout << "Enter a string containing just '(' and ')': ";
    cin >> s;

    int result = longestValidParentheses(s);
    cout << "The length of the longest valid parentheses substring is: " << result << endl;

    return 0;
}
