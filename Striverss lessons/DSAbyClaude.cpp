/*
===============================================================================
                    COMPLETE DSA & COMPETITIVE PROGRAMMING GUIDE
===============================================================================
This comprehensive guide covers all essential topics needed to master DSA and CP.
Each section includes theory, implementation, and practical examples.
Study this systematically to become a DSA and CP expert.
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
                            1. TIME & SPACE COMPLEXITY
===============================================================================
Understanding complexity is crucial for writing efficient algorithms.

Time Complexity (Big O Notation):
- O(1): Constant time - operations that take same time regardless of input size
- O(log n): Logarithmic time - binary search, tree operations
- O(n): Linear time - single loop through data
- O(n log n): Log-linear time - efficient sorting algorithms
- O(n²): Quadratic time - nested loops
- O(2^n): Exponential time - recursive solutions with overlapping subproblems

Space Complexity: Additional memory used by algorithm excluding input space
*/

void complexityExamples() {
    // O(1) - Constant Time
    int arr[100];
    cout << arr[50] << endl; // Always takes same time
    
    // O(log n) - Binary Search
    vector<int> v = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;
    int left = 0, right = v.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[mid] == target) break;
        else if (v[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    
    // O(n) - Linear Time
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    
    // O(n²) - Quadratic Time
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            // Some operation
        }
    }
}

/*
===============================================================================
                            2. ARRAYS & STRINGS
===============================================================================
Arrays: Contiguous memory locations storing elements of same type
Strings: Arrays of characters with special properties

Key Operations:
- Access: O(1)
- Search: O(n)
- Insertion/Deletion: O(n) for arbitrary position
*/

class ArrayStringOperations {
public:
    // Two Pointer Technique - Very important for CP
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
    
