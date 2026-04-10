# AiZO Project: Sorting Algorithms Performance Analysis

This project is part of the Algorithm and Computational Complexity course. Its primary goal is to empirically analyze, compare, and benchmark the performance of various sorting algorithms across different data distributions.

The project goes beyond standard implementations by introducing **Hybrid Sort** (combining the recursive power of Quick Sort with the low-overhead of Insertion Sort for small subarrays) and testing the impact of different pivot selection strategies.

## 📊 Implemented Algorithms & Complexity
The testing engine evaluates the following algorithms:

| Algorithm | Average Complexity | Worst-case | Memory (Space) | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **Heap Sort** | O(N log N) | O(N log N) | O(1) | In-place sorting using a max-heap structure. |
| **Shell Sort** | Depends on gaps | O(N^2) | O(1) | Tested with standard and Frank & Lazarus gap sequences. |
| **Quick Sort** | O(N log N) | O(N^2) | O(log N) | Tested with Left, Right, Middle, and Random pivots. |
| **Hybrid Sort** | O(N log N) | O(N^2) | O(log N) | Quick Sort + Insertion Sort (tested with thresholds: 10, 25, 100). |

## 🧪 Testing Environment
To simulate real-world data behaviors, the benchmarking machine runs algorithms against multiple array scenarios:
* **Randomly generated** elements.
* **Fully sorted** (Ascending).
* **Reverse sorted** (Descending - tests worst-case scenarios).
* **Partially sorted** (33% and 66% sorted).

*Note: The system performs 100 iterations for each array size (ranging from 50k to 5M elements) to calculate a reliable average execution time in milliseconds. It also compares the performance differences between `int` and `float` data types.*

## 🚀 Key Features
- **Template-based Architecture:** Algorithms are implemented using C++ templates, allowing seamless sorting of different data types (`int`, `float`).
- **Stack Overflow Protection:** Custom exceptions and depth-limiters to prevent crashes during deep worst-case recursions.
- **Automated Benchmarking:** A built-in tester class that automatically sequences through sizes, types, and algorithms, outputting clean, aggregable data.

## 💡 Key Findings
Based on the empirical tests conducted up to 5,000,000 elements:
- **Hybrid Sort Outperforms Quick Sort:** Introducing a threshold (e.g., 25) for Insertion Sort reduces the recursive overhead, making Hybrid Sort consistently faster (~10-15%) than standard Quick Sort on large datasets.
- **The Cost of Randomness:** While a random pivot protects against worst-case scenarios, the overhead of the `rand()` function itself makes Quick Sort (Random) noticeably slower on already randomized data compared to deterministic pivots.
- **Gap Sequence Matters:** For Shell Sort, the Frank & Lazarus gap sequence provides a massive performance boost over the standard sequence when the array size scales into the millions.

## 🛠️ Getting Started
### Prerequisites
- C++17 compatible compiler (e.g., GCC/MinGW)

### Compilation & Running
To get the most accurate benchmarking results, it is highly recommended to compile the project with the **highest optimization flag (`-O3`)**.

## Getting Started
1. Clone the repository:
    ```bash
    git clone https://github.com/ANOM0S/AiZO-projekt.git
    ```
2. Run the program! everything works as and console app!
