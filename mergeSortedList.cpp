/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2){
            return NULL;
        }

        if(!list1){
            return list2;
        }

        if(!list2){
            return list1;
        }
        
        ListNode* current = list1, *current2 = list2, *prev = NULL, *head;

        while(current &&  current2){
            if(current->val <= current2->val){
                if(current == list1 && current2 == list2){
                    prev = current;
                    head = current;
                    current = current->next;
                }
                else{
                    prev->next = current;
                    prev = current;
                    current = current->next;
                }

            }
            else{
                if(current == list1 && current2 == list2){
                    prev = current2;
                    head = current2;
                    current2 = current2->next;
                }
                else{
                    prev->next = current2;
                    prev = current2;
                    current2 = current2->next;
                }
            }
        }

        
        if(!current){
            current = list1;

            while(current->next != NULL){
                current = current->next;
            }

                current->next = current2;
            

        }
        
        if(!current2){
            current2 = list2;

            while(current2->next != NULL){
                current2 = current2->next;
            }

            
                current2->next = current;
                
            
        }

        return head;

            
        
    }
};