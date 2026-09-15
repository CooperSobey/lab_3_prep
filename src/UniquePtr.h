#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H
#include <algorithm>

// Your implementation here
template <typename T>
class UniquePtr {
    public:

    //ctor/dtor
    UniquePtr(T *P = nullptr) : mPtr{P} {}
    ~UniquePtr() {
        if (mPtr) {
            delete mPtr;
        }
    }

    //Copy Constructor
    UniquePtr (const UniquePtr& other) = delete;
    //: mPtr {clone (other.mPtr)} {}

    //Move Constructor
    UniquePtr (UniquePtr&& other) : mPtr (other.mPtr) {
        other.mPtr = nullptr;
    }

    //Copy Assignment
     UniquePtr& operator=(const UniquePtr& other) = delete;
    //{
    //     UniquePtr otherClone(other);
    //
    //     std::swap (mPtr, otherClone.mPtr);
    //     return *this;
    // }

    //Move Assignment
    UniquePtr& operator=(UniquePtr&& other) {
        std::swap (mPtr, other.mPtr);
        return *this;
    }

    //Dereference op
    T& operator*() const { return *mPtr;}

    template<typename U>
    UniquePtr(UniquePtr<U>&& other) : mPtr(other.release()) {}


    //operator->
    T* operator->() const {return mPtr;}

    //operator==
    bool operator==(const UniquePtr& other) const {
        return mPtr == other.mPtr;
    }

    //T* release()
    T* release() {
        T* tmp = mPtr;
        mPtr = nullptr;
        return tmp;
    }

    //T* get()
    T* get() const {return mPtr;}

    //void reset(T* newPtr = nullptr)
    void reset(T* newPtr = nullptr) {
        T* oldPtr = mPtr;
        mPtr = newPtr;
        if (oldPtr) {
            delete oldPtr;
        }

    }

    //void swap(UniquePtr<t>& other)
    void swap(UniquePtr<T>& other) {
        std::swap (mPtr, other.mPtr);
    }

    // operator bool()
    operator bool() const {return mPtr != nullptr;}

    private:
        T* mPtr;
};
#endif
