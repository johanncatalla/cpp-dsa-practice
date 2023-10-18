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
    void replace(int newNum, int index);
    [[nodiscard]] int access(int index) const;
    bool append(int num);
    void insert(int num, int index);
    bool del(int index);
    [[nodiscard]] bool search(int num) const;
    void sort();
    [[nodiscard]] int getElement(int index) const;
    [[nodiscard]] int getSize() const;
    [[nodiscard]] int getCapacity() const;
};