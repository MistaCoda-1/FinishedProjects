#include<iostream>
#include<string>
using namespace std;

class metalPipes {
    public:
        virtual void dropPipe() {
            cout << "You dropped the pipe and made sound!\n";
        }
};
class thinPipe : public metalPipes {
    public:
        void dropPipe() override {
            cout << "BING!\n";
        }
};

int main() {
    /*
    metalPipes* normal;
    thinPipe thin;
    normal = &thin;
    normal->dropPipe();
    */

    thinPipe thin;
    thin.dropPipe();
    
    return 0;
}