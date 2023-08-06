// File: storage.h

template <class T>      // <--- 'class' is synonymous with 'typename'
class Container 
{
private:
    T data;
public:
    explicit Container(const T &d) : data(d) {}
    T getData(void) const{
        return data;
    }
    Container(const Container &f) : data(f.data) {}
};

