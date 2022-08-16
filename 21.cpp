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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if(list1 == nullptr) {
                return list2;
            } else if(list2 == nullptr) {
                return list1;
            } else {
                ListNode* finalList = list1;

                if (list1->val <= list2->val) {
                    list1 = list1->next;
                } else {
                    finalList = list2;
                    list2 = list2->next;
                }

                ListNode* curr = finalList;

                while(list1 && list2) {
                    if (list1->val <= list2->val) {
                        curr->next = list1;
                        list1 = list1->next;
                    } else {
                        curr->next = list2;
                        list2 = list2->next;
                    }

                    curr = curr->next;
                }

                if (!list1) {
                    curr->next = list2;
                } else {
                    curr->next = list1;
                }

                return finalList;
            }        
        }
};

int main() {
    return 0;
}
