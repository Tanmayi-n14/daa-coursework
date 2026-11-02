# Design and Analysis of Algorithms Coursework (Semester 4)

Comprehensive collection of algorithmic designs, paradigm implementations, time/space complexity analyses, and the Jackfruit final project from the Design and Analysis of Algorithms curriculum (UE24CS241B) at PES University.

---

## 📌 Course Progression Overview

```
DAA Coursework
├── Level 1: Core Assignments (4 Rigorous Problem Sets Across Algorithmic Paradigms)
│   ├── Assignment 1: Sorting Variations & Recursion
│   ├── Assignment 2: Divide-and-Conquer Paradigms
│   ├── Assignment 3: Transform-and-Conquer & Balanced Trees
│   └── Assignment 4: Greedy Strategies & Dynamic Programming
└── Level 3: Jackfruit Final Project (Question Set 13)
    ├── Divide and Conquer: Rotation Points Counting
    ├── Greedy Method: Coin Change & Optimality Failure Analysis
    └── Dynamic Programming: 0/1 Knapsack with DP Table Reconstruction
```

---

## 📂 Repository Contents

### 🔹 [Level 1: Core Assignments](./Level-1-Assignments/)

#### [Assignment 01: Sorting & Pure Recursion](./Level-1-Assignments/Assignment-01-Sorting-and-Recursion/)
1. **Constrained Selection Sort (`constrained_selection_sort.c`)**:
   * Sorts array using only suffix-minimum adjacent swaps.
   * Tracks total adjacent swap count and determines parity (EVEN or ODD).
2. **Recursive Valid String Pairs (`recursive_valid_pairs.c`)**:
   * Pure recursion without loops to count pairs $(i, j)$ such that $S[i] == S[j]$, distance $j - i - 1$ is even, and ASCII sum of intervening characters is divisible by 3.
3. **Rotation-Invariant Subarrays (`rotation_invariant_subarrays.c`)**:
   * Evaluates cyclic left-rotations of subarrays of length $\ge 2$.
   * Verifies invariance of $| \sum \text{prime-indexed} - \sum \text{non-prime-indexed} |$.

#### [Assignment 02: Divide-and-Conquer Paradigms](./Level-1-Assignments/Assignment-02-Divide-and-Conquer/)
1. **Josephus Elimination (`josephus_problem.c`)**:
   * Determines the surviving index among $N$ individuals with step $K$.
   * Solved via optimal $O(N)$ mathematical dynamic recurrence: $J(i) = (J(i-1) + K) \pmod i$.
2. **Quickselect K-th Largest Element (`quickselect_kth_largest.c`)**:
   * Finds the $k$-th largest element in expected $O(N)$ time without sorting.
   * Employs randomized partitioning to avoid worst-case $O(N^2)$ behavior.
3. **Count of Range Sum (`range_sum_divide_and_conquer.c`)**:
   * Computes the number of subarray sums within interval $[lower, upper]$ in $O(N \log N)$ time.
   * Uses a modified divide-and-conquer merge sort over prefix sums with two-pointer bounding.

#### [Assignment 03: Transform-and-Conquer & Balanced Trees](./Level-1-Assignments/Assignment-03-Transform-and-Conquer/)
1. **Horspool's String Matching (`horspool_string_matching.c`)**:
   * Substring pattern search using a 256-entry bad character shift table: $shift[c] = m - 1 - i$.
   * Achieves average-case sublinear search performance $O(n/m)$.
2. **Heap Sort & K-th Element (`heap_sort.c`)**:
   * In-place Max-Heap construction via bottom-up `heapify` in $O(n)$ time.
   * Sequential root extraction in $O(n \log n)$ time to locate the $k$-th largest element.
3. **2-3 Tree Balanced Search Tree (`two_three_tree.c`)**:
   * Complete implementation of a 2-3 Tree supporting `Insert(x)` and `Search(x)`.
   * Enforces strict node balance (2-nodes and 3-nodes) with recursive bottom-up node splitting and root promotion.

#### [Assignment 04: Greedy & Dynamic Programming](./Level-1-Assignments/Assignment-04-Greedy-and-Dynamic-Programming/)
1. **Greedy Activity Selection (`activity_selection_greedy.c`)**:
   * Interval scheduling optimization sorting activities by finish times via `qsort` in $O(N \log N)$.
   * Greedily selects maximal non-overlapping intervals in $O(N)$ scan.
2. **0/1 Knapsack Problem (`knapsack_01_dp.c`)**:
   * Solves classic discrete knapsack using 1D space-optimized dynamic programming in $O(N \cdot W)$.
   * Iterates backwards across capacities to guarantee items are selected at most once.
3. **Floyd-Warshall All-Pairs Shortest Path (`floyd_warshall.c`)**:
   * Finds shortest paths between all pairs of vertices in a directed weighted graph in $O(V^3)$.
   * Robust handling of unreachable paths via `INF` sentinel values.

---

### 🍈 [Level 3: Jackfruit Final Project (Question Set 13)](./Level-3-Jackfruit-Project/Question-Set-13/)

* **Question 1: Rotation Points Counting (`src/01_rotation_points_dc.c`)**:
  * Comparative implementation of Linear Scan $O(n)$ vs Divide-and-Conquer $T(n) = 2T(n/2) + O(1) \implies O(n)$ to locate rotation points ($A[i] > A[i+1]$).
* **Question 2: Greedy Coin Change (`src/02_greedy_coin_change.c`)**:
  * Denomination sorting, invalid coin removal, and greedy coin dispensing.
  * Formal counterexample study demonstrating greedy sub-optimality (e.g. amount 6 with $\{1, 3, 4\}$ yields 3 coins greedily vs 2 coins optimally).
* **Question 3: 0/1 Knapsack DP (`src/03_knapsack_01_dp.c`)**:
  * 2D dynamic programming grid with full state table visualization and backtracking path recovery.
* **Deliverables Included**:
  * `Question_Paper_Set_13.pdf`: Official Question Paper.
  * `DAA_Jackfruit_Project_Report.pdf`: Comprehensive Project Report.
  * `DAA_Jackfruit_Code_Documentation.pdf`: Code Documentation.
  * `DAA-ASSIGNMENT.pptx`: Defense Presentation Slides.

---

## 🛠️ Building & Running

All 15 programs are written in standard ANSI/POSIX C. Compile using `gcc`:

```bash
# Compile any program (e.g., Quickselect)
gcc -Wall -Wextra Level-1-Assignments/Assignment-02-Divide-and-Conquer/quickselect_kth_largest.c -o quickselect

# Run
./quickselect
```

---

## 👤 Author
* **Tanmayi Nagabhairava** ([@Tanmayi-n14](https://github.com/Tanmayi-n14)) — `PES1UG24CS493`
* Department of Computer Science & Engineering, PES University
