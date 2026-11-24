# Push_swap --- Development Roadmap

## Project architecture

The project uses three sorting algorithms and one adaptive decision
layer:

-   **Easy:** Insertion Sort
-   **Medium:** Chunk Sort
-   **Complex:** Turk Algorithm
-   **Adaptive selector:** analyzes the input and chooses one of the
    three strategies based on stack size, disorder metrics, and measured
    performance.

The adaptive selector is **not a fourth sorting algorithm**. It is a
decision-making component.

> The size ranges below are initial defaults, not fixed rules. The
> selector may choose another eligible algorithm when benchmarks show it
> is likely to produce fewer operations. Make sure every algorithm can
> safely handle any input size for which it may be selected.

------------------------------------------------------------------------

## 1. Overall flowchart

``` mermaid
flowchart TD
    A["Start push_swap"] --> B["1. Parse & validate"]
    B --> C["2. Build stacks"]
    C --> D["3. Normalize values to indexes"]
    D --> E["4. Analyze input disorder"]
    E --> F["5. Adaptive algorithm selector"]
    F --> G{"Choose strategy"}
    G -->|"Insertion Sort"| H["Easy strategy"]
    G -->|"Chunk Sort"| I["Medium strategy"]
    G -->|"Turk Algorithm"| J["Complex strategy"]
    H --> K["Execute operations"]
    I --> K
    J --> K
    K --> L["Sorted stack A"]
    L --> M["Test, benchmark & optimize"]
```

------------------------------------------------------------------------

## 2. Development phases

### Phase 1 --- Parsing and validation

**Goal:** correctly interpret and validate program arguments.

-   [ ] Parse arguments passed separately: `./push_swap 3 2 1`
-   [ ] Parse arguments passed as a string: `./push_swap "3 2 1"`
-   [ ] Handle positive and negative integers.
-   [ ] Handle `INT_MAX` and `INT_MIN`.
-   [ ] Detect non-numeric arguments.
-   [ ] Detect integer overflow.
-   [ ] Detect duplicate numbers.
-   [ ] Handle empty arguments and invalid input.
-   [ ] Detect already-sorted input and avoid unnecessary operations.

**Checkpoint:** invalid input prints `Error` to stderr; valid input is
accepted.

### Phase 2 --- Data structures

**Goal:** choose and implement a reliable representation for stacks A
and B.

A doubly linked list is one suitable option.

  Field          Purpose
  -------------- ----------------------------------------
  `value`        Original integer
  `index`        Normalized rank
  `position`     Current position, when needed
  `target_pos`   Target insertion position, when needed
  `cost_a`       Rotation cost in A, when needed
  `cost_b`       Rotation cost in B, when needed
  `next`         Next node
  `prev`         Previous node

You do not necessarily need every field permanently; some values can be
calculated temporarily.

-   [ ] Define stack and node structures.
-   [ ] Decide how stack sizes will be tracked.
-   [ ] Implement node creation and insertion.
-   [ ] Implement stack initialization.
-   [ ] Implement memory cleanup.

### Phase 3 --- Stack operations

**Goal:** implement and test every operation independently.

  Operation   Purpose
  ----------- ----------------------------------
  `sa`        Swap the first two elements of A
  `sb`        Swap the first two elements of B
  `ss`        Swap both stacks
  `pa`        Push the top element of B to A
  `pb`        Push the top element of A to B
  `ra`        Rotate A upwards
  `rb`        Rotate B upwards
  `rr`        Rotate both stacks upwards
  `rra`       Reverse rotate A
  `rrb`       Reverse rotate B
  `rrr`       Reverse rotate both stacks

-   [ ] Handle empty stacks.
-   [ ] Handle stacks with one element.
-   [ ] Handle stacks with two elements.
-   [ ] Test combined operations.
-   [ ] Ensure each operation modifies only the intended stack(s).
-   [ ] Ensure printed operations match the operations actually
    performed.

**Checkpoint:** each operation produces the expected stack state.

### Phase 4 --- Utility functions

**Goal:** create reusable helpers for the algorithms and analyzer.

Potential helpers:

-   [ ] `stack_size()`
-   [ ] `stack_last()`
-   [ ] `find_min()`
-   [ ] `find_max()`
-   [ ] `is_sorted()`
-   [ ] `get_position()`
-   [ ] Array-copy and sorting helpers for normalization
-   [ ] Stack cleanup functions

Keep analyzer helpers separate from sorting helpers where that improves
clarity.

### Phase 5 --- Index normalization

**Goal:** give every input value a rank based on its ascending sorted
position.

Example:

    Original value   Normalized index
  ---------------- ------------------
              `42`                `2`
              `-5`                `0`
             `100`                `3`
              `12`                `1`

