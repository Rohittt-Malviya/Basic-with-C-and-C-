#include "ConceptDetector.hpp"

#include <algorithm>
#include <cctype>
#include <vector>

namespace dsa {

namespace {

struct Rule {
    std::string slug;
    std::string title;
    std::string category;
    std::vector<std::string> strongSignals;
    std::vector<std::string> weakSignals;
    std::string summary;
    std::string how;
    std::string time;
    std::string space;
    std::string mermaid;
    std::vector<std::string> tests;
    std::vector<std::string> edgeCases;
    std::vector<std::string> followUps;
};

const std::vector<Rule> kRules = {
    {"binary-search", "Binary Search", "Searching",
     {"mid", "left", "right", "while(left<=right", "while (left <= right", "sorted"},
     {"target", "arr[mid]", "return mid"},
     "A logarithmic search over a sorted range.",
     "The implementation keeps low/high boundaries, checks the middle element, and discards half of the space each step.",
     "O(log n)", "O(1)",
     "flowchart LR\n    A[Sorted Array] --> B[Find Middle]\n    B --> C{Target == Middle?}\n    C -->|Yes| D[Return]\n    C -->|No| E[Discard Half]\n    E --> B",
     {"Logarithmic reasoning", "Boundary handling", "Sorted-input assumptions"},
     {"Empty input", "Target missing", "Duplicate values"},
     {"Recursive variant", "First/last occurrence", "Unsorted input handling"}},
    {"breadth-first-search", "Breadth-First Search", "Graphs",
     {"queue", "push", "pop", "visited", "adj", "while(!q.empty", "while (!q.empty"},
     {"graph", "level", "front"},
     "A level-order traversal across graph or tree neighbors.",
     "The code starts from a node, expands neighbors via queue order, and marks visited nodes to avoid repeats.",
     "O(V + E)", "O(V)",
     "graph LR\n    A((Start)) --> B((N1))\n    A --> C((N2))\n    B --> D((N3))",
     {"Graph traversal modeling", "Queue discipline", "Visited-state correctness"},
     {"Disconnected graph", "Self loops", "Repeated edges"},
     {"Multi-source BFS", "Shortest path in unweighted graph"}},
    {"depth-first-search", "Depth-First Search", "Graphs",
     {"dfs", "visited", "adj[", "adjacency", "stack<int>", "recursive"},
     {"graph", "neighbor", "traverse"},
     "A depth-first traversal for graphs or trees.",
     "The implementation explores one branch deeply before backtracking, using recursion or an explicit stack.",
     "O(V + E)", "O(V)",
     "graph TD\n    A((Start)) --> B((Child1))\n    B --> D((Deep))\n    A --> C((Child2))",
     {"Recursive reasoning", "Backtracking control", "Visit-state handling"},
     {"Cycles", "Disconnected components", "Recursion depth"},
     {"Iterative stack version", "Topological applications"}},
    {"merge-sort", "Merge Sort", "Sorting",
     {"merge", "mid", "left", "right", "temp", "divide"},
     {"sorted", "recursive", "while"},
     "A divide-and-conquer stable sorting algorithm.",
     "The code recursively splits the array and merges sorted halves using a temporary buffer.",
     "O(n log n)", "O(n)",
     "flowchart TD\n    A[Array] --> B[Split]\n    B --> C[Sort Left]\n    B --> D[Sort Right]\n    C --> E[Merge]\n    D --> E",
     {"Divide-and-conquer", "Stable merge logic", "Auxiliary space trade-offs"},
     {"Empty arrays", "Duplicate elements", "Large recursion depth"},
     {"Bottom-up merge sort", "In-place alternatives"}},
    {"quick-sort", "Quick Sort", "Sorting",
     {"partition", "pivot", "quick", "swap", "low", "high"},
     {"recursive", "while", "for("},
     "A partition-based divide-and-conquer sorting algorithm.",
     "The code chooses a pivot, partitions values around it, and recursively sorts both partitions.",
     "Average O(n log n), Worst O(n^2)", "O(log n) recursion",
     std::string{},
     {"Partition correctness", "Pivot strategy impact", "Recursive decomposition"},
     {"Already-sorted input", "Many duplicates", "Small partitions"},
     {"Randomized pivot", "Three-way partitioning"}},
    {"insertion-sort", "Insertion Sort", "Sorting",
     {"key", "j=i-1", "while(j>=0", "while (j >= 0", "a[j+1]=a[j]"},
     {"for(i=1", "insert"},
     "A simple in-place sorting technique for small or nearly sorted data.",
     "The implementation inserts each element into the sorted prefix by shifting larger elements right.",
     "O(n^2)", "O(1)",
     std::string{},
     {"Loop invariants", "In-place shifts", "Best-vs-worst-case behavior"},
     {"Already sorted", "Reverse sorted", "Duplicate values"},
     {"Binary insertion sort", "Hybrid sort usage"}},
    {"selection-sort", "Selection Sort", "Sorting",
     {"for(i=0", "for(j=i+1", "swap", "min_index", "smallest"},
     {"array", "index"},
     "A quadratic in-place sorting algorithm based on repeated minimum selection.",
     "The code repeatedly selects the smallest remaining element and swaps it to the front.",
     "O(n^2)", "O(1)",
     std::string{},
     {"Nested loop analysis", "Swap minimization", "In-place sorting"},
     {"Duplicate keys", "Single element", "Already sorted input"},
     {"Stable variant discussion", "When to avoid it"}},
    {"matrix-operations", "Matrix Operations", "Arrays",
     {"[3][3]", "matrix", "for(i=0", "for(j=0", "m1", "m2"},
     {"sum", "mul", "transpose"},
     "Basic matrix traversal and arithmetic operations.",
     "The implementation iterates rows and columns and applies arithmetic per cell.",
     "O(r * c)", "O(1) or O(r*c) depending on output storage",
     "graph TD\n    A[Matrix A] --> C[Cell-wise traversal]\n    B[Matrix B] --> C\n    C --> D[Result Matrix]",
     {"2D indexing", "Nested loop reasoning", "Bounds correctness"},
     {"Dimension mismatch", "Overflow for large values"},
     {"Generic N x M extension", "Cache-friendly traversal"}},
    {"factorial-recursion", "Factorial (Recursion)", "Recursion",
     {"factorial", "return n*", "if(n==0", "if (n == 0", "recurs"},
     {"int fact", "n-1"},
     "A recursive factorial computation with base-case termination.",
     "The function multiplies n by factorial(n-1) until reaching the base case.",
     "O(n)", "O(n) recursion stack",
     std::string{},
     {"Base case design", "Recursive stack behavior", "Overflow awareness"},
     {"n = 0", "Negative input", "Large n overflow"},
     {"Iterative equivalent", "Big integer handling"}},
    {"fibonacci-dynamic-programming", "Fibonacci Dynamic Programming", "Dynamic Programming",
     {"fib(", "vector<int> dp", "dp[", "f[i]=f[i-1]+f[i-2]", "memo", "tabulation"},
     {"recursion", "cache", "bottom-up"},
     "An optimized Fibonacci computation using stored subproblem results.",
     "The code reuses prior values instead of recomputing branches repeatedly.",
     "O(n)", "O(n) or O(1) optimized",
     std::string{},
     {"Overlapping subproblems", "State transitions", "Space optimization"},
     {"n=0/1", "Large n overflow"},
     {"Matrix exponentiation", "Fast doubling"}},
    {"linked-list-operations", "Linked List Operations", "Linked Lists",
     {"struct node", "next", "head", "->next", "null"},
     {"insert", "delete", "reverse"},
     "Fundamental linked-list traversal or mutation logic.",
     "The code manipulates node pointers to traverse, insert, delete, or transform the list.",
     "Depends on operation", "O(1) auxiliary for iterative pointer rewiring",
     "flowchart LR\n    A[Node 1] --> B[Node 2]\n    B --> C[Node 3]\n    C --> D[NULL]",
     {"Pointer manipulation", "Memory safety", "Traversal invariants"},
     {"Empty list", "Single node", "Tail updates"},
     {"Recursive reversal", "Cycle detection"}},
    {"file-io-operations", "File I/O Operations", "Systems",
     {"fopen", "fclose", "fprintf", "fscanf", "ifstream", "ofstream"},
     {"file", "read", "write"},
     "Basic file reading/writing operations.",
     "The implementation opens files, performs read/write calls, and closes resources.",
     "O(n) by file length", "O(1) plus buffer",
     std::string{},
     {"Resource handling", "Error checks", "I/O formatting"},
     {"Missing file", "Permission issues", "Partial reads"},
     {"RAII streams", "Binary file support"}},
};

const Rule kFallback{"general-programming-concept", "General Programming Concept", "General", {}, {},
                     "A standalone programming exercise without a confidently identifiable specialized algorithm.",
                     "The implementation focuses on foundational control flow, I/O, or language constructs.",
                     "Not confidently derivable", "Not confidently derivable", std::string{},
                     {"Core syntax and control flow"},
                     {"Input validation", "Boundary conditions"},
                     {"Refactor into reusable functions", "Add automated tests"}};

} // namespace

std::string ConceptDetector::toLower(std::string value) {
    std::transform(value.begin(), value.end(), value.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return value;
}

int ConceptDetector::countSignals(const std::string &text, const std::vector<std::string> &signals) {
    int count = 0;
    for (const auto &signal : signals) {
        if (text.find(toLower(signal)) != std::string::npos) {
            ++count;
        }
    }
    return count;
}

DetectionResult ConceptDetector::detect(const SourceFile &file) const {
    const auto lower = toLower(file.content);

    const Rule *best = &kFallback;
    double bestScore = 0.0;
    for (const auto &rule : kRules) {
        const int strong = countSignals(lower, rule.strongSignals);
        const int weak = countSignals(lower, rule.weakSignals);
        if (!((strong >= 2) || (strong >= 1 && weak >= 2))) {
            continue;
        }

        const double score = strong * 0.22 + weak * 0.08;
        if (score > bestScore) {
            bestScore = score;
            best = &rule;
        }
    }

    DetectionResult result;
    result.file = file;
    result.conceptSlug = best->slug;
    result.conceptTitle = best->title;
    result.category = best->category;
    result.conceptSummary = best->summary;
    result.howItWorks = best->how;
    result.complexityTime = best->time;
    result.complexitySpace = best->space;
    result.interviewTests = best->tests;
    result.edgeCases = best->edgeCases;
    result.followUps = best->followUps;

    if (!best->mermaid.empty()) {
        result.mermaid = best->mermaid;
    }

    const double rawConfidence = std::clamp(bestScore + 0.45, 0.35, 0.99);
    result.confidence = (best == &kFallback) ? 0.45 : rawConfidence;
    result.lowConfidence = result.confidence < 0.70;

    if (lower.find("goto") != std::string::npos) {
        result.improvements.push_back("Avoid goto-style flow where structured control flow is possible.");
    }
    if (lower.find("scanf(") != std::string::npos && lower.find("if") == std::string::npos) {
        result.improvements.push_back("Add input validation after read operations.");
    }
    if (lower.find("void main") != std::string::npos) {
        result.improvements.push_back("Use standard int main() signature for portability.");
    }

    if (result.conceptSlug == "binary-search" || result.conceptSlug == "fibonacci-dynamic-programming" ||
        result.conceptSlug == "merge-sort") {
        result.optimizationComparisonUseful = true;
    }

    return result;
}

} // namespace dsa
