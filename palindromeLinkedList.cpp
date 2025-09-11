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

        ListNode* prev = NULL, *current = mid, *temp;
        // Reverse from mid to end
        while(current){
            temp = current;
            current->next = prev;
            prev = current;
            current = temp->next;          
        }

        ListNode* tailHead;
        tailHead = prev;

        bool check = false;

        ListNode* counter = head;

        while(tailHead){
            if(counter == tailHead){
                check = true;
            }
            else{
                check = false;
            }
            counter = counter->next;
            tailHead = tailHead->next;
        }

        if(check){
            return true;
        }

        return false;

        



    }
};