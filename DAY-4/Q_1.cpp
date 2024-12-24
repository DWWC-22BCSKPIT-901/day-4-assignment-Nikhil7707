/*Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
Example 1:
Input: s = "leetcode"
Output: 0
*/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> char_count;
    queue<int> q;

    for (int i = 0; i < s.size(); i++) {
        char_count[s[i]]++;
        q.push(i);

        while (!q.empty() && char_count[s[q.front()]] > 1) {
            q.pop();
        }
    }

    return q.empty() ? -1 : q.front();
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = firstUniqChar(s);
    if (result != -1)
        cout << "The index of the first non-repeating character is: " << result << endl;
    else
        cout << "No non-repeating character found." << endl;

    return 0;
}
