#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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
        bool __solution_function() {
            return false;
        }
};

int main() {
    Solution s = Solution();

    // test cases comes here.
    
    return 0;
}
