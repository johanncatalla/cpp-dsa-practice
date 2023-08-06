#include <algorithm> // std::copy
#include <cstddef> // std::size_t
#include <iostream>

class dumb_array
{
public:
    // (default) constructor
    dumb_array(std::size_t size = 0)
        : mSize(size),
          mArray(mSize ? new int[mSize]() : nullptr)
    {
    }

    // copy-constructor
    friend void swap(dumb_array &first, dumb_array &second) // nothrow
    {
        // enable ADL (not necessary in our case, but good practice)
        using std::swap;
        
        // by swapping the members of the two objects,
        // the two objects are effectively swapped
        swap(first.mSize, second.mSize);
        swap(first.mArray, second.mArray);
    }

    // assignment operator
    dumb_array &operator=(dumb_array other) // (1)
    {
        swap(*this, other); // (2)
        return *this;
    }

    // destructor
    ~dumb_array()
    {
        delete [] mArray;
    }

    auto getArray(void) const {
        return mArray;
    }
    
    std::size_t getSize(void) const {
        return mSize;
    }

private:
    std::size_t mSize;
    int* mArray;
};

