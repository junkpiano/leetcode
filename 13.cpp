/**
 * @file 13.cpp
 * @author Yusuke Ohashi (mail@yusuke.cloud)
 * @brief 
 * @version 0.1
 * @date 2022-07-31
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
	int romanToInt(string s) {
		char prev;
		char curr;

		int result = 0;
		
		for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
			prev = curr;
			curr = ch;

			switch(curr) {
				case 'I':
					result += 1;
					break;
				case 'V':
					if (prev == 'I') {
						result += 4 - 1;
					} else {
						result += 5;
					}
					break;
				case 'X':
					if (prev == 'I') {
						result += 9 - 1;
					} else {
						result += 10;
					}
					break;
				case 'L':
					if (prev == 'X') {
						result += 40 - 10;
					} else {
						result += 50;
					}
					break;
				case 'C':
					if (prev == 'X') {
						result += 90 - 10;
					} else {
						result += 100;
					}
					break;
				case 'D':
					if (prev == 'C') {
						result += 400 - 100;
					} else {
						result += 500;
					}
					break;
				case 'M':
					if (prev == 'C') {
						result += 900 - 100;
					} else {
						result += 1000;
					}
					break;
				default:
					break;
			}			
		}

		return result;
	}
};

int main() {
	Solution s = Solution();
	cout << s.romanToInt("III") << endl;
	cout << s.romanToInt("LVIII") << endl;
	cout << s.romanToInt("MCMXCIV") << endl;
	return 1;
}