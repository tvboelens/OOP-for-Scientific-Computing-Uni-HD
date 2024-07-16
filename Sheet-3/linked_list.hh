#ifndef LINKED_LIST_HH
#define LINKED_LIST_HH

class Node{
    friend class List;
    
    
    public:
        int value {0};
        // Access functions
        void setNextItem(Node* n);
        Node* getNextItem();
        Node* getNextItem() const;
        // Constructors
        Node() {};
        Node(int value_) : value{value_} {};
        Node(int value_, Node* n)
            : value{value_}, next_item {&*n} {};

    private:
        Node* next_item {nullptr};
};

class List{
    public:
        List() : first_item{ nullptr } {};                  // create an empty list
        ~List();                                            // clean up list and all nodes
        Node* first() const;                                // return pointer to first entry
        Node* next(const Node* n) const;                    // return pointer to node after n
        void append(int i);                                 // append a value to the end
        void insert(Node* n, int i);                        // insert a value before n
        void erase(Node* n);                                // remove n from the list
        int len() const;                                    // return number of elements in list
    private:
        Node* first_item;
};

#endif 