    // Sliding Window Technique - Essential for substring problems
    int maxSubarraySum(vector<int>& arr) {
        // Kadane's Algorithm - O(n)
        int maxSoFar = arr[0], maxEndingHere = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
    
    // String manipulation - KMP Algorithm for pattern matching
    vector<int> computeLPS(string pattern) {
        int n = pattern.length();
        vector<int> lps(n, 0);
        int len = 0, i = 1;
        
        while (i < n) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) len = lps[len - 1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    
    // Prefix Sum - Important for range queries
    vector<int> prefixSum(vector<int>& arr) {
        vector<int> prefix(arr.size());
        prefix[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }
        return prefix;
    }
};

/*
===============================================================================
                            3. LINKED LISTS
===============================================================================
Dynamic data structure where elements are stored in nodes with pointers
Types: Singly, Doubly, Circular

Advantages: Dynamic size, efficient insertion/deletion
Disadvantages: No random access, extra memory for pointers
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedListOperations {
public:
    // Reverse a linked list - Very common interview question
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    
    // Detect cycle using Floyd's algorithm (Tortoise and Hare)
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) return false;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (slow != fast) {
            if (!fast || !fast->next) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
    
    // Merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        
        current->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

/*
===============================================================================
                            4. STACKS & QUEUES
===============================================================================
Stack: LIFO (Last In First Out) - Operations at one end
Queue: FIFO (First In First Out) - Insert at rear, remove from front

Applications:
- Stack: Function calls, expression evaluation, backtracking
- Queue: BFS, scheduling, buffering
*/

class StackQueueOperations {
public:
    // Valid Parentheses - Classic stack problem
    bool isValidParentheses(string s) {
        stack<char> stk;
        unordered_map<char, char> mapping = {
            {')', '('}, {']', '['}, {'}', '{'}
        };
        
        for (char c : s) {
            if (mapping.find(c) != mapping.end()) {
                if (stk.empty() || stk.top() != mapping[c]) return false;
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
    
    // Implement Queue using Stacks
    class MyQueue {
        stack<int> input, output;
    public:
        void push(int x) {
            input.push(x);
        }
        
        int pop() {
            peek();
            int val = output.top();
            output.pop();
            return val;
        }
        
        int peek() {
            if (output.empty()) {
                while (!input.empty()) {
                    output.push(input.top());
                    input.pop();
                }
            }
            return output.top();
        }
        
        bool empty() {
            return input.empty() && output.empty();
        }
    };
    
    // Next Greater Element - Important pattern
    vector<int> nextGreaterElement(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        stack<int> stk;
        
        for (int i = 0; i < nums.size(); i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                result[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }
};

/*
===============================================================================
                            5. TREES
===============================================================================
Hierarchical data structure with root node and subtrees
Types: Binary Tree, BST, AVL, Red-Black, Segment Tree, Trie

Binary Tree Properties:
- Max nodes at level i: 2^i
- Max nodes in tree of height h: 2^(h+1) - 1
- Min height with n nodes: log₂(n+1) - 1
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class TreeOperations {
public:
    // Tree Traversals - Fundamental operations
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
    
    void inorderHelper(TreeNode* node, vector<int>& result) {
        if (node) {
            inorderHelper(node->left, result);
            result.push_back(node->val);
            inorderHelper(node->right, result);
        }
    }
    
    // Level Order Traversal (BFS)
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(currentLevel);
        }
        return result;
    }
    
    // Maximum Depth of Binary Tree
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    
    // Lowest Common Ancestor
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right) return root;
        return left ? left : right;
    }
    
    // Binary Search Tree Operations
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        
        if (val < root->val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
        
        return root;
    }
    
    bool isValidBST(TreeNode* root) {
        return validateBST(root, LONG_MIN, LONG_MAX);
    }
    
    bool validateBST(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;
        
        if (node->val <= minVal || node->val >= maxVal) return false;
        
        return validateBST(node->left, minVal, node->val) &&
               validateBST(node->right, node->val, maxVal);
    }
};

/*
===============================================================================
                            6. HEAPS (PRIORITY QUEUES)
===============================================================================
Complete binary tree satisfying heap property
Max Heap: Parent ≥ Children
Min Heap: Parent ≤ Children

Applications: Dijkstra's algorithm, heap sort, finding kth largest element
Time Complexity: Insert/Delete O(log n), Get min/max O(1)
*/

class HeapOperations {
public:
    // Kth Largest Element - Classic heap problem
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
    
    // Merge K Sorted Lists using heap
    struct ListNodeComparator {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, ListNodeComparator> pq;
        
        for (ListNode* list : lists) {
            if (list) pq.push(list);
        }
        
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            current->next = node;
            current = current->next;
            
            if (node->next) pq.push(node->next);
        }
        
        return dummy.next;
    }
    
    // Top K Frequent Elements
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) count[num]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        for (auto& p : count) {
            pq.push({p.second, p.first});
            if (pq.size() > k) pq.pop();
        }
        
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

/*
===============================================================================
                            7. GRAPHS
===============================================================================
Collection of vertices connected by edges
Types: Directed/Undirected, Weighted/Unweighted, Cyclic/Acyclic

Representations:
1. Adjacency Matrix: O(V²) space, O(1) edge lookup
2. Adjacency List: O(V+E) space, O(degree) edge lookup

Graph Traversals:
- DFS: Stack-based or recursive, explores as far as possible
- BFS: Queue-based, explores level by level
*/

class GraphOperations {
    vector<vector<int>> adj;
    int V;
    
public:
    GraphOperations(int vertices) : V(vertices) {
        adj.resize(V);
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }
    
    // Depth First Search
    void DFS(int v, vector<bool>& visited, vector<int>& result) {
        visited[v] = true;
        result.push_back(v);
        
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited, result);
            }
        }
    }
    
    vector<int> dfsTraversal(int start) {
        vector<bool> visited(V, false);
        vector<int> result;
        DFS(start, visited, result);
        return result;
    }
    
    // Breadth First Search
    vector<int> bfsTraversal(int start) {
        vector<bool> visited(V, false);
        vector<int> result;
        queue<int> q;
        
        visited[start] = true;
        q.push(start);
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            result.push_back(v);
            
            for (int neighbor : adj[v]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return result;
    }
    
    // Cycle Detection in Undirected Graph
    bool hasCycleDFS(int v, vector<bool>& visited, int parent) {
        visited[v] = true;
        
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                if (hasCycleDFS(neighbor, visited, v)) return true;
            } else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }
    
    bool hasCycle() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i] && hasCycleDFS(i, visited, -1)) {
                return true;
            }
        }
        return false;
    }
    
    // Shortest Path Algorithms
    
    // Dijkstra's Algorithm - Single Source Shortest Path
    vector<int> dijkstra(int src, vector<vector<pair<int, int>>>& weightedAdj) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        dist[src] = 0;
        pq.push({0, src});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            for (auto& edge : weightedAdj[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
    
    // Topological Sort (for DAG)
    vector<int> topologicalSort() {
        vector<int> indegree(V, 0);
        
        // Calculate indegrees
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        vector<int> result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);
            
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }
        
        return result.size() == V ? result : vector<int>(); // Empty if cycle exists
    }
};

