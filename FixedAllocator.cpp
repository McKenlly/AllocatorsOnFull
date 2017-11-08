#include "FixedAllocator.h"

FixedAllocator::FixedAllocator() {
    blockSize_ = 45;
    numBlocks_ = 2;
    allocChunk_ = nullptr;
}
void* FixedAllocator::Allocate(std::size_t newSizeBack)
{
    //chunks - вектор
    if (allocChunk_ == nullptr || allocChunk_->blocksAvailible_ == 0) {
        Chuncks::iterator i;
        // Ищем свободные блоки.
        for (i = chunks_.begin(); i != chunks_.end(); i++)
        {
            if (i->blocksAvailible_ > 0 && blockSize_> newSizeBack) {
                //объект найден
                //разыменовывем указатель
                //и передаем на него адрес
                allocChunk_ = &*i;
                break;
            }
        }
        if (i == chunks_.end()) {
            std::cout << "NEW SHARED" << std::endl;
            chunks_.reserve(chunks_.size() + 1);
            Chunk newChunk;// = new Chunk;
            newChunk.Init(blockSize_, numBlocks_);
            chunks_.push_back(newChunk);
            allocChunk_ = &chunks_.back();
            deallocChunk_ = &chunks_.back();
            //delete newChunk;
        }

    }
    assert(allocChunk_ != 0);
    printf("BlockSize %d\n", blockSize_);
    assert(allocChunk_->blocksAvailible_ > 0);;
    return allocChunk_->Allocate(blockSize_);
}
void FixedAllocator::Dealloc(void *pFree) {

}
FixedAllocator::~FixedAllocator() {

    /*for (auto i:chunks_) {
        for (int j = 0; j < 10; j++) {
            std::cout << (*i.pData_)[j] << std::endl;
        }
    }*/
}
/* Минусы:
    - Задрeжка по времени, обусловленная поиском и добавлением нового блока.
    - Все тот же фиксированный размер
    */
