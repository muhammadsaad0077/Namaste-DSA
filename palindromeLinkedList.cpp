class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid, *fast;
        mid = fast = head;
        //Mid Finding
        while(fast && fast->next){
            mid = mid->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL, *current = mid, *firstNode = head, *temp;
        // Reverse from mid to end
        while(current){
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;          
        }

        current = prev;

        bool isEqual = true;

        while(current){
            if(firstNode->val != current->val){
                isEqual = false;
                break;
            }
            
            firstNode = firstNode->next;
            current = current->next;
        }

        
        
        return isEqual;


    }
};