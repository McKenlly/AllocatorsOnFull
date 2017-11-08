#ifndef CHUNK_ALLOCATOR_H
#define CHUNK_ALLOCATOR_H

#include <cstdio>
#include <iostream>
#include <limits.h>
#include <memory>
#include <malloc.h>
#include <assert.h>

class Chunk {
public:
    Chunk();
    //std::shared_ptr<char *> pData_;
    //std::shared_ptr<char> pData_;
    char *pData_;
    //SharedPointer<char *> pData_;
    char firstAvailibleBlock_;
    int blocksAvailible_;
    void Init(std::size_t blockSize, int blocks);
    void* Allocate(std::size_t blockSize);
    void Deallocate(void *p, std::size_t blockSize);
    ~Chunk();
};


#endif