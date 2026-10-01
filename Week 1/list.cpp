#include <iostream>

struct Node {
    int val;
    Node* prev;
    Node* next;
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;
};

DoublyLinkedList* createList() {
    DoublyLinkedList* lst = new DoublyLinkedList;
    lst->head = nullptr;
    lst->tail = nullptr;
    return lst;
}

Node* makeNode(int value) {
    return new Node{value, nullptr, nullptr};
}

Node* getNodeAt(DoublyLinkedList* lst, int index) {
    if (!lst) return nullptr;
    Node* curr = lst->head;
    int pos = 0;
    while (curr && pos < index) {
        curr = curr->next;
        pos++;
    }
    return curr;
}

int getSize(DoublyLinkedList* lst) {
    if (!lst) return 0;
    int len = 0;
    for (Node* curr = lst->head; curr != nullptr; curr = curr->next) {
        len++;
    }
    return len;
}

void pushFront(DoublyLinkedList* lst, int value) {
    if (!lst) return;
    Node* newNode = makeNode(value);
    if (!lst->head) {
        lst->head = lst->tail = newNode;
        return;
    }
    newNode->next = lst->head;
    lst->head->prev = newNode;
    lst->head = newNode;
}

void pushBack(DoublyLinkedList* lst, int value) {
    if (!lst) return;
    Node* newNode = makeNode(value);
    if (!lst->tail) {
        lst->head = lst->tail = newNode;
        return;
    }
    newNode->prev = lst->tail;
    lst->tail->next = newNode;
    lst->tail = newNode;
}

void insertAt(DoublyLinkedList* lst, int value, int index) {
    if (!lst || index < 0) return;
    if (index == 0) {
        pushFront(lst, value);
        return;
    }
    Node* target = getNodeAt(lst, index);
    if (!target) {
        if (index == getSize(lst)) {
            pushBack(lst, value);
        }
        return;
    }
    Node* newNode = makeNode(value);
    newNode->next = target;
    newNode->prev = target->prev;
    target->prev->next = newNode;
    target->prev = newNode;
}

void popFront(DoublyLinkedList* lst) {
    if (!lst || !lst->head) return;
    Node* temp = lst->head;
    if (lst->head == lst->tail) {
        lst->head = lst->tail = nullptr;
    } else {
        lst->head = lst->head->next;
        lst->head->prev = nullptr;
    }
    delete temp;
}

void popBack(DoublyLinkedList* lst) {
    if (!lst || !lst->tail) return;
    Node* temp = lst->tail;
    if (lst->head == lst->tail) {
        lst->head = lst->tail = nullptr;
    } else {
        lst->tail = lst->tail->prev;
        lst->tail->next = nullptr;
    }
    delete temp;
}

void removeAt(DoublyLinkedList* lst, int index) {
    if (!lst || index < 0) return;
    Node* target = getNodeAt(lst, index);
    if (!target) return;

    if (target == lst->head) {
        popFront(lst);
        return;
    }
    if (target == lst->tail) {
        popBack(lst);
        return;
    }

    target->prev->next = target->next;
    target->next->prev = target->prev;
    delete target;
}

void printForward(DoublyLinkedList* lst) {
    if (!lst) return;
    for (Node* curr = lst->head; curr != nullptr; curr = curr->next) {
        std::cout << curr->val << " ";
    }
    std::cout << "\n";
}

void printBackward(DoublyLinkedList* lst) {
    if (!lst) return;
    for (Node* curr = lst->tail; curr != nullptr; curr = curr->prev) {
        std::cout << curr->val << " ";
    }
    std::cout << "\n";
}

void clearList(DoublyLinkedList* lst) {
    if (!lst) return;
    while (lst->head) {
        popFront(lst);
    }
    delete lst;
}
