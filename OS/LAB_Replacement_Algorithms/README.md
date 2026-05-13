# Lab: Page Replacement Algorithms

## Part 1:


**Page Reference Sequence:** 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5
**Number of Frames:** 3

| Algorithm | Total Page Faults | Final Memory State |
| :--- | :--- | :--- |
| **FIFO** | **9** | `[5, 3, 4]` |
| **LRU** | **10** | `[3, 4, 5]` |
| **Optimal** | **7** | `[3, 4, 5]` |
| **MRU** | **11** | `[5, 2, 1]` |

## Part 2:
### Check [part2.c](./part2.c)

## Part 3:

### 1. Performance Comparison
* **Best Performer**: The **Optimal** algorithm performed best with the fewest page faults.
* **Reason**: It reduces faults by replacing the page that will not be used for the longest period in the future.

### 2. Algorithm Behavior
* **FIFO (First-In-First-Out)**: Replaces the oldest page in memory.
* **LRU (Least Recently Used)**: Replaces the page that hasn't been used for the longest time.
* **MRU (Most Recently Used)**: Replaces the most recently accessed page.

### 3. Real-World Implementation
* **Why Optimal can't be used**: It requires perfect knowledge of future page requests.
* **Constraint**: Real systems cannot predict future reference strings, making implementation impossible.