After normalization, the stack contains indexes `0` through `n - 1`.
This makes comparisons independent of original integer values and is
useful for Chunk Sort and disorder analysis.

-   [ ] Copy input values to an auxiliary array.
-   [ ] Sort the auxiliary array.
-   [ ] Assign each stack node its rank.
-   [ ] Verify indexes are unique and cover `0` through `n - 1`.

------------------------------------------------------------------------

## 3. Adaptive method --- Disorder analyzer and algorithm selector

This phase happens **after normalization and before sorting**.

It has two responsibilities:

1.  **Disorder analyzer:** measure how ordered or disordered the initial
    input is.
2.  **Algorithm selector:** use the measurements and stack size to
    choose Insertion Sort, Chunk Sort, or Turk.

The analyzer must inspect the original stack before any sorting
operation changes it.

### 3.1 Metrics to calculate

Start with two main metrics: inversion ratio and LIS ratio.

#### A. Inversion count and inversion ratio

An inversion is a pair of positions `i` and `j` where `i < j` but
`index[i] > index[j]`.

  Input indexes     Inversion count
  --------------- -----------------
  `0 1 2 3 4`                     0
  `0 2 1 4 3`                     2
  `4 3 2 1 0`                    10

The maximum possible inversion count is:

\[ I\_{max} = `\frac{n(n-1)}{2}`{=tex} \]

Normalize it:

\[ D\_{inv} = `\frac{I}{n(n-1)/2}`{=tex} \]

Interpretation:

-   `0`: already sorted.
-   Near `0`: mostly ordered.
-   Near `1`: highly disordered.
-   `1`: reverse sorted.

For `n < 2`, define the ratio as zero to avoid division by zero.

A simple pairwise implementation takes `O(n²)`, which may be adequate
for push_swap inputs up to 500 elements. A merge-sort-based counter can
do it in `O(n log n)` if desired.

#### B. Longest Increasing Subsequence (LIS) and LIS ratio

The Longest Increasing Subsequence is the longest subsequence whose
values increase, without requiring adjacent elements.

Example:

``` text
Input:  4 1 2 5 3 6
LIS:    1 2 3 6
Length: 4
```

Calculate:

\[ D\_{LIS} = 1 - `\frac{LIS}{n}`{=tex} \]

Interpretation:

-   `0`: the entire input is increasing.
-   Near `0`: a large part is already in increasing order.
-   Near `1`: the LIS is relatively small.

An `O(n log n)` LIS-length implementation is suitable. If you later want
to reconstruct the actual subsequence, store predecessor information as
well as the LIS length.

### 3.2 Optional metrics

Do not implement every metric immediately. Add these only if benchmarks
show they are useful.

  -----------------------------------------------------------------------
  Metric                  What it measures        Possible use
  ----------------------- ----------------------- -----------------------
  Maximum displacement    Distance from each      Detect elements far
                          element's final rank    from their sorted
                                                  positions

  Sorted runs             Number of naturally     Detect existing local
                          increasing sequences    order

  Adjacent inversions     Neighboring pairs out   Cheap local-order
                          of order                indicator
  -----------------------------------------------------------------------

### 3.3 Build the selector

The selector should consider:

-   Number of elements.
-   Inversion ratio.
-   LIS ratio.
-   Measured performance of each eligible algorithm for similar inputs.

Conceptual decision process:

``` text
if input is already sorted:
    perform no operations
else:
    calculate disorder metrics

    if size is small:
        choose the small-stack strategy
    else:
        estimate the cost of each eligible algorithm
        choose the strategy with the lowest estimated cost
```

Initial size-based defaults:

    Input size Initial default
  ------------ -----------------
          2--5 Insertion Sort
        6--100 Chunk Sort
      101--500 Turk Algorithm

These are starting defaults, not final adaptive rules. The selector must
never choose an algorithm outside the size range it safely supports.

### 3.4 Do not invent disorder thresholds

Avoid assuming that a low inversion ratio automatically means Insertion
Sort is best, or that a high LIS ratio automatically means Turk is best.
Metrics describe the input; they do not prove which algorithm will
produce the fewest operations.

Build a benchmark dataset:

1.  Generate many random permutations at several input sizes.
2.  Include sorted, reverse-sorted, nearly sorted, and structured
    inputs.
3.  Calculate inversion and LIS ratios for each input.
4.  Run each eligible algorithm on an independent copy of the same
    input.
5.  Record operation counts.
6.  Compare results and look for patterns between the metrics and the
    best-performing algorithm.
7.  Use the results to tune selector thresholds or cost estimates.
8.  Re-test on fresh random datasets to avoid overfitting to the
    benchmark samples.

The goal is for the selector to estimate which eligible algorithm will
use the fewest operations.

### 3.5 Adaptive selector checklist

-   [ ] Analyze the initial stack before sorting.
-   [ ] Calculate inversion count.
-   [ ] Calculate inversion ratio safely.
-   [ ] Calculate LIS length.
-   [ ] Calculate LIS ratio safely.
-   [ ] Handle already-sorted input.
-   [ ] Pass metrics to the selector.
-   [ ] Implement initial size-based fallback rules.
-   [ ] Build a benchmark harness to compare eligible algorithms.
-   [ ] Tune selection rules using measured operation counts.
-   [ ] Test the selector on datasets not used during tuning.

------------------------------------------------------------------------

## 4. Sorting algorithms

### Phase 6 --- Easy algorithm: Insertion Sort

**Target:** 2--5 elements.

Define the exact two-stack insertion strategy before coding. One
possible small-stack approach:

1.  Move the smallest element(s) to B.
2.  Sort the remaining three elements in A.
3.  Push elements from B back to A in the correct order.

Suggested progression:

-   [ ] Handle 2 elements.
-   [ ] Handle 3 elements.
-   [ ] Handle 4 elements.
-   [ ] Handle 5 elements.
-   [ ] Test every possible permutation for each size.
-   [ ] Measure operation counts.

For 2--3 elements, specialized minimal cases may be more efficient than
a generic insertion routine. It is reasonable to use dedicated small
cases within the easy strategy.

**Checkpoint:** every permutation of 2--5 distinct values is sorted
correctly.

### Phase 7 --- Medium algorithm: Chunk Sort

**Target:** initially 6--100 elements.

1.  Choose an initial chunk size.
2.  Identify the index range belonging to the current chunk.
3.  Find elements belonging to that chunk.
4.  Rotate A to bring an appropriate element to the top.
5.  Push it to B.
6.  Optimize the order in which elements are pushed into B.
7.  Repeat until A is empty.
8.  Push elements back from B to A in descending order.

For 100 elements, compare starting configurations such as:

-   5 chunks of 20.
-   4 chunks of 25.
-   10 chunks of 10.

These are starting points, not guaranteed optimal values.

-   [ ] Implement chunk identification.
-   [ ] Implement the push strategy from A to B.
-   [ ] Optimize the order of B.
-   [ ] Implement the return from B to A.
-   [ ] Benchmark different chunk sizes.
-   [ ] Verify random and structured inputs.

### Phase 8 --- Complex algorithm: Turk Algorithm

**Target:** initially 101--500 elements.

Implement incrementally:

1.  Push initial elements from A to B.
2.  Calculate the current position of every element in A.
3.  Find the correct target position for each candidate in B.
4.  Calculate the rotations required in A and B.
5.  Account for combined rotations (`rr` and `rrr`).
6.  Select the cheapest candidate to move.
7.  Execute the required rotations.
8.  Push the selected element to B.
9.  Repeat until only three elements remain in A.
10. Sort those three elements.
11. Calculate insertion positions from B into A.
12. Push elements back into A in the correct order.
13. Rotate A until its smallest element is on top.

Consider separating the implementation into:

-   `calculate_positions()`

-   `find_target_position()`

-   `calculate_costs()`

-   `find_cheapest_move()`

-   `execute_move()`

-   [ ] Implement target-position calculation.

-   [ ] Implement rotation-cost calculation.

-   [ ] Account for `rr` and `rrr`.

-   [ ] Select the cheapest move.

-   [ ] Execute moves correctly.

-   [ ] Implement the return from B to A.

-   [ ] Implement final alignment.

-   [ ] Benchmark operation counts.

------------------------------------------------------------------------

## 5. Testing and optimization

### Phase 9 --- Correctness and performance testing

Test the algorithms and adaptive selector separately.

    Test size Initial expected strategy
  ----------- ---------------------------
         2--5 Insertion Sort
           10 Chunk Sort
           50 Chunk Sort
          100 Chunk Sort
          200 Turk Algorithm
          500 Turk Algorithm

The adaptive selector may choose another eligible strategy if benchmark
data supports it.

Test these input patterns:

-   [ ] Already-sorted input.
-   [ ] Reverse-sorted input.
-   [ ] Nearly sorted input.
-   [ ] Random permutations.
-   [ ] Mixed positive and negative numbers.
-   [ ] Alternating high and low values.
-   [ ] Inputs with long increasing subsequences.
-   [ ] Inputs with many inversions.
-   [ ] Duplicate numbers (must be rejected).
-   [ ] Integer boundaries.
-   [ ] Minimum and maximum supported input sizes.

