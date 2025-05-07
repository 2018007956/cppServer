#include "jsonloader.h"
#include <iostream>
using namespace std;
int main(){
    jsonloader x("config.json");
    // x.load();

    // call interface
    configloader * loader = &x;
    loader -> load();
    cout << loader -> test1() << endl;
    cout << loader -> test3() << endl;

    return 0;
}