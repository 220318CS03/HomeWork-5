#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node() {
        value = 0;
        next = nullptr;
    }

    Node(int x) {
        value = x;
        next = nullptr;
    }

    Node(int x, Node* n) {
        value = x;
        next = n;
    }
};

class List {
private:
    Node* head;

public:
    List() {
        head = nullptr;
    }

    Node* insert_front(int x) {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        return head;
    }

    Node* insert_back(int x) {
        Node* temp = new Node(x);
        if (head == nullptr) {
            head = temp;
            return head;
        }
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = temp;
        return head;
    }

    Node* erase_front() {
        if (head == nullptr) {
            return nullptr;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* erase_back() {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return nullptr;
        }
        Node* curr = head;
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }
        delete curr->next;
        curr->next = nullptr;
        return head;
    }

    void displayList() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    int size() {
        int count = 0;
        Node* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    void bubbleSort() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        Node* curr = head;
        Node* nextNode;
        bool swapped;
        do {
            swapped = false;
            curr = head;
            while (curr->next != nullptr) {
                nextNode = curr->next;
                if (curr->value > nextNode->value) {
                    swap(curr->value, nextNode->value);
                    swapped = true;
                }
                curr = curr->next;
            }
        } while (swapped);
    }

    void selectionSort() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        Node* curr = head;
        Node* minNode;
        while (curr->next != nullptr) {
            minNode = curr;
            Node* nextNode = curr->next;
            while (nextNode != nullptr) {
                if (nextNode->value < minNode->value) {
                    minNode = nextNode;
                }
                nextNode = nextNode->next;
            }
            swap(curr->value, minNode->value);
            curr = curr->next;
        }
    }

void quickSort() {
if(head == nullptr || head->next == nullptr) return;
Node *pivot = head, *curr = head->next, *small = nullptr, *large = nullptr, *prev = nullptr;
while(curr != nullptr) {
if(curr->value < pivot->value) {
if(small == nullptr) small = curr;
prev = curr;
curr = curr->next;
}
else {
if(large == nullptr) large = curr;
prev->next = curr->next;
curr->next = nullptr;
large->next = curr;
large = curr;
curr = prev->next;
}
}
List smallList, largeList;
smallList.head = head;
largeList.head = large->next;
large->next = nullptr;
smallList.quickSort();
largeList.quickSort();
if(smallList.head == nullptr) head = pivot;
else {
head = smallList.head;
curr = head;
while(curr->next != nullptr) curr = curr->next;
curr->next = pivot;
}
pivot->next = largeList.head;
}

void insertionSort() {
if(head == nullptr || head->next == nullptr) return;
Node *curr = head->next, *prev_curr = head;
while(curr != nullptr) {
int curr_val = curr->value;
Node *pos = head, *prev_pos = nullptr;
while(pos != curr && curr_val > pos->value) {
prev_pos = pos;
pos = pos->next;
}
if(pos == curr) {
prev_curr = curr;
curr = curr->next;
continue;
}
prev_curr->next = curr->next;
curr->next = pos;
if(pos == head) head = curr;
else prev_pos->next = curr;
curr = prev_curr->next;
}
}
};
int main (int argc , const char * argv []) {
List l ;
l . insert_back (2) ;
l . insert_back (10) ;
l . insert_back (1) ;
l . insert_back (6) ;
l . insert_back (7) ;
l . insert_back (3) ;
l . displayList () ;
l . bubbleSort () ;
l . displayList () ;
List l1 ;
l1 . insert_back (34) ;
l1 . insert_back (1) ;
l1 . insert_back (90) ;
l1 . insert_back (61) ;
l1 . insert_back (57) ;
l1 . insert_back (9) ;
l1 . insert_back (7) ;
l1 . displayList () ;
l1 . selectionSort () ;
l1 . displayList () ;
return 0;
}
