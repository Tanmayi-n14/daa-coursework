# DAA Jackfruit Final Assignment: Question Set 13

* **Course**: Design and Analysis of Algorithms (UE24CS241B) — Semester 4
* **Department**: Department of Computer Science and Engineering, PES University
* **Author**: Tanmayi Nagabhairava (`PES1UG24CS493`)

---

## 📋 Question Set 13 Overview

### Question 1: Divide and Conquer — Rotation Points Counting
* **Problem**: Given an unsorted array $A[0..n-1]$ of $n$ distinct integers, find the number of rotation points (indices $i$ where $A[i] > A[i+1]$).
* **Source Code**: [`src/01_rotation_points_dc.c`](./src/01_rotation_points_dc.c)
* **Approaches Implemented**:
  1. **Linear Scan**: $O(n)$ time complexity.
  2. **Divide and Conquer**: Recursively divides the array into halves, computes left and right rotation counts, and checks the boundary cross-element ($A[mid] > A[mid+1]$). Recurrence: $T(n) = 2T(n/2) + O(1) \implies O(n)$ time complexity.

### Question 2: Greedy Method — Coin Change Denomination
* **Problem**: Given $n$ coin denominations $d_1, d_2, \dots, d_n$ (non-standard) and an amount $M$, design a greedy algorithm to find the minimum number of coins needed.
* **Source Code**: [`src/02_greedy_coin_change.c`](./src/02_greedy_coin_change.c)
* **Key Features**:
  * Duplicate and invalid coin removal ($\le 0$).
  * Descending bubble sort for greedy selection of largest denominations first.
  * Rigorous **failure counterexample analysis**: Demonstrates where greedy fails compared to dynamic programming (e.g. for coins $\{1, 3, 4\}$ and amount 6, greedy yields 3 coins $\{4, 1, 1\}$, whereas the optimal solution is 2 coins $\{3, 3\}$).

### Question 3: Dynamic Programming — 0/1 Knapsack Problem
* **Problem**: Given $n$ items with weights $w_i$ and values $v_i$, and knapsack capacity $W$, find the subset of items that maximizes value without exceeding $W$.
* **Source Code**: [`src/03_knapsack_01_dp.c`](./src/03_knapsack_01_dp.c)
* **Algorithm & State**:
  * 2D DP Table: $dp[i][w] = \max(dp[i-1][w], v_{i-1} + dp[i-1][w - w_{i-1}])$.
  * Full DP table printing for test cases.
  * Backtracking reconstruction to determine the exact selected item indices.
  * Time Complexity: $O(n \cdot W)$, Space Complexity: $O(n \cdot W)$.

---

## 📁 Included Deliverables & Documents
* **`Question_Paper_Set_13.pdf`**: Official PES University Question Paper for Set 13.
* **`DAA_Jackfruit_Project_Report.pdf`**: Comprehensive Project Report with algorithm proofs and complexity bounds.
* **`DAA_Jackfruit_Code_Documentation.pdf`**: Code Documentation Report.
* **`DAA-ASSIGNMENT.pptx`**: Defense Presentation Slide Deck.
* **`problem-statements/`**: Original photographed prompt sheets from Question Set 13.
