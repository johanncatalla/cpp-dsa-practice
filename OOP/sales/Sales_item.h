#ifndef SALESITEM_H
#define SALESITEM_H

#include <iostream>
#include <string>

class Sales_item {

// Declare operators (overloading)
friend std::istream &operator>>(std::istream&, Sales_item&);
friend std::ostream &operator<<(std::ostream&, const Sales_item&);
friend bool operator<(const Sales_item&, const Sales_item&);
friend bool operator==(const Sales_item&, const Sales_item&);

public:
    // Constructors
    Sales_item() = default;
    Sales_item(const std::string &book): bookNo(book) {}
    Sales_item(std::istream &is) { is >> *this; }
public:
    // operations on Sales_item objects
    // member binary operator: left-hand operand bound to implicit this pointer
    Sales_item &operator+=(const Sales_item&);

    std::string isbn() const { return bookNo; }
    double avg_price() const; 

private:
    // Initialize variables
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

inline
bool compareIsbn(const Sales_item &item1, const Sales_item &item2)
{ return item1.isbn() == item2.isbn(); }

// nonmember binary operator: declare parameter for each operand
Sales_item operator+(const Sales_item&, const Sales_item&);

// compare all values
inline bool
operator==(const Sales_item &item1, const Sales_item &item2)
{
    // must be a friend of sales item
    return item1.units_sold == item2.units_sold &&
           item1.revenue == item2.revenue &&
           item1.isbn() == item2.isbn(); 
}

inline bool 
operator !=(const Sales_item &item1, const Sales_item &item2)
{
    return !(item1 == item2);
}

// assumes both object has the same isbn
// add the units sold and revenue of the two objects by storing it in the target object then returning the object
Sales_item& Sales_item::operator+=(const Sales_item &item)
{
    units_sold += item.units_sold;
    revenue += item.revenue;
    return *this;
}

// assumes both objects has the same isbn
// adds two objects
Sales_item operator+(const Sales_item &item1, const Sales_item &item2)
{
    Sales_item ret(item1); // copy (|item1|) into lcoal object that we'll return
    ret += item2; 
    return ret;
}

std::istream& 
operator>>(std::istream& in, Sales_item& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    // check that the inputs succeeded
    if (in)
        s.revenue = s.units_sold * price;
    else 
        s = Sales_item();  // input failed: reset object to default state
    return in;
}

std::ostream& 
operator<<(std::ostream& out, const Sales_item& s)
{
    out << s.isbn() << " " << s.units_sold << " "
        << s.revenue << " " << s.avg_price();
    return out;
}

double Sales_item::avg_price() const
{
    if (units_sold) 
        return revenue/units_sold; 
    else 
        return 0;
}

#endif
