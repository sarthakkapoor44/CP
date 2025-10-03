#pragma once

template<typename T> class Vector{
    public:
        Vector(){
            ReAlloc(2);
        }
        void PushBack(const T& newElement){
            if(currentSize < capacity){
                block[currentSize] = newElement;
                currentSize++;
            } else {
                ReAlloc(currentSize + currentSize/2);
                block[currentSize] = newElement;
                currentSize++;
            }
        }

        T& operator[](size_t index){
            if(index>= currentSize){
                return -1;
            }
            return block[index];
        }

        size_t Size() {
            return currentSize;
        }
    private:
        void ReAlloc(size_t newCapacity) {
            if (newCapacity < currentSize) currentSize = newCapacity;
            T* newBlock = new T[newCapacity];
            for(size_t i  = 0 ; i < currentSize ; i ++ ){
                newBlock[i] = head[i];
            }
            delete[] block;
            block = newBlock;
            capacity = newCapacity;
        }
        T* block = nullptr;
        size_t currentSize = 0;
        size_t capacity = 0;
};