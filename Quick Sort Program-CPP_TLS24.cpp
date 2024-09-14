#include<iostream>
#include<utility> // untuk std::swap
using namespace std;

int divide(int arr[], int start, int end)
{
    int pivot = arr[end];  // Pilih elemen terakhir sebagai pivot
    int index = start;      // Index untuk menempatkan elemen yang lebih kecil dari pivot

    for (int i = start; i < end; i++)
    {
        if (arr[i] < pivot)
        {
            // Gunakan std::swap untuk menukar elemen
            swap(arr[i], arr[index]);
            index++;
        }
    }

    // Tempatkan pivot di posisi yang benar
    swap(arr[end], arr[index]);

    return index;  // Kembalikan posisi pivot
}

void Quick(int arr[], int start, int end)
{
    if (start < end)
    {
        int d = divide(arr, start, end);  // Bagi array berdasarkan pivot
        Quick(arr, start, d - 1);         // Urutkan bagian kiri
        Quick(arr, d + 1, end);           // Urutkan bagian kanan
    }
}

int main()
{
    int num;
    cout << "Enter the number of elements: ";
    cin >> num;

    int arr[100];  // Array dengan ukuran hingga 100 elemen
    cout << "Enter the elements: ";
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    // Panggil fungsi Quick Sort
    Quick(arr, 0, num - 1);

    // Tampilkan hasil setelah pengurutan
    cout << "After sorting, the elements are: ";
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
