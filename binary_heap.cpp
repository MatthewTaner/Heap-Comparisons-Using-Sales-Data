//
// Created by josia on 11/4/2025.
//

#include "binary_heap.h"
#include "helpers.h"
#include <stdexcept>
#include <utility>
using namespace std;

void BinaryHeap::build(const vector<Record>& rows) {
    heap = rows;
    int n = heap.size();
    for (int i = n/2 - 1; i >= 0; --i) {
        heapify_down(i);
    }
}


void BinaryHeap::push(const Record& r) {
    heap.push_back(r);
    heapify_up(heap.size() - 1);
}

const Record& BinaryHeap::top() const {
    if (heap.empty()) throw runtime_error("BinaryHeap::top on empty");
    return heap[0];
}

void BinaryHeap::pop() {
    if (heap.empty()) return;
    swap(heap[0], heap.back());
    heap.pop_back();
    if (!heap.empty()) heapify_down(0);
}

void BinaryHeap::heapify_up(size_t i) {
    while (i > 0) {
        size_t p = parent(i);
        if (higher(heap[i], heap[p])) {
            swap(heap[i], heap[p]);
            i = p;
        } else {
            break;
        }
    }
}

void BinaryHeap::heapify_down(size_t i) {
    const size_t n = heap.size();
    while (true) {
        size_t best = i;
        size_t L = left(i), R = right(i);

        if (L < n && higher(heap[L], heap[best])) best = L;
        if (R < n && higher(heap[R], heap[best])) best = R;

        if (best == i) break;
        swap(heap[i], heap[best]);
        i = best;
    }
}
