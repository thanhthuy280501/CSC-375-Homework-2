#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <iostream>

template <class DataType>
class Array {
private:
    DataType* elements;  // Pointer to the dynamic array
    int capacity;        // Current capacity of the array
    DataType dud;        // Returned from operator[] if index error occurs
    int errorCode;       // Contains code for error if array misuse occurs

public:
    // Constructor
    Array(int size) {
        if (size < 1) {
            capacity = 1;
            errorCode = 1;  // Nonpositive size error
        } else {
            capacity = size;
            errorCode = 0;  // No error
        }
        elements = new DataType[capacity];
    }

    // Destructor
    ~Array() {
        delete[] elements;
    }

    // Overloaded subscript operator
    DataType& operator[](int index) {
        if (index < 0 || index >= capacity) {
            errorCode |= 2;  // Invalid index error
            return dud;
        }
        return elements[index];
    }

    // Change size of the array
    void changeSize(int newSize) {
        if (newSize < 1) {
            errorCode |= 4;  // Nonpositive new size error
            return;
        }

        DataType* newArray = new DataType[newSize];
        int limit = (newSize > capacity) ? capacity : newSize;

        for (int i = 0; i < limit; i++) {
            newArray[i] = elements[i];
        }

        delete[] elements;
        elements = newArray;
        capacity = newSize;
    }

    // Get current capacity of the array
    inline int length() const {
        return capacity;
    }

    // Get error message
    std::string err() const {
        if (errorCode == 0) {
            return "No error.\n";
        }

        std::string errorMessage = "";
        if (errorCode & 1) {  // Nonpositive size error
            errorMessage += "Nonpositive size passed into constructor, so\n";
            errorMessage += "the capacity was set to 1 by default.\n";
        }
        if (errorCode & 2) {  // Invalid index error
            errorMessage += "Index out of range.\n";
        }
        if (errorCode & 4) {  // Nonpositive new size error
            errorMessage += "Nonpositive size passed into changeSize, so\n";
            errorMessage += "the size of the array was not changed.\n";
        }

        return errorMessage;
    }
};

#endif // ARRAY_H
