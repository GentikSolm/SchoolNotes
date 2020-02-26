#ifndef CHARLIST_HPP
#define CHARLIST_HPP

class CharList{
private:
    struct ListNode{
        char value;
        ListNode *next;
    };
    ListNode *head;
public:
    CharList(){head = nullptr;}
    void displayList() const;
    void appendNode(char);
    void insertNode(char);
    void deleteNode(char);
    ~CharList();
};

#endif
