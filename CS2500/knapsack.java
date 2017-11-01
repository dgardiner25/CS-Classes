package sack;

import sack.heap_sort;

// Class to store value, weight, and value/weight ratio to make sorting easier
class item {
    private int value;
    private int weight;
    private double val_weight;

    public void set_value(int value) {
        this.value = value;
    }

    public int get_value() {
        return this.value;
    }

    public void set_weight(int weight) {
        this.weight = weight;
    }

    public int get_weight() {
        return this.weight;
    }

    public void set_val_weight(double val_weight) {
        this.val_weight = val_weight;
    }

    public double get_val_weight() {
        return this.val_weight;
    }
};

public class knapsack {

    public static void main(String[] args) {
        int W = (int) (Math.random() * 99 + 1); // Size of the sack
        int n = (int) (Math.random() * 7 + 3); // Number of values/weights
        int[] val = new int[n]; // Values
        int[] wt = new int[n]; // Weights
        double start, end; // To track runtime

        // Add values to value and weight arrays
        for (int i = 0; i < n; i++) {
            val[i] = (int) (Math.random() * 50 + 1);
            wt[i] = (int) (Math.random() * W + 1);
        }

        // Output values, weights and sack size
        System.out.println("Sack Size: " + W);
        System.out.print("Values: [ ");
        for (int i = 0; i < n; i++) {
            System.out.print(val[i] + ", ");
        }
        System.out.println("]");
        System.out.print("Weights: [ ");
        for (int i = 0; i < n; i++) {
            System.out.print(wt[i] + ", ");
        }
        System.out.println("]");

        // Run dynamic algorithm
        start = System.nanoTime();
        System.out.println("Dynamic Solution: ");
        dynamicKnapsack(W, wt, val, n);
        end = System.nanoTime();
        System.out.println("Runtime of dynamic knapsack: " + (end - start) / 1000000 + " ms");

        // Run greedy algorithm
        start = System.nanoTime();
        System.out.println("Greedy Solution: " + greedyKnapsack(W, wt, val, n));
        end = System.nanoTime();
        System.out.println("Runtime of greedy knapsack: " + (end - start) / 1000000 + " ms");
    }

    // Return the greater of the two arguments
    static int max(int l, int r) {
        return (l > r ? l : r);
    }

    // Check if the given position is optimal
    static boolean isMax(int[][] K, int[] wt, int[] val, int i, int w) {
        return (K[i][w] == max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]));
    }

    // Dynamic approach
    public static int dynamicKnapsack(int W, int wt[], int val[], int n) {
        // Pre: Sack must be greater than size 0
        assert (W > 0) : "Sack must be greater than size 0.";
        int[][] K = new int[n + 1][W + 1];

        // Invariant: K[0][0] is the optimal value of an empty sack
        assert isMax(K, wt, val, 0, 0) : "K[0][0] is not the max value.";
        for (int i = 0; i <= n; i++) {
            // Invariant: K[i-1][W] is the optimal value of the i-1th row of the sack of size W
            assert isMax(K, wt, val, i, W) : "K[i-1][W] is not the max value.";
            for (int w = 0; w <= W; w++) {
                // Invariant: K[i][w-1] is the optimal value of the ith row of the sack of size w-1
                assert isMax(K, wt, val, i, w - 1) : "K[i][w-1] is not the max value.";
                if (i == 0 || w == 0)
                    K[i][w] = 0;
                else if (wt[i - 1] <= w)
                    K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
                else
                    K[i][w] = K[i - 1][w];
                // Invariant: K[i][w] is the optimal value of the ith row of the sack of size w
                assert isMax(K, wt, val, i, w) : "K[i][w] is not the max value.";
            }
            // Invariant: K[i][W] is the optimal value of the ith row of the sack of size W
            assert isMax(K, wt, val, i, W) : "K[i][W] is not the max value.";
        }
        // Post: K[n][W] is the optimal value of the nth row of the sack of size W
        assert isMax(K, wt, val, n, W) : "K[n][W] is not the max value";

        // For outputting the table
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < W + 1; j++) {
                System.out.print(K[i][j] + " ");
            }
            System.out.println();
        }

        // Return optimal value
        return K[n][W];
    }

    public static int greedyKnapsack(int W, int wt[], int val[], int n) {
        item[] items = new item[n]; // Holds the value/weights
        int weight_count = 0; // Current weight in knapsack
        int value_count = 0; // Result (value in Knapsack)

        // Sort by value/weight using heap sort
        for (int i = 0; i < n; i++) {
            items[i] = new item();
            items[i].set_val_weight(((double) (val[i])) / wt[i]);
            items[i].set_value(val[i]);
            items[i].set_weight(wt[i]);
        }
        heap_sort.heapSort(items, n);

        // Output sorted value/weights
        //        for (int i = 0; i < n; i++) {
        //            System.out.println(items[i].get_val_weight() + " " + items[i].get_value() + " " + items[i].get_weight());
        //        }

        // Pre: Sack must be greater than size 0
        assert (W > 0) : "Sack must be greater than size 0.";
        for (int i = n - 1; i >= 0; i--) {
            // If item doesn't overflow the sack, add the value
            // Invariant: The current weight must not be greater than the size of the sack
            assert weight_count <= W : "Current weight exceeds sack size!";
            if (weight_count + items[i].get_weight() <= W) {
                weight_count += items[i].get_weight();
                value_count += items[i].get_value();
            }
            // Invariant: The current weight must not be greater than the size of the sack
            assert weight_count <= W : "Current weight exceeds sack size!";
        }
        // Post: The value of the sack is greater than 0
        assert value_count > 0 : "The value of the sack can't be 0";

        // Return final value
        return value_count;
    }

}
