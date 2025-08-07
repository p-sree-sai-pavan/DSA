// This single file is a comprehensive guide to the C++ Standard Template Library (STL).
// It's designed for beginners with a focus on Data Structures & Algorithms (DSA)
// and Competitive Programming (CP).

// --- Header Files ---
#include <iostream>  // For input/output operations (cin, cout)
#include <vector>    // For the vector container
#include <string>    // For using the string class
#include <utility>   // For std::pair
#include <stack>     // For the stack container adaptor
#include <queue>     // For the queue and priority_queue container adaptors
#include <set>       // For set and multiset containers
#include <map>       // For map and multimap containers
#include <list>      // For the list container
#include <deque>     // For the deque container
#include <algorithm> // For common algorithms like sort, binary_search, etc.
#include <unordered_set> // For the unordered_set container
#include <unordered_map> // For the unordered_map container

// Allows us to use names for objects and variables from the standard library without the `std::` prefix.
using namespace std;

// --- Function Prototypes ---
// This helps organize the code and makes the main function readable.
void explainFunctions();
void explainPairs();
void explainVectors();
void explainListAndDeque();
void explainStack();
void explainQueue();
void explainPriorityQueue();
void explainSetAndMultiset();
void explainUnorderedSet();
void explainMapAndMultimap();
void explainUnorderedMap();
void explainAlgorithms();

// Custom comparator function for sorting pairs.
bool comp(pair<int, int> p1, pair<int, int> p2);

// --- Main Function ---
// The entry point of the program. It calls all the explanation functions.
int main() {
    cout << "--- C++ STL Guide for Beginners (CP/DSA Focus) ---" << endl;
    cout << "Timestamp: Thursday, August 7, 2025 at 10:32 PM IST" << endl;
    cout << "Location: Guwahati, Assam, India\n" << endl;

    // The guide is structured from basic utilities to complex containers and algorithms.
    explainFunctions();
    explainPairs();

    cout << "\n\n--- STL Containers ---";
    cout << "\n----------------------\n";
    explainVectors();
    explainListAndDeque();
    explainStack();
    explainQueue();
    explainPriorityQueue();
    explainSetAndMultiset();
    explainUnorderedSet();
    explainMapAndMultimap();
    explainUnorderedMap();

    cout << "\n\n--- STL Algorithms ---";
    cout << "\n----------------------\n";
    explainAlgorithms();

    cout << "\n--- End of Guide ---" << endl;
    return 0; // Indicates successful execution
}

// --- Function Definitions ---

/**
 * @brief Demonstrates basic function types in C++.
 */
void explainFunctions() {
    cout << "\n--- 1. Functions ---" << endl;
    cout << "Functions are blocks of reusable code." << endl;
    
    // A 'void' function doesn't return a value.
    auto printGreeting = []() {
        cout << "  This is a void function." << endl;
    };
    printGreeting();

    // A return-type function returns a value of a specific type (e.g., int).
    auto sum = [](int a, int b) {
        return a + b;
    };
    int result = sum(5, 3);
    cout << "  This is a return-type function. sum(5, 3) = " << result << endl;
}

/**
 * @brief Explains std::pair for storing two related values.
 * @details Useful for storing coordinates (x, y), or items with a key and value before using a map.
 */
void explainPairs() {
    cout << "\n--- 2. std::pair ---" << endl;
    
    // A pair stores two values, which can be of different types.
    pair<int, string> p = {1, "Striver"};
    cout << "  Simple Pair: {" << p.first << ", " << p.second << "}" << endl;

    // Pairs can be nested to store more values.
    pair<int, pair<int, int>> nested_p = {1, {3, 4}};
    cout << "  Nested Pair: {" << nested_p.first << ", {" << nested_p.second.first << ", " << nested_p.second.second << "}}" << endl;

    // You can create arrays of pairs.
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << "  Array of Pairs: Second element of the second pair is " << arr[1].second << endl;
}

/**
 * @brief Explains std::vector, the most common dynamic array in CP/DSA.
 */
