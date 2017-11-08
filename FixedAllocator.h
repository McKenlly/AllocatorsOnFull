#ifndef FIXED_ALLOCATOR_H
#define FIXED_ALLOCATOR_H


#include <cstdio>
#include <vector>
#include <iostream>
#include <limits.h>
#include "Chunk.h"
/*
Распределение памяти для небольших объектов.
Предназначен для распределени памяти фиксированного размера
причем этот размер необязательно должен соответствовать
размеру порции.
Чтобы ускорить работу, класс не перебирает элементы вектора
в поисках подходящего участка памяти при каждом запросе.
В оъекте хранится указатель на последний объект класса Chunk,
который пользовался распределением памяти.
При поступлении нового запроса функция FixedAlllocate сначала проверяет
достаточно ли памяти для размещения. Если этот обект удовлетворяет требованиям запроса,
то мы берем его. Еси нет, то выполняется линейный поиск.
Возможно в вектор записывается новый объект при нехватке.
Такой подход повышает вероятность, что в следующий раз распределение 
памяти будет выполнено быстро. 
*/
#include <assert.h>
#include <cstdio>
#include <memory>
#include <cstdlib>

class FixedAllocator {
public:
    FixedAllocator();
    void* Allocate(std::size_t);
    void Dealloc(void *);
    ~FixedAllocator();
private:
    std::size_t blockSize_; 
    int numBlocks_;
    typedef std::vector<Chunk> Chuncks;
    Chuncks chunks_; // Вектор пуллов(страниц)
    Chunk* allocChunk_; //Pointer on start pool
    Chunk* deallocChunk_; //Pointer in finish pool
};

#endif