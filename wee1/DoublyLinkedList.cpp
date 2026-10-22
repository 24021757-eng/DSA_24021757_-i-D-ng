#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

DNode* taoNut(int x) {
    DNode* p = new DNode{x, nullptr, nullptr};
    return p;
}

void chenDau(DNode *&head, int x) {
    DNode* p = taoNut(x);

    p->next = head;

    if (head != nullptr) {
        head->prev = p;
    }

    head = p;
}

void chenCuoi(DNode *&head, int x) {
    DNode* p = taoNut(x);

    if (head == nullptr) {
        head = p;
        return;
    }

    DNode* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = p;
    p->prev = temp;
}

void chenViTri(DNode *&head, int x, int k) {
    if (k <= 0 || head == nullptr) {
        chenDau(head, x);
        return;
    }

    DNode* temp = head;
    int i = 0;

    while (i < k - 1 && temp->next != nullptr) {
        temp = temp->next;
        i++;
    }

    DNode* p = taoNut(x);
    DNode* sau = temp->next;

    p->prev = temp;
    p->next = sau;
    temp->next = p;

    if (sau != nullptr) {
        sau->prev = p;
    }
}

void xoaDau(DNode *&head) {
    if (head == nullptr) {
        return;
    }

    DNode* p = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete p;
}

void xoaCuoi(DNode *&head) {
    if (head == nullptr) {
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    DNode* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    DNode* truoc = temp->prev;
    truoc->next = nullptr;

    delete temp;
}

void xoaViTri(DNode *&head, int k) {
    if (head == nullptr || k < 0) {
        return;
    }

    if (k == 0) {
        xoaDau(head);
        return;
    }

    DNode* temp = head;
    int i = 0;

    while (temp != nullptr && i < k) {
        temp = temp->next;
        i++;
    }

    if (temp == nullptr) {
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

int timViTri(DNode* head, int x) {
    DNode* temp = head;
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

void inDanhSach(DNode* head) {
    for (DNode* p = head; p != nullptr; p = p->next) {
        cout << p->data << " ";
    }

    cout << endl;
}

void inNguoc(DNode* head) {
    if (head == nullptr) {
        return;
    }

    DNode* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    for (DNode* p = temp; p != nullptr; p = p->prev) {
        cout << p->data << " ";
    }

    cout << endl;
}

int main() {
    DNode* head = nullptr;

    cout << "Tao node:" << endl;

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

    cout << "Xoa vi tri cuoi" << endl;
    xoaCuoi(head);
    inDanhSach(head);

    cout << "Xoa vi tri thu 2" << endl;
    xoaViTri(head, 1);
    inDanhSach(head);

    cout << "In nguoc node" << endl;
    inNguoc(head);

    while (head != nullptr) {
        xoaDau(head);
    }

    return 0;
}
