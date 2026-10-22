void enqueue(int x) {
    if (n == 100) {
        cout << "Queue day" << endl;
        return;
    }

    chenCuoi(x);
}

void dequeue() {
    if (n == 0) {
        cout << "Queue rong" << endl;
        return;
    }

    xoaDau();
}

void front() {
    if (n == 0) {
        cout << "Queue rong" << endl;
        return;
    }

    layPhanTu(0);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Queue ban dau:" << endl;
    inXuoi();

    cout << "Phan tu dau hang doi:" << endl;
    front();

    cout << "Sau khi dequeue:" << endl;
    dequeue();
    inXuoi();

    cout << "Them 40:" << endl;
    enqueue(40);
    inXuoi();

    return 0;
}