/*
===============================================================================
                            8. DYNAMIC PROGRAMMING
===============================================================================
Method for solving complex problems by breaking them down into simpler subproblems
Key Properties:
1. Overlapping Subproblems
2. Optimal Substructure

Approaches:
1. Top-down (Memoization): Recursion + Cache
2. Bottom-up (Tabulation): Iterative solution

Common Patterns:
- Linear DP, Grid DP, Interval DP, Tree DP, Digit DP
*/

class DynamicProgramming {
public:
    // Fibonacci - Classic DP introduction
    int fibonacci(int n) {
        if (n <= 1) return n;
        
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    
    // Longest Common Subsequence - 2D DP
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    
    // Coin Change - Classic DP problem
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
    
    // 0/1 Knapsack Problem
    int knapsack(int W, vector<int>& weights, vector<int>& values) {
        int n = weights.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                if (weights[i-1] <= w) {
                    dp[i][w] = max(dp[i-1][w], 
                                  dp[i-1][w - weights[i-1]] + values[i-1]);
                } else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        return dp[n][W];
    }
    
    // Longest Increasing Subsequence - O(n log n) solution
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        
        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) {
                tails.push_back(num);
            } else {
                *it = num;
            }
        }
        return tails.size();
    }
    
    // Maximum Subarray Product
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(maxSoFar, minSoFar);
            }
            
            maxSoFar = max(nums[i], maxSoFar * nums[i]);
            minSoFar = min(nums[i], minSoFar * nums[i]);
            
            result = max(result, maxSoFar);
        }
        return result;
    }
};

/*
===============================================================================
                            9. SORTING ALGORITHMS
===============================================================================
Comparison-based vs Non-comparison based
Stable vs Unstable sorting

Time Complexities:
- Bubble, Selection, Insertion Sort: O(n²)
- Merge Sort, Heap Sort: O(n log n) always
- Quick Sort: O(n log n) average, O(n²) worst case
- Counting, Radix, Bucket Sort: O(n) for specific cases
*/

class SortingAlgorithms {
public:
    // Merge Sort - Divide and Conquer, Stable
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
    
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) temp[k++] = arr[i++];
            else temp[k++] = arr[j++];
        }
        
        while (i <= mid) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];
        
        for (int i = 0; i < k; i++) {
            arr[left + i] = temp[i];
        }
    }
    
    // Quick Sort - Divide and Conquer, In-place
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
    
    // Counting Sort - Non-comparison based
    void countingSort(vector<int>& arr) {
        int maxElement = *max_element(arr.begin(), arr.end());
        vector<int> count(maxElement + 1, 0);
        
        // Count frequencies
        for (int num : arr) count[num]++;
        
        // Reconstruct array
        int index = 0;
        for (int i = 0; i <= maxElement; i++) {
            while (count[i]-- > 0) {
                arr[index++] = i;
            }
        }
    }
};

/*
===============================================================================
                            10. SEARCHING ALGORITHMS
===============================================================================
Linear Search: O(n) - Check each element
Binary Search: O(log n) - For sorted arrays

Binary Search Variants:
- Find exact element
- Find first/last occurrence
- Find insertion position
- Search in rotated array
*/

