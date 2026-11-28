class MyLinkedList {
public:
struct Node{
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        next = nullptr;
    }
};
Node* head;
    MyLinkedList() {
        head = new Node(-1);
    }
    
    int get(int i) {
        Node* tmp = head->next;
        if(tmp == nullptr) return -1;

        int cnt = 0;
        while(tmp!=nullptr){
            if(cnt==i) return tmp->val;
            tmp = tmp->next;
            cnt++;
        }
        return -1;  
    }
    
    void addAtHead(int val) {
        Node* k = new Node(val);
        k->next = head->next;
        head->next = k;
    }
    
    void addAtTail(int val) {
        Node* k = new Node(val);
        Node* tmp = head;

        while(tmp->next!=nullptr){
            tmp = tmp->next;
        }
        tmp->next = k;
    }
    
    void addAtIndex(int i, int val) {
    if (i < 0) return;

    Node* tmp = head;
    int cnt = 0;

    while (tmp != nullptr && cnt < i) {
        tmp = tmp->next;
        cnt++;
    }

    if (tmp == nullptr) return;

    Node* k = new Node(val);
    k->next = tmp->next;
    tmp->next = k;
}
    
    void deleteAtIndex(int i) {
    if (i < 0) return;

    Node* tmp = head;
    int cnt = 0;

    while (tmp->next != nullptr && cnt < i) {
        tmp = tmp->next;
        cnt++;
    }

    if (tmp->next == nullptr) return;

    Node* k = tmp->next;
    tmp->next = k->next;

    delete k;
}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */