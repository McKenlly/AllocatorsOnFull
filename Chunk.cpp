#include "Chunk.h"

Chunk::Chunk() {
    firstAvailibleBlock_ = 0;
    blocksAvailible_ = 12;
    pData_ = nullptr;
}
void Chunk::Init(std::size_t blockSize, int blocks){
    //char *x = new char[blocks*blockSize];
    //pData_ = std::make_shared<char *>(x);

    pData_ = new char[blocks*blockSize];
    int length = static_cast<int>(malloc_usable_size(pData_));
    std::cout<< "OverMemory " <<length << std::endl;
/*
    Question 1;
    std::cout << "length" << length << "\t" << blockSize << "\t" << blocks << std::endl;    
*/  firstAvailibleBlock_ = 0;
    blocksAvailible_ =  blocks;
    int i = 0;
    char *p = pData_;
    for (; i != blocks; p+=blockSize) {
        *p = static_cast<char>(++i);
        //std::cout <<malloc_usable_size(p) << std::endl;
    }
}

void* Chunk::Allocate(std::size_t blocksSize){
    if (blocksAvailible_ == 0)
        return nullptr;
    char* pResult = pData_ +
                        (firstAvailibleBlock_ * blocksSize);
    firstAvailibleBlock_ = *pResult;

    --blocksAvailible_;
    return (void *)pResult;
}

void Chunk::Deallocate(void* p, std::size_t blockSize)
{
    assert(p >= pData_);
    char *toRelease = static_cast<char*>(p);
    //Проверка выравнивания
    assert((toRelease - pData_)% blockSize == 0);
    *toRelease = firstAvailibleBlock_;
    firstAvailibleBlock_ = static_cast<char>(toRelease - pData_)/blockSize;
    //Проверка усечения
    assert(firstAvailibleBlock_ == 
                (toRelease - pData_)/blockSize);
    ++blocksAvailible_;
}
Chunk::~Chunk() {
    delete [] pData_;
}