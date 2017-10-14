package help.me;

public class heap_sort {

    public static void main(String[] args) {
        int[] heap = new int[500];
        double start, end;
        int choice = 2;
        
        if(choice == 1) {
            System.out.print("BEST: ");
            for (int i = 499; i >= 0; i--)
                heap[499 - i] = i;
            start = System.nanoTime();
            // Pre: heap[n..n] is sorted
            assert isSorted(heap, heap.length, heap.length) : "Heap is not sorted";
            heapSort(heap, heap.length);
            // Post: heap[0..n] is sorted
            assert isSorted(heap, 0, heap.length) : "Heap is not sorted";
            end = System.nanoTime();
            System.out.println((end - start) / 1000000 + " ms");
        } else if(choice == 2) {
            System.out.print("WORST (or at least worse): ");
            for (int i = 0; i < 500; i++)
                heap[i] = i;
            start = System.nanoTime();
            // Pre: heap[n..n] is sorted
            assert isSorted(heap, heap.length, heap.length) : "Heap is not sorted";
            heapSort(heap, heap.length);
            // Post: heap[0..n] is sorted
            assert isSorted(heap, 0, heap.length) : "Heap is not sorted";
            end = System.nanoTime();
            System.out.println((end - start) / 1000000 + " ms");
        } else {
            System.out.print("RANDOM: ");
            for (int i = 0; i < 500; i++)
                heap[i] = (int) (Math.random() * 1000);
            start = System.nanoTime();
            // Pre: heap[n..n] is sorted
            assert isSorted(heap, heap.length, heap.length) : "Heap is not sorted";
            heapSort(heap, heap.length);
            // Post: heap[0..n] is sorted
            assert isSorted(heap, 0, heap.length) : "Heap is not sorted";
            end = System.nanoTime();
            System.out.println((end - start) / 1000000 + " ms");
        }

       
    }

    // Usual swap function
    static void swap(int heap[], int val1, int val2) {
        int temp = heap[val1];
        heap[val1] = heap[val2];
        heap[val2] = temp;
    }

    static void printLinear(int heap[], int size) {
        for (int i = 0; i < size; ++i)
            System.out.print(heap[i] + " ");
    }

    static void printTree(int heap[], int size) {
        int count = 1;
        int pow_2 = 1;
        for (int i = 0; i < size; i++) {
            System.out.print(heap[i] + "     ");
            count++;
            if (count == Math.pow(2, pow_2)) {
                System.out.println();
                pow_2++;
            }
        }
        System.out.println();
    }

    private static void createMaxHeap(int heap[], int parent, int size) {
        // Invariant: heap[k+1..n] satisfies max heap property
        assert isMaxHeap(heap, parent + 1, size) : "Heap does not satisfy max heap property";
        int child1 = 2 * parent + 1; // Left child
        int child2 = 2 * parent + 2; // Right child
        int biggest = parent; // Default to the parent of the children

        // Check if there is a left child (if there isn't, child1 >= size) and if it is bigger than the parent
        if (child1 < size && heap[child1] > heap[biggest])
            biggest = child1;

        // Check if there is a right child (if there isn't, child2 >= size) and
        // if it is bigger than the current biggest (parent or child1)
        if (child2 < size && heap[child2] > heap[biggest])
            biggest = child2;

        // Check if the children were bigger than the parent
        if (biggest != parent) {
            // Swap the biggest value with the parent
            swap(heap, parent, biggest);

            // Invariant: heap[index+1..n] satisfies max heap property
            assert isMaxHeap(heap, biggest + 1, size) : "Heap does not satisfy max heap property";
            // Call the function again to continue building the max heap
            createMaxHeap(heap, biggest, size);
            // Invariant: heap[index..n] satisfies max heap property
            assert isMaxHeap(heap, biggest, size) : "Heap does not satisfy max heap property";
        }
        // Invariant: heap[k..n] satisfies max heap property
        assert isMaxHeap(heap, parent, size) : "Heap does not satisfy max heap property";
    }

    private static void heapSort(int heap[], int size) {
        // Create the initial max heap, starting with the first parent node
        for (int i = size / 2 - 1; i >= 0; i--) {
            // Invariant (pre): heap[i+1..n] satisfies max heap property
            assert isMaxHeap(heap, i + 1, size) : "Heap does not satisfy max heap property";
            createMaxHeap(heap, i, size);
            //Invariant (post): heap[i..n] satisfies max heap property
            assert isMaxHeap(heap, i, size) : "Heap does not satisfy max heap property";
        }

        // Take the max element and swap it with the last then decrease size
        for (int i = size - 1; i >= 1; i--) {
            // Invariant: heap[0..i] satisfies max heap property and heap[i+1..n] is sorted
            assert isMaxHeap(heap, 0, i) && isSorted(heap, i + 1, size) : "Heap does not satisfy max heap property";
            // Replace max element (root) with the last element
            swap(heap, 0, i);
            createMaxHeap(heap, 0, i);
            // Invariant: heap[0..i-1] satisfies max heap property and heap[i..n] is sorted
            assert isMaxHeap(heap, 0, i - 1) && isSorted(heap, i, size) : "Heap does not satisfy max heap property";
        }
    }

    static boolean isMaxHeap(int heap[], int parent, int size) {
        int index;
        if (parent > size)
            return false;
        else if (parent > size / 2 - 1)
            return true;
        else if (2 * parent + 2 < size)
            index = (heap[2 * parent + 1] > heap[2 * parent + 2] ? 2 * parent + 1 : 2 * parent + 2);
        else
            index = 2 * parent + 1;
        return heap[parent] >= heap[index];
    }

    static boolean isSorted(int heap[], int start, int end) {
        for (int i = start; i < end - 1; i++) {
            if (heap[i] > heap[i + 1])
                return false;
        }
        return true;
    }

}