void explainVectors() {
    cout << "\n--- 3. std::vector ---" << endl;
    cout << "Vectors are dynamic arrays. Use them when you don't know the size of your array beforehand." << endl;
    vector<int> v;

    // Time Complexity: O(1) on average (amortized).
    v.push_back(10);
    v.emplace_back(20); // emplace_back is often slightly faster.
    cout << "  Vector after push_back/emplace_back: {10, 20}" << endl;

    // Accessing elements: O(1)
    cout << "  Accessing v[1]: " << v[1] << endl;

    // Erasing elements: O(n) because elements might need to be shifted.
    v.erase(v.begin()); // Erases the first element -> {20}
    cout << "  Vector after erasing first element: {20}" << endl;

    // Inserting elements: O(n)
    v.insert(v.begin(), 2, 5); // Insert 5 twice at the beginning -> {5, 5, 20}
    cout << "  Vector after inserting {5, 5}: ";
    for (auto element : v) cout << element << " ";
    cout << endl;

    // Swapping vectors (O(1))
    vector<int> v2 = {100, 200};
    v.swap(v2);
    cout << "  Vector v after swapping with v2: ";
    for (auto el : v) cout << el << " "; // {100, 200}
    cout << endl;

    // Other useful functions (O(1))
    cout << "  Current size: " << v.size() << endl;
    v.pop_back(); // Removes the last element -> {100}
    cout << "  Vector after pop_back: {100}" << endl;
    v.clear(); // Erases all elements
    cout << "  Is vector empty after clear()? " << (v.empty() ? "Yes" : "No") << endl;
}

/**
 * @brief Briefly explains std::list and std::deque.
 */
void explainListAndDeque() {
    cout << "\n--- 4. std::list & std::deque ---" << endl;
    cout << "Use these when you need fast insertions/deletions at the ends, which is slow for vectors." << endl;
    
    // std::list (doubly linked list): Fast insertion/deletion anywhere (O(1)), but slow random access.
    list<int> ls;
    ls.push_front(5); // O(1)
    ls.push_back(10); // O(1)
    cout << "  std::list with push_front and push_back: {5, 10}" << endl;

    // std::deque (double-ended queue): Fast at both ends.
    deque<int> dq;
    dq.push_front(5); // O(1)
    dq.push_back(10); // O(1)
    cout << "  std::deque with push_front and push_back: {5, 10}" << endl;
}

/**
 * @brief Explains std::stack (LIFO - Last-In, First-Out).
 * @details Think of a stack of plates. All operations are O(1).
 */
void explainStack() {
    cout << "\n--- 5. std::stack (LIFO) ---" << endl;
    stack<string> st;
    st.push("First In");
    st.push("Second In");
    st.push("Third In"); // Stack: {"First", "Second", "Third"} (top)

    cout << "  Top element (last one in): " << st.top() << endl;
    st.pop(); // Removes "Third In"
    cout << "  New top element after pop: " << st.top() << endl;
}

/**
 * @brief Explains std::queue (FIFO - First-In, First-Out).
 * @details Think of a line at a ticket counter. All operations are O(1).
 */
void explainQueue() {
    cout << "\n--- 6. std::queue (FIFO) ---" << endl;
    queue<string> q;
    q.push("First In");
    q.push("Second In");
    q.push("Third In"); // Queue: {"First" (front), "Second", "Third" (back)}

    cout << "  Front element (first one in): " << q.front() << endl;
    cout << "  Back element (last one in): " << q.back() << endl;
    q.pop(); // Removes "First In"
    cout << "  New front element after pop: " << q.front() << endl;
}

/**
 * @brief Explains std::priority_queue (Heaps).
 * @details Always keeps the element with the highest priority at the top.
 */
void explainPriorityQueue() {
    cout << "\n--- 7. std::priority_queue (Heaps) ---" << endl;
    // Time Complexity: push/pop -> O(log n), top -> O(1)
    
    // Max-Heap (default): largest element has highest priority.
    priority_queue<int> max_pq;
    max_pq.push(5);
    max_pq.push(2);
    max_pq.push(8);
    cout << "  Top of max-heap (largest element): " << max_pq.top() << endl;

    // Min-Heap: smallest element has highest priority.
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(5);
    min_pq.push(2);
    min_pq.push(8);
    cout << "  Top of min-heap (smallest element): " << min_pq.top() << endl;
}

/**
 * @brief Explains std::set and std::multiset (sorted elements).
 */
void explainSetAndMultiset() {
    cout << "\n--- 8. std::set & std::multiset (Sorted) ---" << endl;
    cout << "Use a set when you need to store unique elements in sorted order." << endl;
    // Time Complexity for insert, find, erase, count: O(log n)
    
    set<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(1); // Duplicate is ignored
    cout << "  Set elements (unique, sorted): ";
    for (auto el : s) cout << el << " "; // 1 2 5
    cout << endl;

    // lower_bound/upper_bound are very useful in CP
    auto it = s.lower_bound(2); // points to 2 or first element > 2
    cout << "  Lower bound of 2 in set is: " << *it << endl;

    // Multiset allows duplicates, also sorted.
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    cout << "  Multiset (allows duplicates): ";
    for (auto el : ms) cout << el << " "; // 1 1 2
    cout << endl;
}

/**
 * @brief Explains std::unordered_set.
 */