class SearchingAlgorithms {
public:
    // Binary Search - Classic implementation
    int binarySearch(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    
    // Find First and Last Position
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
    
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                result = mid;
                right = mid - 1; // Continue searching left
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
    
    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                result = mid;
                left = mid + 1; // Continue searching right
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
    
    // Search in Rotated Sorted Array
    int searchRotated(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) return mid;
            
            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

/*
===============================================================================
                            11. BACKTRACKING
===============================================================================
Algorithmic technique for solving problems recursively by trying to build
solutions incrementally and abandoning candidates that fail to satisfy
problem constraints.

Key Steps:
1. Choose - Make a choice
2. Constraint - Check if choice is valid
3. Goal - Check if goal is reached
4. Backtrack - Undo choice and try next option
*/

class BacktrackingAlgorithms {
public:
    // N-Queens Problem
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solveNQueensHelper(board, 0, result);
        return result;
    }
    
    void solveNQueensHelper(vector<string>& board, int row, vector<vector<string>>& result) {
        if (row == board.size()) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < board.size(); col++) {
            if (isValidQueenPlacement(board, row, col)) {
                board[row][col] = 'Q';
                solveNQueensHelper(board, row + 1, result);
                board[row][col] = '.'; // Backtrack
            }
        }
    }
    
    bool isValidQueenPlacement(vector<string>& board, int row, int col) {
        int n = board.size();
        
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        
        // Check diagonal (top-left to bottom-right)
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        
        // Check diagonal (top-right to bottom-left)
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        
        return true;
    }
    
    // Generate Parentheses
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHelper("", 0, 0, n, result);
        return result;
    }
    
    void generateParenthesisHelper(string current, int open, int close, int max, vector<string>& result) {
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }
        
        if (open < max) {
            generateParenthesisHelper(current + "(", open + 1, close, max, result);
        }
        if (close < open) {
            generateParenthesisHelper(current + ")", open, close + 1, max, result);
        }
    }
    
    // Sudoku Solver
    bool solveSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValidSudoku(board, row, col, num)) {
                            board[row][col] = num;
                            
                            if (solveSudoku(board)) return true;
                            
                            board[row][col] = '.'; // Backtrack
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            // Check row
            if (board[row][i] == num) return false;
            
            // Check column
            if (board[i][col] == num) return false;
            
            // Check 3x3 box
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) return false;
        }
        return true;
    }
    
    // Combination Sum
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(candidates, target, 0, current, result);
        return result;
    }
    
    void combinationSumHelper(vector<int>& candidates, int target, int start, 
                             vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
            current.push_back(candidates[i]);
            combinationSumHelper(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }
};

/*
===============================================================================
                            12. GREEDY ALGORITHMS
===============================================================================
Makes locally optimal choices at each step, hoping to find global optimum.
Works for problems with greedy choice property and optimal substructure.

When to use Greedy:
- Activity Selection Problem
- Huffman Coding
- Fractional Knapsack
- Minimum Spanning Tree (Kruskal's, Prim's)
*/

class GreedyAlgorithms {
public:
    // Activity Selection Problem
    int activitySelection(vector<pair<int, int>>& activities) {
        sort(activities.begin(), activities.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second; // Sort by finish time
        });
        
        int count = 1;
        int lastFinishTime = activities[0].second;
        
        for (int i = 1; i < activities.size(); i++) {
            if (activities[i].first >= lastFinishTime) {
                count++;
                lastFinishTime = activities[i].second;
            }
        }
        return count;
    }
    
    // Jump Game - Can reach last index
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return maxReach >= nums.size() - 1;
    }
    
    // Minimum Number of Platforms
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int platformsNeeded = 1, maxPlatforms = 1;
        int i = 1, j = 0;
        
        while (i < arr.size() && j < dep.size()) {
            if (arr[i] <= dep[j]) {
                platformsNeeded++;
                i++;
            } else {
                platformsNeeded--;
                j++;
            }
            maxPlatforms = max(maxPlatforms, platformsNeeded);
        }
        return maxPlatforms;
    }
    
    // Gas Station Problem
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0, tank = 0, start = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];
            
            if (tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }
        
        return totalGas >= totalCost ? start : -1;
    }
};

