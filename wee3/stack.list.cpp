#include <iostream>
using namespace std;

int arr[100];
int n = 0;

void layPhanTu(int vitri) {
    cout << arr[vitri] << endl;
}

void chenCuoi(int x) {
    arr[n++] = x;
}

void chenDau(int x) {
    int i = n;

    while (i > 0) {
        arr[i] = arr[i - 1];
        i--;
    }

    arr[0] = x;
    n++;
}

void chenViTri(int x, int vitri) {
    int i = n;

    while (i > vitri) {
        arr[i] = arr[i - 1];
        i--;
    }

    arr[vitri] = x;
    n++;
}

void xoaDau() {
    int i = 0;

    while (i < n - 1) {
        arr[i] = arr[i + 1];
        i++;
    }

    n--;
}

void xoaCuoi() {
    --n;
}

void xoaViTri(int vitri) {
    int i = vitri;

    while (i < n - 1) {
        arr[i] = arr[i + 1];
        i++;
    }

    n--;
}

void inXuoi() {
    int i = 0;

    while (i < n) {
        cout << arr[i] << " ";
        i++;
    }

    cout << endl;
}

void inNguoc() {
    int i = n - 1;

    while (i >= 0) {
        cout << arr[i] << " ";
        i--;
    }

    cout << endl;
}

void push(int x) {
    if (n == 100) {
        cout << "Stack day" << endl;
        return;
    }

    chenCuoi(x);
}

void pop() {
    if (n == 0) {
        cout << "Stack rong" << endl;
        return;
    }

    xoaCuoi();
}

void top() {
    if (n == 0) {
        cout << "Stack rong" << endl;
        return;
    }

    layPhanTu(n - 1);
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Stack ban dau:" << endl;
    inXuoi();

    cout << "Phan tu tren cung:" << endl;
    top();

    cout << "Sau khi pop:" << endl;
    pop();
    inXuoi();

    cout << "Them 40:" << endl;
    push(40);
    inXuoi();

    return 0;
}