void explainUnorderedSet() {
    cout << "\n--- 9. std::unordered_set (Unique, Unsorted) ---" << endl;
    cout << "Use when you need uniqueness but NOT order. It's faster than set on average." << endl;
    // Time Complexity: O(1) on average, O(n) in the worst case (due to hash collisions).
    
    unordered_set<int> us;
    us.insert(2);
    us.insert(1);
    us.insert(5);
    cout << "  Unordered set elements (random order): ";
    for (auto el : us) cout << el << " ";
    cout << endl;
}

/**
 * @brief Explains std::map and std::multimap (key-value pairs, sorted by key).
 */
void explainMapAndMultimap() {
    cout << "\n--- 10. std::map & std::multimap (Key-Value, Sorted by Key) ---" << endl;
    cout << "Use when you need to map keys to values and require the keys to be sorted." << endl;
    // Time Complexity for insert, find, erase: O(log n)
    
    map<string, int> mpp;
    mpp["apple"] = 10;
    mpp["orange"] = 30;
    mpp.insert({"banana", 20});

    cout << "  Map elements (unique keys, sorted by key):" << endl;
    for (auto const& [key, val] : mpp) {
        cout << "    Key: " << key << ", Value: " << val << endl;
    }
    
    // Multimap allows duplicate keys.
    multimap<string, int> mmpp;
    mmpp.insert({"apple", 10});
    mmpp.insert({"apple", 50}); // Duplicate key is allowed
    mmpp.insert({"banana", 20});
    cout << "\n  Multimap elements (allows duplicate keys):" << endl;
    for (auto const& [key, val] : mmpp) {
        cout << "    Key: " << key << ", Value: " << val << endl;
    }
}

/**
 * @brief Explains std::unordered_map.
 */
void explainUnorderedMap() {
    cout << "\n--- 11. std::unordered_map (Key-Value, Unsorted) ---" << endl;
    cout << "The go-to hash map in C++. Use when you need key-value pairs but NOT order. Faster than map." << endl;
    // Time Complexity: O(1) on average, O(n) in the worst case.
    
    unordered_map<string, int> umpp;
    umpp["apple"] = 10;
    umpp["orange"] = 30;
    umpp.insert({"banana", 20});

    cout << "  Unordered_map elements (random order):" << endl;
    for (auto const& [key, val] : umpp) {
        cout << "    Key: " << key << ", Value: " << val << endl;
    }
}

/**
 * @brief Custom comparison function for sorting pairs.
 * @details Sorts by second element ascending. If second elements are equal,
 * sorts by first element descending. This kind of custom logic is common in CP.
 * @return True if p1 should come before p2, false otherwise.
 */
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;
    return p1.first > p2.first;
}

/**
 * @brief Explains various useful STL algorithms crucial for CP/DSA.
 */
void explainAlgorithms() {
    cout << "\n--- 12. STL Algorithms ---" << endl;
    
    vector<int> v = {3, 1, 4, 1, 5, 9};
    cout << "  Original vector: {3, 1, 4, 1, 5, 9}" << endl;

    // --- Sorting --- O(n log n)
    sort(v.begin(), v.end());
    cout << "  Sorted Ascending: ";
    for(int el : v) cout << el << " "; // 1 1 3 4 5 9
    cout << endl;

    // --- Binary Search --- O(log n) on a sorted range
    bool isPresent = binary_search(v.begin(), v.end(), 3);
    cout << "  Is 3 present in sorted vector? " << (isPresent ? "Yes" : "No") << endl;

    // --- Lower/Upper Bound --- O(log n) on a sorted range
    auto it1 = lower_bound(v.begin(), v.end(), 4); // >= 4
    cout << "  Lower bound of 4 is at index: " << (it1 - v.begin()) << endl;
    auto it2 = upper_bound(v.begin(), v.end(), 4); // > 4
    cout << "  Upper bound of 4 is at index: " << (it2 - v.begin()) << endl;

    // --- Popcount --- O(1)
    int num = 7; // Binary is 111
    cout << "\n  __builtin_popcount(7) (count of set bits): " << __builtin_popcount(num) << endl;

    // --- Permutations ---
    string s = "123";
    sort(s.begin(), s.end());
    cout << "\n  All permutations of '123': ";
    do {
        cout << s << " ";
    } while (next_permutation(s.begin(), s.end()));
    cout << endl;

    // --- Max/Min Element --- O(n)
    cout << "\n  Max element in {3,1,4,1,5,9}: " << *max_element(v.begin(), v.end()) << endl;
    cout << "  Min element in {3,1,4,1,5,9}: " << *min_element(v.begin(), v.end()) << endl;
}
