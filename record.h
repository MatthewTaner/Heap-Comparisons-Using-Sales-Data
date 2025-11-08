//
// Created by josia on 11/4/2025.
//

#ifndef COP3530_RECORD_H
#define COP3530_RECORD_H
#include <string>


//simple record class
class Record {
private:
    int sales;
    std::string type;

public:
    // constructor
    Record(int sales, std::string type) : sales(sales), type(std::move(type)) {}

    // destructor
    ~Record() = default;

    // getters for heaps
    int get_sales() const { return sales; }
    const std::string& get_type() const { return type; }
};



#endif //COP3530_RECORD_H