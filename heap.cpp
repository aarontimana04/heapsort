#include <iostream>
#include <vector>
#include <iterator> //quiza no es necesario, pero lo vi en la ppt

using namespace std;

//intercambio de valores
void swap(vector<int>::iterator a, vector<int>::iterator b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(vector<int>::iterator begin, vector<int>::iterator end, vector<int>::iterator current) {
    auto largest = current;
    auto left = begin + 2 * distance(begin, current) + 1;
    auto right = begin + 2 * distance(begin, current) + 2;

    if (left < end && *left > *largest)
        largest = left;

    if (right < end && *right > *largest)
        largest = right;

    if (largest != current) {
        swap(largest, current);
        heapify(begin, end, largest);
    }
}

//Usando operaciones basicas S3-pag.7 de 21
void heapSort(vector<int>& arr) {
    auto begin = arr.begin();
    auto end = arr.end();

    for (auto current = begin + distance(begin, end) / 2 - 1; current >= begin; --current)
        heapify(begin, end, current);

    for (auto current = end - 1; current > begin; --current) {
        swap(begin, current);
        heapify(begin, current, begin);
    }
}

void imprimir(const vector<int>& arr) {
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

//principal
int main() {
    vector<int> arr = {3,5,1,7,10,1,6,9};
    cout << "Arreglo original:\n";
    imprimir(arr);

    heapSort(arr);

    cout << "Arreglo ordenado:\n";
    imprimir(arr);
    return 0;
}
