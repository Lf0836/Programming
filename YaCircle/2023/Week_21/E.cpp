#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct HeapItem {
  int value;
  int index;
};

class PriorityQueue {
 private:
  vector<HeapItem> heap;
  int size;

  void siftUp(int i) {
    while (i > 0 && heap[i].value > heap[(i - 1) / 2].value) {
      swap(heap[i], heap[(i - 1) / 2]);
      i = (i - 1) / 2;
    }
  }

  void siftDown(int i) {
    while (2 * i + 1 < size) {
      int left = 2 * i + 1;
      int right = 2 * i + 2;
      int j = left;
      if (right < size && heap[right].value > heap[left].value) {
        j = right;
      }
      if (heap[i].value >= heap[j].value) {
        break;
      }
      swap(heap[i], heap[j]);
      i = j;
    }
  }

 public:
  PriorityQueue(int maxSize) : size(0), heap(maxSize) {}

  int extractMax() {
    if (size == 0) {
      return -1;
    }
    int maxValue = heap[0].value;
    heap[0] = heap[--size];
    siftDown(0);
    return maxValue;
  }

  int insert(int value) {
    if (size == heap.size()) {
      return -1;
    }
    heap[size].value = value;
    heap[size].index = size;
    siftUp(size++);
    return size - 1;
  }

  int remove(int index) {
    if (index >= size) {
      return -1;
    }
    int removedValue = heap[index].value;
    heap[index] = heap[--size];
    if (heap[index].value > removedValue) {
      siftDown(index);
    } else {
      siftUp(index);
    }
    return removedValue;
  }

  void printHeap() {
    for (int i = 0; i < size; ++i) {
      cout << heap[i].value << " ";
    }
    cout << endl;
  }
};

int main() {
  int maxSize, numQueries;
  cin >> maxSize >> numQueries;
  PriorityQueue pq(maxSize);

  for (int i = 0; i < numQueries; ++i) {
    int queryType;
    cin >> queryType;
    if (queryType == 1) {
      int maxValue = pq.extractMax();
      if (maxValue == -1) {
        cout << -1 << endl;
      } else {
        cout << maxValue << endl;
      }
    } else if (queryType == 2) {
      int value;
      cin >> value;
      int index = pq.insert(value);
      if (index == -1) {
        cout << -1 << endl;
      } else {
        cout << index << endl;
      }
    } else if (queryType == 3) {
      int index;
      cin >> index;
      int removedValue = pq.remove(index);
      if (removedValue == -1) {
        cout << -1 << endl;
      } else {
        cout << removedValue << endl;
      }
    }
  }
  pq.printHeap();
  return 0;
}
