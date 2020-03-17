
#include <iostream>

class functor {
    int max;
    int min;
    int odd;
    int even;
    int positive;
    int negative;

    size_t size_;
    int counter;
    size_t half_size;
    int half_element;
    int first_element;
    int last_element;

    bool first_last_is_equal() { return first_element == last_element; }

public:
    functor() = default;

    functor(int size) : max(0), min(500), even(0), odd(0), positive(0), negative(0), counter(0), half_size(0) {

        size_ = size;
        if (size_ % 2 == 0) {
            half_size = size_ / 2;
        } else half_size = (size_ / 2) + 1;

    };

    void operator()(int x) {
        ++counter;

        max = std::max(max, x);
        min = std::min(min, x);

        if (x % 2 == 0) {
            even += x;
        } else odd += x;

        if (x < 0) {
            ++positive;
        } else if (x >= 0) ++negative;

        if (counter == half_size) {
            half_element = x;
        }

        if (counter == 1) {
            first_element = x;
        }
        if (counter == size_) {
            last_element = x;
        }
//        cout << counter;
    }

    void print() {
        std::cout << "-------------------------------" << std::endl;
        std::cout << "max " << max;
        std::cout << std::endl;
        std::cout << "min " << min;
        std::cout << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "even " << even;
        std::cout << std::endl;
        std::cout << "odd " << odd;
        std::cout << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "positive " << positive;
        std::cout << std::endl;
        std::cout << "negative " << negative;
        std::cout << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "equal " << first_last_is_equal();
        std::cout << std::endl;
        std::cout << "half " << half_element;
    }

    /*int max_el() { return max; }

    int min_el() { return min; }

    int even_el() { return even; }

    int odd_el() { return odd; }

    int meno_el() { return positive; }

    int piu_el() { return negative; }

    int half_el() { return half_element; }

    int half_size_el() { return half_size; }

    int first_el() { return first_element; }

    int last_el() { return last_element; }*/


};

