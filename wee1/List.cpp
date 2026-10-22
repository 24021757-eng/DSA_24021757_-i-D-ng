
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

int main() {
    chenCuoi(10);
    chenCuoi(20);
    chenCuoi(30);

    cout << "In vi tri dau:" << endl;
    layPhanTu(1);

    cout << "In xuoi mang:" << endl;
    inXuoi();

    cout << "Chen 5 vao vi tri dau:" << endl;
    chenDau(5);
    inXuoi();

    cout << "Chen 15 vao vi tri thu 3:" << endl;
    chenViTri(15, 2);
    inXuoi();

    cout << "Xoa vi tri dau:" << endl;
    xoaDau();
    inXuoi();

    cout << "Xoa vi tri cuoi:" << endl;
    xoaCuoi();
    inXuoi();

    cout << "Xoa vi tri thu 2:" << endl;
    xoaViTri(1);
    inXuoi();

    cout << "In nguoc mang:" << endl;
    inNguoc();

    return 0;
}

