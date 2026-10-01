#include <iostream>

struct SNode {
    int val;
    SNode* next;

    SNode(int v) : val(v), next(nullptr) {}
};

struct SingleLinkedList {
    SNode* head_ = nullptr;
    SNode* tail_ = nullptr;

    SNode* fetchAt(int idx) {
        if (idx < 0) return nullptr;
        SNode* cur = head_;
        for (int k = 0; cur && k < idx; ++k) {
            cur = cur->next;
        }
        return cur;
    }

    void prepend(int val) {
        SNode* node = new SNode(val);
        if (!head_) {
            head_ = tail_ = node;
            return;
        }
        node->next = head_;
        head_ = node;
    }

    void append(int val) {
        SNode* node = new SNode(val);
        if (!head_) {
            head_ = tail_ = node;
            return;
        }
        tail_->next = node;
        tail_ = node;
    }

    void insertAt(int val, int idx) {
        if (idx < 0) return;
        if (idx == 0) {
            prepend(val);
            return;
        }
        SNode* prevNode = fetchAt(idx - 1);
        if (!prevNode) return;
        if (prevNode == tail_) {
            append(val);
            return;
        }
        SNode* node = new SNode(val);
        node->next = prevNode->next;
        prevNode->next = node;
    }

    void removeFront() {
        if (!head_) return;
        SNode* target = head_;
        head_ = head_->next;
        if (!head_) tail_ = nullptr;
        delete target;
    }

    void removeBack() {
        if (!head_) return;
        if (head_ == tail_) {
            delete head_;
            head_ = tail_ = nullptr;
            return;
        }
        SNode* cur = head_;
        while (cur->next != tail_) {
            cur = cur->next;
        }
        delete tail_;
        tail_ = cur;
        tail_->next = nullptr;
    }

    void removeAt(int idx) {
        if (idx < 0 || !head_) return;
        if (idx == 0) {
            removeFront();
            return;
        }
        SNode* prevNode = fetchAt(idx - 1);
        if (!prevNode || !prevNode->next) return;
        SNode* target = prevNode->next;
        if (target == tail_) {
            tail_ = prevNode;
            prevNode->next = nullptr;
        } else {
            prevNode->next = target->next;
        }
        delete target;
    }

    void displayForward() const {
        SNode* cur = head_;
        while (cur) {
            std::cout << cur->val << " ";
            cur = cur->next;
        }
        std::cout << "\n";
    }

    void displayReverse(SNode* node) const {
        if (!node) return;
        displayReverse(node->next);
        std::cout << node->val << " ";
    }

    void displayReverse() const {
        displayReverse(head_);
        std::cout << "\n";
    }

    void clear() {
        while (head_) {
            removeFront();
        }
    }
};
