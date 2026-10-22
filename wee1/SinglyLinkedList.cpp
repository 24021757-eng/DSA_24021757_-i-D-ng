#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* taoNut(int x) {
    Node* p = new Node{x, nullptr};
    return p;
}

void chenDau(Node *&head, int x) {
    Node* p = taoNut(x);
    p->next = head;
    head = p;
}

void chenCuoi(Node *&head, int x) {
    Node* p = taoNut(x);

    if (head == nullptr) {
        head = p;
    }
    else {
        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = p;
    }
}

void chenViTri(Node *&head, int x, int k) {
    if (k < 0 || head == nullptr) {
        chenDau(head, x);
        return;
    }

    Node* temp = head;
    int i = 0;

    while (i < k - 1 && temp->next != nullptr) {
        temp = temp->next;
        i++;
    }

    Node* p = taoNut(x);
    Node* sau = temp->next;

    temp->next = p;
    p->next = sau;
}

void xoaDau(Node *&head) {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    head = temp->next;
    delete temp;
}

void xoaCuoi(Node *&head) {
    if (head == nullptr) {
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    Node* cuoi = temp->next;
    temp->next = nullptr;
    delete cuoi;
}

void xoaViTri(Node *&head, int k) {
    if (head == nullptr || k < 0) {
        return;
    }

    if (k == 0) {
        xoaDau(head);
        return;
    }

    Node* temp = head;
    int i = 0;

    while (i < k - 1 && temp->next != nullptr) {
        temp = temp->next;
        i++;
    }

    if (temp->next == nullptr) {
        return;
    }

    Node* p = temp->next;
    temp->next = p->next;
    delete p;
}

int timViTri(Node* head, int x) {
    Node* temp = head;
    int vitri = 0;

    while (temp != nullptr) {
        if (temp->data == x) {
            return vitri;
        }

        temp = temp->next;
        vitri++;
    }

    return -1;
}

void inDanhSach(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void inNguoc(Node* head) {
    if (head != nullptr) {
        inNguoc(head->next);
        cout << head->data << " ";
    }
}

int main() {
    Node* head = nullptr;

    cout << "Tao chuoi node" << endl;
    chenDau(head, 10);
    chenCuoi(head, 20);
    chenCuoi(head, 30);
    chenCuoi(head, 40);
    inDanhSach(head);

    cout << "Chen vao vi tri thu 2" << endl;
    chenViTri(head, 15, 1);
    inDanhSach(head);

    cout << "Xoa vi tri dau" << endl;
    xoaDau(head);
    inDanhSach(head);

    cout << "Xoa vi tri cuoi:" << endl;
    xoaCuoi(head);
    inDanhSach(head);

    cout << "Xoa vi tri thu 2" << endl;
    xoaViTri(head, 1);
    inDanhSach(head);

    cout << "Duyet nguoc:" << endl;
    inNguoc(head);

    while (head != nullptr) {
        xoaDau(head);
    }

    return 0;
}

