//
// Created by shalaga44 on 1/5/21.
//

#ifndef DESKTOP_APPLICATION_IO_H
#define DESKTOP_APPLICATION_IO_H

#include <iostream>

using namespace std;

template<typename ANY>
void print(ANY any) {
    cout << any;
}

template<typename ANY0, typename ANY1>
void print(ANY0 any0, ANY1 any1) {
    print(any0);
    cout << ", ";
    print(any1);
}

template<typename ANY>
void println(ANY any) {
    print(any);
    cout << endl;
}


template<typename T, size_t size>
void printlnArray(const T (&array)[size]) {
    cout << "[" << array[0] << ", ";
    for (size_t i = 1; i < size - 1; ++i)
        cout << array[i] << ", ";
    cout << array[size - 1] << "]" << endl;
}

template<typename ANY0, typename ANY1>
void println(ANY0 any0, ANY1 any1) {
    print(any0);
    cout << ", ";
    print(any1);
    cout << endl;
}

template<typename T, size_t size>
void printArray(const T (&array)[size]) {
    cout << "[" << array[0] << ", ";
    for (size_t i = 1; i < size - 1; ++i)
        cout << array[i] << ", ";
    cout << array[size - 1] << "]";
}

template<typename T0, size_t size0, typename T1, size_t size1>
void printlnArray(const T0 (&array0)[size0], const T1 (&array1)[size1]) {
    printArray(array0);
    cout << ", ";
    printlnArray(array1);

}


#endif //DESKTOP_APPLICATION_IO_H