/*
===============================================================================
                            13. DIVIDE & CONQUER
===============================================================================
Paradigm that solves problems by:
1. Divide: Break problem into smaller subproblems
2. Conquer: Solve subproblems recursively
3. Combine: Merge solutions of subproblems

Examples: Merge Sort, Quick Sort, Binary Search, Matrix Multiplication
*/

class DivideAndConquer {
public:
    // Maximum Subarray Sum (Divide & Conquer approach)
    int maxSubarraySum(vector<int>& arr, int left, int right) {
        if (left == right) return arr[left];
        
        int mid = left + (right - left) / 2;
        
        int leftSum = maxSubarraySum(arr, left, mid);
        int rightSum = maxSubarraySum(arr, mid + 1, right);
        int crossSum = maxCrossingSum(arr, left, mid, right);
        
        return max({leftSum, rightSum, crossSum});
    }
    
    int maxCrossingSum(vector<int>& arr, int left, int mid, int right) {
        int leftSum = INT_MIN, sum = 0;
        for (int i = mid; i >= left; i--) {
            sum += arr[i];
            leftSum = max(leftSum, sum);
        }
        
        int rightSum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= right; i++) {
            sum += arr[i];
            rightSum = max(rightSum, sum);
        }
        
        return leftSum + rightSum;
    }
    
    // Closest Pair of Points
    struct Point {
        int x, y;
        Point(int x, int y) : x(x), y(y) {}
    };
    
    double distance(Point p1, Point p2) {
        return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }
    
    double closestPairRec(vector<Point>& points, int left, int right) {
        if (right - left <= 3) {
            // Brute force for small arrays
            double minDist = DBL_MAX;
            for (int i = left; i < right; i++) {
                for (int j = i + 1; j < right; j++) {
                    minDist = min(minDist, distance(points[i], points[j]));
                }
            }
            return minDist;
        }
        
        int mid = left + (right - left) / 2;
        Point midPoint = points[mid];
        
        double leftMin = closestPairRec(points, left, mid);
        double rightMin = closestPairRec(points, mid, right);
        
        double minDist = min(leftMin, rightMin);
        
        // Check points near the dividing line
        vector<Point> strip;
        for (int i = left; i < right; i++) {
            if (abs(points[i].x - midPoint.x) < minDist) {
                strip.push_back(points[i]);
            }
        }
        
        return min(minDist, stripClosest(strip, minDist));
    }
    
    double stripClosest(vector<Point>& strip, double d) {
        double minDist = d;
        sort(strip.begin(), strip.end(), [](Point a, Point b) {
            return a.y < b.y;
        });
        
        for (int i = 0; i < strip.size(); i++) {
            for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; j++) {
                minDist = min(minDist, distance(strip[i], strip[j]));
            }
        }
        return minDist;
    }
};

/*
===============================================================================
                            14. BIT MANIPULATION
===============================================================================
Operations on individual bits of numbers.
Bitwise Operators: & (AND), | (OR), ^ (XOR), ~ (NOT), << (Left Shift), >> (Right Shift)

Common Tricks:
- Check if number is power of 2: n & (n-1) == 0
- Get rightmost set bit: n & -n
- Turn off rightmost set bit: n & (n-1)
- XOR of number with itself is 0
*/

class BitManipulation {
public:
    // Count number of 1 bits (Hamming Weight)
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            count++;
            n &= (n - 1); // Turn off the rightmost set bit
        }
        return count;
    }
    
    // Single Number - Every element appears twice except one
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num; // XOR cancels out duplicates
        }
        return result;
    }
    
    // Missing Number from 0 to n
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        for (int num : nums) actualSum += num;
        return expectedSum - actualSum;
        
        // Alternative XOR approach:
        // int result = n;
        // for (int i = 0; i < n; i++) {
        //     result ^= i ^ nums[i];
        // }
        // return result;
    }
    
    // Power of Two
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
    
    // Reverse Bits
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }
        return result;
    }
    
    // Generate all subsets using bit manipulation
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }
    
    // Maximum XOR of Two Numbers in Array
    int findMaximumXOR(vector<int>& nums) {
        int maxResult = 0, mask = 0;
        
        for (int i = 30; i >= 0; i--) {
            mask |= (1 << i);
            unordered_set<int> prefixes;
            
            for (int num : nums) {
                prefixes.insert(num & mask);
            }
            
            int candidate = maxResult | (1 << i);
            for (int prefix : prefixes) {
                if (prefixes.count(candidate ^ prefix)) {
                    maxResult = candidate;
                    break;
                }
            }
        }
        return maxResult;
    }
};

