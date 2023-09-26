class list {
private:
    int size;
    int capacity;
    int *array;
public:
    // Constructor
    explicit list(int size);
    //Destructor
    ~list();

    void display() const;
    bool replace(int newNum, int index);
    [[nodiscard]] int access(int index) const;
    bool append(int num);
    int getElement(int index) const;
    int getSize() const;
};