# Data Structures Practical Programs (C++)

Question-wise standalone C++ implementations for the 60 questions in the supplied practical question bank.

## Compile and run

Compile **one file at a time**, because each source file has its own `main()`.

```bash
g++ -std=c++17 -Wall -Wextra -pedantic 01_stack_using_array.cpp -o program
./program
```

## Question index

| Q | Source file | Aim |
|---:|---|---|
| 1 | [`01_stack_using_array.cpp`](./01_stack_using_array.cpp) | Stack ADT using array: PUSH, POP, PEEK, DISPLAY; overflow/underflow. |
| 2 | [`02_doubly_linked_list_playlist.cpp`](./02_doubly_linked_list_playlist.cpp) | Playlist with doubly linked list; insert at beginning/end/position, delete song, display both ways. |
| 3 | [`03_queue_using_linked_list.cpp`](./03_queue_using_linked_list.cpp) | Queue using linked list; enqueue customers, dequeue served customer, display. |
| 4 | [`04_matrix_addition_multiplication.cpp`](./04_matrix_addition_multiplication.cpp) | Read two 3x3 matrices; display their sum and product. |
| 5 | [`05_infix_to_postfix.cpp`](./05_infix_to_postfix.cpp) | Convert infix to postfix using stack; ^ is right-associative. |
| 6 | [`06_binary_search_tree_operations.cpp`](./06_binary_search_tree_operations.cpp) | BST insert, delete, search and inorder/preorder/postorder traversals. |
| 7 | [`07_avl_tree_insertion.cpp`](./07_avl_tree_insertion.cpp) | Insert 10,20,30,40,50,25 into AVL tree and rebalance with rotations. |
| 8 | [`08_min_heap_array.cpp`](./08_min_heap_array.cpp) | Min heap with insertion, display and delete-min. Input values are not specified in PDF. |
| 9 | [`09_dijkstra_shortest_path.cpp`](./09_dijkstra_shortest_path.cpp) | Dijkstra shortest paths from A. Enter adjacency matrix; 0 means no edge. |
| 10 | [`10_kruskal_minimum_spanning_tree.cpp`](./10_kruskal_minimum_spanning_tree.cpp) | Kruskal MST for given weighted edges; expected minimum cost is 8. |
| 11 | [`11_linear_search_product_ids.cpp`](./11_linear_search_product_ids.cpp) | Linear search 61 and 50 in {24,17,39,5,61,12,48,30}; positions are 1-based. |
| 12 | [`12_binary_search_iterative_recursive.cpp`](./12_binary_search_iterative_recursive.cpp) | Iterative and recursive binary search on a sorted input array. |
| 13 | [`13_bubble_and_quick_sort.cpp`](./13_bubble_and_quick_sort.cpp) | Sort input integers using bubble sort and quick sort. |
| 14 | [`14_hashing_separate_chaining.cpp`](./14_hashing_separate_chaining.cpp) | Hash keys 23,45,12,34,56,78,90 into size-7 table with separate chaining. |
| 15 | [`15_circular_linked_list.cpp`](./15_circular_linked_list.cpp) | Circular linked list insert, delete value, display wrap-around. |
| 16 | [`16_postfix_evaluation.cpp`](./16_postfix_evaluation.cpp) | Evaluate postfix expression 5 3 + 8 2 - * using a stack. |
| 17 | [`17_priority_queue_array.cpp`](./17_priority_queue_array.cpp) | Array priority queue; larger priority number is served first. |
| 18 | [`18_bfs_dfs_adjacency_matrix.cpp`](./18_bfs_dfs_adjacency_matrix.cpp) | BFS/DFS on specified 0..5 graph; PDF omits start, example starts at 0. |
| 19 | [`19_heap_sort.cpp`](./19_heap_sort.cpp) | Heap sort the array {45,12,78,34,90,23} in ascending order. |
| 20 | [`20_reverse_and_middle_singly_linked_list.cpp`](./20_reverse_and_middle_singly_linked_list.cpp) | Create singly linked list, display, reverse, and find middle node. |
| 21 | [`21_stack_using_linked_list.cpp`](./21_stack_using_linked_list.cpp) | Stack ADT using linked list with push, pop, display. |
| 22 | [`22_singly_linked_list_operations.cpp`](./22_singly_linked_list_operations.cpp) | Singly linked list insert beginning/end/position, search and delete value. |
| 23 | [`23_circular_queue_array.cpp`](./23_circular_queue_array.cpp) | Circular queue array with enqueue/dequeue/display and full/empty checks. |
| 24 | [`24_polynomial_addition_multiplication.cpp`](./24_polynomial_addition_multiplication.cpp) | Polynomial linked-list representation; add and multiply polynomials. |
| 25 | [`25_infix_to_postfix_multiple_expressions.cpp`](./25_infix_to_postfix_multiple_expressions.cpp) | Convert four specified infix expressions to postfix. |
| 26 | [`26_bst_min_max_search.cpp`](./26_bst_min_max_search.cpp) | Build specified BST; search key, inorder, minimum and maximum. |
| 27 | [`27_avl_tree_insert_delete.cpp`](./27_avl_tree_insert_delete.cpp) | AVL insertion/deletion with rebalancing. |
| 28 | [`28_max_heap_array.cpp`](./28_max_heap_array.cpp) | Build max heap from input, insert/delete can be practised through heapify. |
| 29 | [`29_prims_minimum_spanning_tree.cpp`](./29_prims_minimum_spanning_tree.cpp) | Prim MST from A. PDF references a graph image whose weights are unavailable here. |
| 30 | [`30_bfs_dfs_adjacency_list.cpp`](./30_bfs_dfs_adjacency_list.cpp) | BFS and DFS from vertex 1 using the specified adjacency list graph. |
| 31 | [`31_linear_search_item_code.cpp`](./31_linear_search_item_code.cpp) | Linear search for 47 in {14,8,29,3,47,21,35}. |
| 32 | [`32_binary_search_book_ids.cpp`](./32_binary_search_book_ids.cpp) | Binary search 33 and 60 in the specified sorted array. |
| 33 | [`33_insertion_and_merge_sort.cpp`](./33_insertion_and_merge_sort.cpp) | Insertion sort and merge sort; input array is not specified in PDF. |
| 34 | [`34_hashing_linear_probing.cpp`](./34_hashing_linear_probing.cpp) | Size-10 hash table; insert 31,22,43,54,65,76 with linear probing. |
| 35 | [`35_doubly_linked_list_operations.cpp`](./35_doubly_linked_list_operations.cpp) | Doubly linked list insertion, deletion, display forward and backward. |
| 36 | [`36_postfix_evaluation.cpp`](./36_postfix_evaluation.cpp) | Evaluate 8 2 3 ^ / 2 3 * + 5 3 * - using an integer stack. |
| 37 | [`37_deque_using_array.cpp`](./37_deque_using_array.cpp) | Array deque with insertion/deletion at front and rear. |
| 38 | [`38_binary_tree_traversals.cpp`](./38_binary_tree_traversals.cpp) | Binary tree inorder, preorder, postorder and level-order traversals. |
| 39 | [`39_bucket_sort.cpp`](./39_bucket_sort.cpp) | Bucket sort the specified decimal values in [0,1). |
| 40 | [`40_sparse_matrix_triplet_transpose.cpp`](./40_sparse_matrix_triplet_transpose.cpp) | Convert matrix to (row,column,value) triplets and display transpose. |
| 41 | [`41_queue_using_array.cpp`](./41_queue_using_array.cpp) | Queue ADT using array with enqueue, dequeue, display and boundary checks. |
| 42 | [`42_singly_linked_list_position_count.cpp`](./42_singly_linked_list_position_count.cpp) | Singly linked list insert/delete at given position and count nodes. |
| 43 | [`43_stack_string_reverse_palindrome.cpp`](./43_stack_string_reverse_palindrome.cpp) | Reverse a word using stack and check whether it is a palindrome. |
| 44 | [`44_polynomial_subtraction_evaluation.cpp`](./44_polynomial_subtraction_evaluation.cpp) | Polynomial linked-list style terms; subtract Q from P and evaluate at x. |
| 45 | [`45_infix_to_postfix_expressions.cpp`](./45_infix_to_postfix_expressions.cpp) | Convert the four specified infix expressions to postfix. |
| 46 | [`46_bst_height_leaf_count_mirror.cpp`](./46_bst_height_leaf_count_mirror.cpp) | BST height, leaf count and mirror image. Height counts nodes on longest path. |
| 47 | [`47_avl_balance_factors.cpp`](./47_avl_balance_factors.cpp) | Insert 14,17,11,7,53,4,13 into AVL; display inorder and each balance factor. |
| 48 | [`48_heap_operations_and_sort.cpp`](./48_heap_operations_and_sort.cpp) | Binary max-heap insert/delete and heap sort the input array ascending. |
| 49 | [`49_dijkstra_source_vertex_1.cpp`](./49_dijkstra_source_vertex_1.cpp) | Dijkstra from vertex 1 using specified undirected weighted edges. |
| 50 | [`50_articulation_points_dfs.cpp`](./50_articulation_points_dfs.cpp) | DFS articulation points for the given A-F network. |
| 51 | [`51_linear_search_count_occurrences.cpp`](./51_linear_search_count_occurrences.cpp) | Count occurrences of 7 in {7,3,7,9,7,2,5}. |
| 52 | [`52_binary_search_names_comparisons.cpp`](./52_binary_search_names_comparisons.cpp) | Binary search alphabetically sorted names and count key comparisons. |
| 53 | [`53_quick_and_heap_sort.cpp`](./53_quick_and_heap_sort.cpp) | Quick sort and heap sort the same integer list in ascending order. |
| 54 | [`54_hashing_quadratic_probing.cpp`](./54_hashing_quadratic_probing.cpp) | Insert 89,18,49,58,69 into size-10 table using quadratic probing. |
| 55 | [`55_josephus_circular_linked_list.cpp`](./55_josephus_circular_linked_list.cpp) | Josephus circular linked list for n=7, k=3. |
| 56 | [`56_balanced_brackets_stack.cpp`](./56_balanced_brackets_stack.cpp) | Check correctly nested (), [] and {} brackets with a stack. |
| 57 | [`57_priority_queue_linked_list.cpp`](./57_priority_queue_linked_list.cpp) | Linked-list priority queue; larger numeric priority served first. |
| 58 | [`58_merge_two_sorted_arrays.cpp`](./58_merge_two_sorted_arrays.cpp) | Merge two already-sorted arrays into one sorted array. |
| 59 | [`59_kruskal_union_find.cpp`](./59_kruskal_union_find.cpp) | Read weighted graph; Kruskal MST using union-find. |
| 60 | [`60_kth_largest_using_heap.cpp`](./60_kth_largest_using_heap.cpp) | Find kth largest value using a max heap without sorting the whole array. |

## Important source notes

- Concrete arrays, keys and edges supplied in the question text are embedded in the corresponding programs.
- Q8 does not specify task priorities; the program reads priorities.
- Q9 references a weighted graph not fully present in the extracted text; the program reads an adjacency matrix and uses vertex A as source.
- Q12 omits the actual sorted array and key; the program reads both.
- Q18 omits the start vertex in the question text; this implementation demonstrates traversal from vertex 0.
- Q29 refers to a graph image whose weighted edges are not present in the extracted text; the program reads an adjacency matrix and starts at A.
- Q33 and Q38 omit their sample data; the programs accept input.
- Q40 omits the matrix values; the program accepts a matrix and produces triplet transpose.
- Q52 omits the actual names and lookup key; the program accepts sorted names and a key.
- Priority queue examples use larger numeric values as higher priority. Confirm the convention used by your instructor.
- Infix-to-postfix examples assume single-character operands. Unary operators and multi-character identifiers need a token-based extension.
- Review and test each program before using it in a practical examination.