/*
===============================================================================
                            15. MATHEMATICAL ALGORITHMS
===============================================================================
Number Theory, Combinatorics, Probability, and Mathematical Optimization

Important Concepts:
- Prime Numbers, GCD/LCM
- Modular Arithmetic
- Fast Exponentiation
- Sieve of Eratosthenes
*/

class MathematicalAlgorithms {
public:
    // Greatest Common Divisor (Euclidean Algorithm)
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    // Least Common Multiple
    int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
    
    // Fast Exponentiation (Modular)
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    
    // Sieve of Eratosthenes - Find all primes up to n
    vector<bool> sieveOfEratosthenes(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }
    
    // Check if number is prime
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
    
    // Factorial with large numbers (using strings)
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        if (n1 == 0 || n2 == 0) return "0";
        
        vector<int> result(n1 + n2, 0);
        int i_n1 = 0, i_n2 = 0;
        
        for (int i = n1 - 1; i >= 0; i--) {
            int carry = 0;
            int num1_digit = num1[i] - '0';
            i_n2 = 0;
            
            for (int j = n2 - 1; j >= 0; j--) {
                int num2_digit = num2[j] - '0';
                int sum = num1_digit * num2_digit + result[i_n1 + i_n2] + carry;
                carry = sum / 10;
                result[i_n1 + i_n2] = sum % 10;
                i_n2++;
            }
            
            if (carry > 0) {
                result[i_n1 + i_n2] += carry;
            }
            i_n1++;
        }
        
        int i = result.size() - 1;
        while (i >= 0 && result[i] == 0) i--;
        
        if (i == -1) return "0";
        
        string s = "";
        while (i >= 0) s += to_string(result[i--]);
        return s;
    }
    
    // Combinatorics - nCr using Pascal's Triangle
    int combination(int n, int r) {
        if (r > n - r) r = n - r; // Take advantage of symmetry
        
        int result = 1;
        for (int i = 0; i < r; i++) {
            result = result * (n - i) / (i + 1);
        }
        return result;
    }
    
    // Count digits in factorial
    int countDigitsInFactorial(int n) {
        if (n < 2) return 1;
        
        double digits = 0;
        for (int i = 2; i <= n; i++) {
            digits += log10(i);
        }
        return floor(digits) + 1;
    }
};

/*
===============================================================================
                            16. ADVANCED DATA STRUCTURES
===============================================================================
Specialized data structures for specific use cases:
- Trie (Prefix Tree)
- Disjoint Set Union (Union-Find)
- Segment Tree
- Binary Indexed Tree (Fenwick Tree)
*/

// Trie (Prefix Tree) - Efficient string operations
class Trie {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord;
        TrieNode() : isEndOfWord(false) {}
    };
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};

