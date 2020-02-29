#include <iterator>

template<typename T>
class mylist;

template<typename T>
class mylist_iterator;

//---------------mylist_node------------------------------
template<typename T>
class mylist_node {

    friend class mylist<T>;
    friend class mylist_iterator<T>;

    T elem;
    mylist_node<T> *next;

    mylist_node(const T &t, mylist_node<T> *next) : elem(t), next(next) {}

    ~mylist_node() { delete next; }

};

//-------------mylist----------------------------------------------
template<typename T>
class mylist {
    mylist_node<T> *head, *tail;
    int count = 0;
public:
    typedef mylist_iterator<T> iterator;

    mylist() : head(nullptr), tail(nullptr) {}

    ~mylist() { delete head; };

    void push_back(const T &elem);

    typedef std::ptrdiff_t difference_type;

    T &operator[](difference_type n) {
        auto tmp = head;
        for (int i = 0; i != n; ++i) { tmp = tmp->next; }
        return tmp->elem;
    }

    void factorial(mylist_iterator<T> start, mylist_iterator<T> end);

    iterator begin() { return mylist_iterator<T>(head); };

    iterator end() { return mylist_iterator<T>(nullptr); };
};


//----------------------mylist_iterator------------------------------------------------------------
template<typename T>
class mylist_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
    friend class mylist<T>;

public:
    mylist_node<T> *p;

    mylist_iterator(mylist_node<T> *p) : p(p) {}

    typedef std::ptrdiff_t difference_type;

    T &operator*();

    const mylist_iterator &operator++();

    const mylist_iterator operator++(int other);

    bool operator!=(const mylist_iterator<T> &other) const;

    bool operator==(const mylist_iterator<T> &other);

};

//---------------------implements-------------------------------------------------
template<typename T>
T &mylist_iterator<T>::operator*() {
    return p->elem;
}

template<typename T>
bool mylist_iterator<T>::operator!=(const mylist_iterator<T> &other) const {
    return p != other.p;
}

template<typename T>
bool mylist_iterator<T>::operator==(const mylist_iterator<T> &other) {
    return p == other.p;
}

template<typename T>
const mylist_iterator<T> &mylist_iterator<T>::operator++() {
    p = p->next;
    return *this;
}

template<typename T>
const mylist_iterator<T> mylist_iterator<T>::operator++(int other) {
    mylist_iterator tmp = *this;
    if (p->next != nullptr)
        p = p->next;
    else
        p = nullptr;
    return tmp;
}


//---------------------factorial function-------------------------------
template<typename T>
void mylist<T>::factorial(mylist_iterator<T> start, mylist_iterator<T> end) {
    mylist_iterator<T> i(start);
    int k = 1;
    int p = 1;
    for (i; i != end; ++i, ++k) {
        p = 1;
        for (int j = 1; j <= k; ++j) {
            p *= j;
        }
        *i = p;
    }
}

//---------------------push_back----------------------------
template<typename T>
void mylist<T>::push_back(const T &elem) {
    mylist_node<T> *node = new mylist_node<T>(elem, nullptr);
    if (head == nullptr) {
        head = node;
    } else {
        tail->next = node;
    }
    tail = node;
    ++count;
}
