#include "Array.h"
#include "math.h"

void Array::push_back(string element) {
    if (size == capacity) {
        capacity *= 2;
        string* newData = new string[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[size++] = element;
}

void Array::insert_at(int index, string element) {
    if (index < 0 || index > size) {
        throw out_of_range("Index out of range");
    }
    if (size == capacity) {
        capacity *= 2;
        string* newData = new string[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = element;
    ++size;
}

string Array::get_at(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

void Array::remove_at(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    --size;
}

void Array::set_at(int index, string element) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    data[index] = element;
}

int Array::find_value(const string& value){
    int res = -1;
    for (int i = 0; i < size; ++i){
        if (low_word(data[i]) == low_word(value)){
            if (data[i] == value) return 1;
            res = 0;
        }
    }

    return res;
}

void Array::print() {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

string low_word(const string& word){
    string temp;
    for (auto i: word){
        temp += tolower(i);
    }
    return temp;
}
