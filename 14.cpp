/**
 * @file 14.cpp
 * @author Yusuke Ohashi (mail@yusuke.cloud)
 * @brief Easy
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022 Yusuke Ohashi
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		string curr;
		string prefix;
		
		for (int i = 0; i < strs.size(); i++) {
			curr = strs[i];
			string tempPrefix;

			if (i == 0) {
				prefix = curr;
				continue;
			}

			size_t minLength = min(curr.length(), prefix.length());

			for (int j = 0; j < minLength; j++) {
				if(curr[j] == prefix[j]) {
					tempPrefix += curr[j];
				} else {
					break;
				}
			}

			if (tempPrefix.length() == 0) {
				return "";
			} else {
				size_t prefixLength = min(prefix.length(), tempPrefix.length());
				prefix = prefix.substr(0, prefixLength);
			}
		}

		return prefix;
    }
};

int main() {
	Solution s = Solution();

	vector<string> strs = {"test", "testing"};
	vector<string> single = {"cir","car"};
	vector<string> animals = {"dog", "dog", "do"};
	vector<string> flower = {"flower","flow","flight"};

	cout << s.longestCommonPrefix(strs) << endl;
	cout << s.longestCommonPrefix(single) << endl;
	cout << s.longestCommonPrefix(animals) << endl;
	cout << s.longestCommonPrefix(flower) << endl;
}