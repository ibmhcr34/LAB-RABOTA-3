#ЛАБ. РАБОТА 3 РЕШЕШИЕ НА Java ЗАДАЧА 1



public class MinHeap {
    private int[] heap;
    private int size;
    private int capacity;

    public MinHeap(int capacity) {
        this.capacity = capacity;
        this.heap = new int[capacity];
        this.size = 0;
    }

    private int parent(int i) { return (i - 1) / 2; }
    private int leftChild(int i) { return 2 * i + 1; }
    private int rightChild(int i) { return 2 * i + 2; }

    public void insert(int val) {
        if (size == capacity) {
            System.out.println("Heap is full");
            return;
        }
        heap[size] = val;
        int current = size;
        size++;

        while (current != 0 && heap[current] < heap[parent(current)]) {
            int temp = heap[current];
            heap[current] = heap[parent(current)];
            heap[parent(current)] = temp;
            current = parent(current);
        }
    }

    public int extractMin() {
        if (size == 0) {
            return -1;
        }
        int min = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);
        return min;
    }

    private void heapify(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int smallest = i;

        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;

        if (smallest != i) {
            int temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;
            heapify(smallest);
        }
    }

    public boolean isMinHeap() {
        for (int i = 0; i < size / 2; i++) {
            int left = leftChild(i);
            int right = rightChild(i);

            if (left < size && heap[i] > heap[left]) return false;
            if (right < size && heap[i] > heap[right]) return false;
        }
        return true;
    }

    public void printHeap() {
        for (int i = 0; i < size; i++) System.out.print(heap[i] + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        MinHeap heap = new MinHeap(10);
        heap.insert(5);
        heap.insert(3);
        heap.insert(8);
        heap.insert(1);

        heap.printHeap(); 

        System.out.println(heap.extractMin());
        heap.printHeap();

        System.out.println(heap.isMinHeap());
    }
}