For each benchmark, record:

-   Input size.
-   Inversion ratio.
-   LIS ratio.
-   Selected algorithm.
-   Operation count.
-   Whether an independent checker confirms the result.

Use an independent checker to verify the emitted operations. Benchmark
many random datasets and compare averages and worst cases, not just one
run.

### Phase 10 --- Finalization

-   [ ] Create a Makefile with `all`, `clean`, `fclean`, and `re`.
-   [ ] Compile with `-Wall -Wextra -Werror`.
-   [ ] Run Norminette.
-   [ ] Check memory leaks with Valgrind.
-   [ ] Check error handling.
-   [ ] Verify stdout contains only valid operations.
-   [ ] Verify invalid input prints `Error` to stderr.
-   [ ] Test with the official 42 checker.
-   [ ] Verify operation thresholds required by the subject and
    evaluation rubric.

------------------------------------------------------------------------

## 6. Full progress checklist

### Parsing and validation

-   [ ] Argument parsing
-   [ ] Integer validation and overflow
-   [ ] Duplicate detection
-   [ ] Error handling
-   [ ] Already-sorted input

### Data structures

-   [ ] Stack representation
-   [ ] Node management
-   [ ] Stack initialization
-   [ ] Memory cleanup

### Stack operations

-   [ ] `sa` / `sb` / `ss`
-   [ ] `pa` / `pb`
-   [ ] `ra` / `rb` / `rr`
-   [ ] `rra` / `rrb` / `rrr`

### Utilities and normalization

-   [ ] Stack helpers
-   [ ] Minimum / maximum / sorted checks
-   [ ] Auxiliary array sorting
-   [ ] Index normalization
-   [ ] Position calculations

### Adaptive disorder analyzer

-   [ ] Inversion count
-   [ ] Inversion ratio
-   [ ] LIS length
-   [ ] LIS ratio
-   [ ] Safe handling of small input sizes
-   [ ] Optional metrics, if useful

### Adaptive algorithm selector

-   [ ] Initial size-based fallback
-   [ ] Eligible-algorithm checks
-   [ ] Benchmark harness
-   [ ] Cost comparison
-   [ ] Threshold tuning
-   [ ] Tests on unseen inputs

### Easy --- Insertion Sort

-   [ ] 2 elements
-   [ ] 3 elements
-   [ ] 4 elements
-   [ ] 5 elements
-   [ ] Test every permutation

### Medium --- Chunk Sort

-   [ ] Chunk identification
-   [ ] Push strategy
-   [ ] B-stack optimization
-   [ ] Push back to A
-   [ ] Benchmark chunk sizes

### Complex --- Turk Algorithm

-   [ ] Target-position calculation
-   [ ] Rotation-cost calculation
-   [ ] Cheapest-move selection
-   [ ] Combined rotations
-   [ ] Push back to A
-   [ ] Final alignment

### Testing and optimization

-   [ ] Random tests
-   [ ] Structured disorder tests
-   [ ] Independent checker
-   [ ] Operation benchmarks
-   [ ] Adaptive selector benchmarks

### Finalization

-   [ ] Makefile
-   [ ] Norminette
-   [ ] Valgrind
-   [ ] Final compilation and submission

------------------------------------------------------------------------

## 7. Recommended order of work

1.  **Build the foundation:** parsing → data structures → stack
    operations → utilities.
2.  **Normalize the input:** assign indexes from `0` to `n - 1`.
3.  **Implement the analyzer:** inversion count and LIS length, then
    their normalized ratios.
4.  **Implement the three algorithms:** Insertion Sort, then Chunk Sort,
    then Turk.
5.  **Build the benchmark harness:** run each eligible algorithm on
    equivalent copies of the same inputs and record operation counts.
6.  **Implement and tune the adaptive selector:** start with safe
    size-based defaults, then use benchmark evidence to make
    disorder-aware choices.
7.  **Polish and validate:** correctness → performance → memory checks →
    Norminette → final submission.

### Important design principles

-   The disorder analyzer must inspect the original input before sorting
    begins.
-   The selector chooses an algorithm; it does not sort the stack
    itself.
-   The three algorithms must only be selected for input sizes they can
    handle.
-   Disorder metrics are indicators, not guarantees of which algorithm
    is best.
-   Use measured operation counts to tune the selector instead of
    inventing arbitrary thresholds.
-   Keep a simple, reliable fallback strategy until the adaptive rules
    are tuned.
-   Always verify the final operation sequence with an independent
    checker.

**Key objective:** build three reliable sorting strategies, measure
their behavior on different input patterns, and let the adaptive
selector choose the strategy expected to produce the fewest operations.
