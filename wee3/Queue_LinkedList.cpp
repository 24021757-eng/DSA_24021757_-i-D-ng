void enqueue(Node *&head, int x) {
    chenCuoi(head, x);
}

void dequeue(Node *&head) {
    if (head == nullptr) {
        cout << "Queue rong" << endl;
        return;
    }

    xoaDau(head);
}

void front(Node* head) {
    if (head == nullptr) {
        cout << "Queue rong" << endl;
        return;
    }

    cout << head->data << endl;
}

int main() {
    Node* head = nullptr;

    enqueue(head, 10);
    enqueue(head, 20);
    enqueue(head, 30);

    cout << "Queue ban dau:" << endl;
    inDanhSach(head);

    cout << "Phan tu dau hang doi:" << endl;
    front(head);

    cout << "Sau khi dequeue:" << endl;
    dequeue(head);
    inDanhSach(head);

    cout << "Them 40:" << endl;
    enqueue(head, 40);
    inDanhSach(head);

    while (head != nullptr) {
        xoaDau(head);
    }

    return 0;
}

