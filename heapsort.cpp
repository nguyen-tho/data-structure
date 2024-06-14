#include <iostream>
/*
Độ phức tạp thời gian:
  Trường hợp trung bình và tốt nhất: O(n log n)
  Trường hợp xấu nhất: O(n log n)
Ưu điểm:
  Hiệu quả cao, đặc biệt là với dữ liệu lớn
  Yêu cầu bộ nhớ ít
  Hoạt động tốt với cả dữ liệu gần được sắp xếp và dữ liệu ngẫu nhiên
Nhược điểm:
  Yêu cầu cấu trúc dữ liệu Heap, dẫn đến việc tốn thêm thời gian và bộ nhớ
  Không ổn định, nghĩa là việc hoán đổi một phần tử trong mảng có thể ảnh hưởng đến hiệu suất của thuật toán
*/
using namespace std;

void heapify(int arr[], int n, int i) {
    // Lấy vị trí của các con
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Tìm vị trí của phần tử lớn nhất trong ba phần tử i, left và right
    int largest = i;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Nếu largest không phải i, hoán đổi arr[i] và arr[largest]
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Heapify lại cây con bắt đầu từ largest
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Chuyển đổi mảng thành heap tối đa
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Lặp lại để lấy ra các phần tử lớn nhất và đặt chúng vào vị trí cuối cùng của mảng đã được sắp xếp
    for (int i = n - 1; i > 0; i--) {
        // Hoán đổi arr[0] (phần tử lớn nhất) với arr[i]
        swap(arr[0], arr[i]);

        // Giảm kích thước của heap và heapify lại cây con
        n--;
        heapify(arr, n, 0);
    }
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mảng ban đầu: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    heapSort(arr, n);

    cout << "\nMảng đã được sắp xếp: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
