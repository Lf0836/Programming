#include <iostream>
#include <vector>

using namespace std;

// Функция для слияния двух отсортированных половинок в одну
void merge(vector<int>& arr, int left, int middle, int right) {
  int i, j, k;
  int n1 = middle - left + 1;    // Размер левой половинки
  int n2 = right - middle;    // Размер правой половинки

  // Создаем временные векторы для хранения левой и правой половинок
  vector<int> L(n1), R(n2);

  // Копируем данные во временные векторы
  for (i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = arr[middle + 1 + j];
  }

  // Слияние временных векторов обратно в основной вектор
  i = 0;        // Индекс для левого временного вектора
  j = 0;        // Индекс для правого временного вектора
  k = left;    // Индекс для основного вектора

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];    // Записываем значение из левого временного вектора
      i++;
    } else {
      arr[k] = R[j];    // Записываем значение из правого временного вектора
      j++;
    }
    k++;
  }

  // Копирование оставшихся элементов левого временного вектора, если такие есть
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Копирование оставшихся элементов правого временного вектора, если такие есть
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Функция сортировки слиянием
void mergeSort(vector<int>& arr, int left, int right) {
  if (left < right) {
    int middle = (left + right) / 2;

    // Рекурсивно разделяем и сортируем левую половинку
    mergeSort(arr, left, middle);
    // Рекурсивно разделяем и сортируем правую половинку
    mergeSort(arr, middle + 1, right);

    // Слияние двух отсортированных половинок
    merge(arr, left, middle, right);
  }
}

int main() {
  int n;
  cout << "Введите размер массива: ";
  cin >> n;

  vector<int> arr(n);
  cout << "Введите элементы массива: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // Вызов функции сортировки слиянием
  mergeSort(arr, 0, n - 1);

  cout << "Отсортированный массив: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}