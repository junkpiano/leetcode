/**
 * @file 20.cpp
 * @author Yusuke Ohashi (mail@yusuke.cloud)
 * @brief 
 * @version 0.1
 * @date 2022-08-22
 * 
 * @copyright Copyright (c) 2022 Yusuke Ohashi
 * 
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#if defined(__APPLE__) && defined(__MACH__)
#undef assert
#endif

#ifdef NDEBUG
#define assert(condition, message) 0
#else
#define assert(condition, message) \
    (!(condition)) ? \
    (std::cerr << "Assertion failed: (" << #condition << "), " \
    << "function: " << __FUNCTION__ \
    << ", file: " << __FILE__ \
    << ", line: " << __LINE__ \
    << std::endl << message << std::endl, abort(), 0): 1
#endif

class Solution {
    public:
        bool isValid(string s) {
            stack<char> p;

            for(int i = 0; i < s.length(); i++) {
                char ch = s[i];

                if(ch == '(' || ch == '{' || ch == '[') {
                    p.push(ch);
                } else {
                    if (p.size() == 0)
                        return false; // invalid opening parentheses.

                    if (ch == ')' && p.top() == '(') {
                        p.pop();
                    } else if (ch == '}' && p.top() == '{') { 
                        p.pop();
                    } else if (ch == ']' && p.top() == '[') { 
                        p.pop();
                    } else {
                        return false;
                    }
                }
            }

            return p.size() == 0;
        }
};

int main() {
    Solution s = Solution();

    assert(s.isValid("{[]}") == true, "This string should be valid");
    assert(s.isValid("]}") == false, "This string should be invalid");
    assert(s.isValid("]") == false, "This string should be invalid");

    return 0;
}
