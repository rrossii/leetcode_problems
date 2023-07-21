#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        while (head != nullptr) {
            if (head->val == INT32_MAX) {
                return true;
            }
            head->val = INT32_MAX;
            head = head->next;
        }
        return false;
    }
};