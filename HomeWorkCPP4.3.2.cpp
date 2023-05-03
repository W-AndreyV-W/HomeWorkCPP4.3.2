#include <iostream>
#include <locale.h>

class SmartArray {
public:
    // Копирование массива 
    SmartArray& operator = (const SmartArray& other) {
        if (this != &other) {
            size_ = other.size_;
            num_array = other.num_array;

            delete[] array;
            array = new int[size_];

            for (int i = 0; i < size_; i++) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

    SmartArray (const SmartArray& other) {
        if (this != &other) {
            size_ = other.size_;
            num_array = other.num_array;

            array = new int[size_];

            for (int i = 0; i < size_; i++) {
                array[i] = other.array[i];
            }
        }
    }

    SmartArray(int size) {
        array = new int[size] {};
        size_ = size;
    }

    ~SmartArray() {
        delete[] array;
        array = nullptr;
        delete[] array_new;
        array_new = nullptr;
    }

    void add_element(int number);

    int get_element(int array_out) {
        return array[array_out];
    }

private:
    int* array = nullptr;
    int* array_new = nullptr;
    int size_ = 1;
    int num_array = 0;
   
    // Изменение размера массива
    void changing_array();
};

void SmartArray::changing_array() {

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

void SmartArray::add_element(int number) {

    if (num_array == size_) {
        changing_array();
    }

    array[num_array] = number;
    num_array++;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SmartArray arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    SmartArray new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    SmartArray arr2(arr);

    arr = new_array;

    std::cout << arr.get_element(1) << std::endl;
    std::cout << arr2.get_element(2) << std::endl;
}