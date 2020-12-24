#include <iostream>

template <class T>
class DeepPtr {
	private:
		T * ptr;

	public:
		DeepPtr(T * p = 0) : ptr(p) {}

		~DeepPtr() {
			delete ptr;
		}

		DeepPtr(const DeepPtr<T> & dp) : ptr(dp.ptr->clone()) {}

		DeepPtr<T> & operator= (const DeepPtr<T> & dp) {
			if (this != & dp) {
				delete ptr;
				DeepPtr(dp);
			}
			return * this;
		}

		T & operator-> () {
			return * ptr;
		}
};