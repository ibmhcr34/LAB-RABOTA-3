#ЛАБ. РАБОТА 3 РЕШЕШИЕ НА C++ ЗАДАЧА 1



#include <iostream>
#include <vector>

class MinHeap {
    std::vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapify(int i) {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < (int)heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < (int)heap.size() && heap[right] < heap[smallest])
            smallest = right;
        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        int i = (int)heap.size() - 1;
        while (i != 0 && heap[i] < heap[parent(i)]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    int extractMin() {
        if (heap.empty())
            return -1;
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapify(0);
        return root;
    }

    bool isMinHeap() {
        for (int i = 0; i < (int)heap.size() / 2; i++) {
            int left = leftChild(i);
            int right = rightChild(i);
            if (left < (int)heap.size() && heap[i] > heap[left])
                return false;
            if (right < (int)heap.size() && heap[i] > heap[right])
                return false;
        }
        return true;
    }

    void print() {
        for (int val : heap)
            std::cout << val << " ";
        std::cout << "\n";
    }
};

int main() {
    MinHeap h;
    h.insert(5);
    h.insert(3);
    h.insert(8);
    h.insert(1);

    h.print();

    std::cout << h.extractMin() << "\n";

    h.print();

    std::cout << (h.isMinHeap() ? "true\n" : "false\n");

    return 0;
}