// Disjoint Set Union (Union-Find) - For connectivity queries
class DSU {
    vector<int> parent, rank;
    
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

// Segment Tree - Range queries and updates in O(log n)
class SegmentTree {
    vector<int> tree, lazy;
    int n;
    
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }
    
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    void updateLazy(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node] * (end - start + 1);
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    
    void updateRange(int node, int start, int end, int l, int r, int val) {
        updateLazy(node, start, end);
        if (start > r || end < l) return;
        
        if (start >= l && end <= r) {
            tree[node] += val * (end - start + 1);
            if (start != end) {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }
        
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        updateLazy(2 * node, start, mid);
        updateLazy(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    int queryRange(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return 0;
        updateLazy(node, start, end);
        
        if (start >= l && end <= r) return tree[node];
        
        int mid = (start + end) / 2;
        return queryRange(2 * node, start, mid, l, r) +
               queryRange(2 * node + 1, mid + 1, end, l, r);
    }
    
    void update(int l, int r, int val) {
        updateRange(1, 0, n - 1, l, r, val);
    }
    
    int query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};

/*
===============================================================================
                            17. COMPETITIVE PROGRAMMING TECHNIQUES
===============================================================================
Essential techniques and patterns frequently used in contests:
- Fast I/O
- Template for contests
- Common algorithms and their applications
*/

// Fast I/O for competitive programming
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// Template for competitive programming
class CompetitiveProgramming {
public:
    // Binary search on answer - Common technique
    bool canAchieve(vector<int>& arr, int target, int k) {
        // Implementation depends on specific problem
        return true; // Placeholder
    }
    
    int binarySearchOnAnswer(vector<int>& arr, int k) {
        int left = 0, right = 1e9;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAchieve(arr, mid, k)) {
                result = mid;
                right = mid - 1; // Try for smaller answer
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
    
    // Coordinate compression - For large coordinate values
    vector<int> compress(vector<int>& arr) {
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());
        
        for (int& x : arr) {
            x = lower_bound(sorted_arr.begin(), sorted_arr.end(), x) - sorted_arr.begin();
        }
        return arr;
    }
    
    // Mo's Algorithm - For offline range queries
    struct Query {
        int l, r, idx;
    };
    
    vector<int> mosAlgorithm(vector<int>& arr, vector<Query>& queries) {
        int block_size = sqrt(arr.size());
        
        sort(queries.begin(), queries.end(), [&](Query a, Query b) {
            if (a.l / block_size != b.l / block_size) {
                return a.l / block_size < b.l / block_size;
            }
            return (a.l / block_size & 1) ? a.r < b.r : a.r > b.r;
        });
        
        vector<int> answers(queries.size());
        int currentL = 0, currentR = -1;
        int currentAnswer = 0;
        
        for (Query q : queries) {
            while (currentL > q.l) {
                currentL--;
                // Add arr[currentL] to current answer
            }
            while (currentR < q.r) {
                currentR++;
                // Add arr[currentR] to current answer
            }
            while (currentL < q.l) {
                // Remove arr[currentL] from current answer
                currentL++;
            }
            while (currentR > q.r) {
                // Remove arr[currentR] from current answer
                currentR--;
            }
            
            answers[q.idx] = currentAnswer;
        }
        
        return answers;
    }
    
    // Heavy-Light Decomposition concept (simplified)
    // Used for tree queries in O(log²n)
    
    // Matrix Exponentiation - For recurrence relations
    vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B, int mod) {
        int n = A.size();
        vector<vector<long long>> C(n, vector<long long>(n, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }
        return C;
    }
    
    vector<vector<long long>> matrixPower(vector<vector<long long>> mat, long long p, int mod) {
        int n = mat.size();
        vector<vector<long long>> result(n, vector<long long>(n, 0));
        
        // Identity matrix
        for (int i = 0; i < n; i++) result[i][i] = 1;
        
        while (p > 0) {
            if (p & 1) result = multiply(result, mat, mod);
            mat = multiply(mat, mat, mod);
            p >>= 1;
        }
        return result;
    }
};

/*
===============================================================================
                            MAIN FUNCTION & EXAMPLES
===============================================================================
*/

int main() {
    fastIO();
    
    cout << "=== DSA & CP MASTERY GUIDE EXAMPLES ===" << endl;
    
    // Example 1: Array operations
    ArrayStringOperations arrayOps;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = arrayOps.twoSum(nums, target);
    cout << "Two Sum result: [" << result[0] << ", " << result[1] << "]" << endl;
    
    // Example 2: Maximum subarray sum
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << arrayOps.maxSubarraySum(arr) << endl;
    
    // Example 3: Graph operations
    GraphOperations graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    
    vector<int> dfsResult = graph.dfsTraversal(0);
    cout << "DFS Traversal: ";
    for (int vertex : dfsResult) cout << vertex << " ";
    cout << endl;
    
    // Example 4: Dynamic Programming
    DynamicProgramming dp;
    cout << "10th Fibonacci number: " << dp.fibonacci(10) << endl;
    
    string text1 = "abcde", text2 = "ace";
    cout << "LCS of '" << text1 << "' and '" << text2 << "': " << dp.longestCommonSubsequence(text1, text2) << endl;
    
    // Example 5: Bit manipulation
    BitManipulation bitOps;
    vector<int> singleArr = {2, 2, 1};
    cout << "Single Number: " << bitOps.singleNumber(singleArr) << endl;
    
    // Example 6: Mathematical algorithms
    MathematicalAlgorithms mathOps;
    cout << "GCD of 48 and 18: " << mathOps.gcd(48, 18) << endl;
    cout << "Is 17 prime? " << (mathOps.isPrime(17) ? "Yes" : "No") << endl;
    
    // Example 7: Advanced data structures
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    cout << "Trie search 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Trie starts with 'app': " << (trie.startsWith("app") ? "Yes" : "No") << endl;
    
    DSU dsu(5);
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    cout << "Are 0 and 2 connected? " << (dsu.connected(0, 2) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
===============================================================================
                            STUDY ROADMAP & TIPS
===============================================================================

BEGINNER LEVEL (1-2 months):
1. Master basic syntax and STL containers (vector, stack, queue, map, set)
2. Understand time/space complexity analysis
3. Practice basic array, string, and math problems
4. Learn linear and binary search
5. Understand recursion and basic backtracking

Key Topics to Master:
- Arrays and Strings (2 weeks)
- Basic Math and Number Theory (1 week)
- Recursion and Backtracking (2 weeks)
- Binary Search (1 week)

INTERMEDIATE LEVEL (2-3 months):
1. Master all sorting algorithms
2. Learn linked lists, stacks, queues thoroughly
3. Understand trees and basic tree algorithms
4. Learn graph traversals (BFS, DFS)
5. Introduction to dynamic programming
6. Basic bit manipulation

Key Topics to Master:
- Sorting Algorithms (1 week)
- Linked Lists (1 week)
- Trees and BST (3 weeks)
- Graph Algorithms (3 weeks)
- Dynamic Programming Basics (3 weeks)
- Bit Manipulation (1 week)

ADVANCED LEVEL (3-4 months):
1. Advanced DP patterns and optimization
2. Advanced graph algorithms (shortest path, MST)
3. Segment trees and other advanced data structures
4. String algorithms (KMP, Z-algorithm)
5. Number theory and combinatorics
6. Geometry and mathematical algorithms

Key Topics to Master:
- Advanced DP (4 weeks)
- Advanced Graph Algorithms (3 weeks)
- Advanced Data Structures (3 weeks)
- String Algorithms (2 weeks)
- Mathematical Algorithms (2 weeks)

EXPERT LEVEL (4+ months):
1. Contest-specific techniques
2. Heavy-light decomposition
3. Advanced number theory
4. Computational geometry
5. Network flows
6. Advanced string matching

PRACTICE STRATEGY:
1. Solve problems daily (minimum 2-3 problems)
2. Focus on understanding patterns rather than memorizing solutions
3. Time yourself and practice under contest conditions
4. Review and analyze your mistakes
5. Participate in contests regularly

RECOMMENDED PLATFORMS:
- LeetCode: For interview preparation
- Codeforces: For competitive programming
- AtCoder: For mathematical problems
- SPOJ: For diverse problem sets
- HackerRank: For structured learning

CONTEST PREPARATION:
1. Practice implementation speed
2. Learn to identify problem patterns quickly
3. Master debugging techniques
4. Develop time management skills
5. Build a personal template library

KEY SUCCESS FACTORS:
1. Consistency is more important than intensity
2. Focus on understanding, not memorization
3. Practice a variety of problems
4. Learn from editorial solutions
5. Participate in community discussions

COMMON MISTAKES TO AVOID:
1. Jumping to advanced topics without mastering basics
2. Not practicing implementation regularly
3. Ignoring time/space complexity analysis
4. Not participating in contests
5. Focusing only on problem solving without understanding theory

Remember: Becoming proficient in DSA and CP is a marathon, not a sprint.
Stay consistent, practice regularly, and don't get discouraged by initial difficulties.
Every expert was once a beginner!

===============================================================================
*/