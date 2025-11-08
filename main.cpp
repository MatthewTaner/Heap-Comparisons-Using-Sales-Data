#include <iostream>
#include <chrono>
#include <vector>
#include "csv_loader.h"
#include "binary_heap.h"
#include "fourary_heap.h"

using namespace std;

int main() {

    vector<Record> rows = load_csv("100000 Sales Records.csv");
    //check how many rows
    cout << "Loaded rows: " << rows.size() << endl;

    auto start = chrono::steady_clock::now();
    BinaryHeap bh;
    bh.build(rows);
    auto end = chrono::steady_clock::now();
    cout << "Binary build ms: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;

    start = chrono::steady_clock::now();
    fourary_heap fh;
    fh.build(rows);
    end = chrono::steady_clock::now();
    cout << "4-ary build ms: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;

    start = chrono::steady_clock::now();
    while (!bh.empty()) bh.pop();
    end = chrono::steady_clock::now();
    cout << "Binary extract ms: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;

    start = chrono::steady_clock::now();
    while (!fh.empty()) fh.pop();
    end = chrono::steady_clock::now();
    cout << "4-ary extract ms: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;

    return 0;
}
