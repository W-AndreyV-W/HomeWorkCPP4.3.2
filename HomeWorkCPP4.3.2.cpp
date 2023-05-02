#include <iostream>
#include <locale.h>

class Smart_array {
public:

    // Копирование массива 
    Smart_array& operator = (const Smart_array& other) {
        delete[] array;
        array = new int[other.size_];
        int i = 0;
        for (; i < other.size_; i++) {
            array[i] = other.array[i];
        }
        num_array = i;
        return *this;
    }

    Smart_array(int size) {
        array = new int[size] {};
        size_ = size;
    }
    ~Smart_array() {
        delete[] array;
        array = nullptr;
        delete[] array_new;
        array_new = nullptr;
    }

    void add_element(int number) {
        number_ = number;
        element();
    }

    int get_element(int array_out) {
        return array[array_out];
    }

private:
    int* array = nullptr;
    int* array_new = nullptr;
    int size_ = 1;
    int num_array = 0;
    int number_ = 0;
    // Изменение размера массива
    void changing_array();
    void element();

};

void Smart_array::changing_array() {

    int size_new = 2 * size_;
    array_new = new int[size_new] {};

    for (int i = 0; i < size_; i++) {
        array_new[i] = array[i];
    }

    size_ = size_new;

    delete[] array;
    array = array_new;
    array_new = nullptr;
}

void Smart_array::element() {

    if (num_array == size_) {
        changing_array();
    }

    array[num_array] = number_;
    num_array++;
}



int main()
{
    setlocale(LC_ALL, "Russian");
    Smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    Smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;

    std::cout << arr.get_element(1) << std::endl;
}