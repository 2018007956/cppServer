#include <string>
#include <cstdio>
#include "configloader.h"
using namespace std;
class jsonloader : public configloader {
    public : 
    jsonloader(string filepath);
    ~jsonloader();
    bool load();
    int test1();
    string test3();

    private :
    string filepath;
    FILE * file;

    int value;
    string value2;
};