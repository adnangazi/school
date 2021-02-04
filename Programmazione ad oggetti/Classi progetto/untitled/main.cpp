#include <iostream>
using namespace std;

class FooError : public runtime_error {
public:
    FooError() : runtime_error("Foo error!") {}
};

int main() {
    cerr << FooError().what() << endl;
    for (int i = 0; i < 10000; i++) {
        int a = i;
        a++;
        for (int i = 0; i < 10000; i++) {
            int a = i;
            a++;
        }
    }
    cout << "sono qua!" << endl;
}
