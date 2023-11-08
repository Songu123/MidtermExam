#include <iostream>
#include <math.h>
#define SIZE 10
#define SORT_ASC 1
#define SORT_DESC 2
#define MENU_NHAP 1
#define MENU_TONG 2
#define MENU_SORT 3
#define MENU_DISPLAY 4
using namespace std;

void hamNhap(int arr[], int size );
bool isPrime(int n);
void tongSoNguyenTo(int arr[], int size);
void swap(int &x, int &y);

void sort(int arr[], int size, int order);
void phanTuXuatHienNhieu(int arr[], int size);

int main() {
    int arr[SIZE];
    bool display = true;
    while(display){
        int choose;
        cout << "\n========MENU========" << endl;
        cout << "1. Nhập các phần tử trong mảng" << endl;
        cout << "2. Tổng các số nguyên tố trong mảng" << endl;
        cout << "3. Sắp xếp mảng" << endl;
        cout << "4. Phần tử xuất hiện nhiều nhất trong mảng" << endl;
        cout << "0. Thoát" << endl;
        cout << "Chọn: ";
        cin >> choose;
        switch(choose){
            case MENU_NHAP:
                cout << "Nhập các phần tử trong mảng" << endl;
                hamNhap(arr, SIZE);
                break;
            case MENU_TONG:
                tongSoNguyenTo(arr, SIZE);
                break;
            case MENU_SORT:
                int order;
                cout << "\n1. Sắp xếp tăng dần" << endl;
                cout << "2. Sắp xếp giảm dần" << endl;
                cout << "Chọn: ";
                cin >> order;
                while (order != SORT_ASC && order != SORT_DESC) {
                    cout << "Nhập sai! Vui lòng chọn lại: ";
                    cin >> order;
                }
                sort(arr, SIZE, order);
                break;
            case MENU_DISPLAY:
                phanTuXuatHienNhieu(arr, SIZE);
                break;
            case 0:
                cout << "Đã thoát chương trình!";
                display = false;
                break;
            default:
                cout << "Nhập sai!" << endl;
                break;
        }
    }
    return 0;
}

void hamNhap(int arr[], int size){
    for( int i = 0; i < size; i++){
        cout << "Nhập phần tứ thứ " << i + 1 << " : ";
        cin >> arr[i];
    }
    cout << "\nCác phần tử trong mảng là: ";
    for( int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

bool isPrime(int n){
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

void tongSoNguyenTo(int arr[], int size){
    int tong = 0;
    cout << "\nCác số nguyên tố trong mảng: ";
    for(int i = 0; i < size; i++){
        if(isPrime(arr[i])){
            cout << arr[i] << " ";
            tong += arr[i];
        }
    }
    cout << "\nTổng các số nguyên tố trong mảng là: " << tong << endl;
}

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void sort(int arr[], int size, int order){
    switch(order){
        case SORT_ASC:
            for (int i = 0; i < size; ++i) {
                for (int j = i + 1; j < size; ++j) {
                    if(arr[i] > arr[j]){
                        swap(arr[i], arr[j]);
                    }
                }
            }
            break;
        case SORT_DESC:
            for (int i = 0; i < size; ++i) {
                for (int j = i + 1; j < size; ++j) {
                    if(arr[i] < arr[j]){
                        swap(arr[j], arr[i]);
                    }
                }
            }
            break;

    }
    cout << "Mảng sau khi sắp xếp: ";
    for (int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
}

void phanTuXuatHienNhieu(int arr[], int size){
    int count = 1;
    int max = 0;
    int number;
    for (int i = 0; i < size; ++i){
        if (arr[i] == arr[i + 1]){
            count++;
            if(count > max){
                number = arr[i];
                max = count;
            }
        }else{
            count = 1;
        }
    }
    cout << "\nPhần tử xuất hiện nhiều nhất trong mảng là: " << number << endl;
    cout << "Số lần xuất hiện: " << max << endl;
}
