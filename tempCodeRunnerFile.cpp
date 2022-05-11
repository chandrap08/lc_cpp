    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    
    ListNode* head = new ListNode;
    auto tail = head;
    while(list1 && list2){
        //AppendNode(list1->val <= list2->val ? list1:list2, tail);
        if(list1->val <= list2->val){
            tail->next = list1;
            list1 = list1->next;
        }
        else{
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    tail->next = list1? list1:list2;
    return head->next;