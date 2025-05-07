#include <cstdio>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "jsonloader.h"
#include "json/json.h"
using namespace std;
jsonloader :: jsonloader(string filepath) {
    FILE * file = fopen(filepath.c_str(), "r");
    if(file==NULL){ throw runtime_error(""); }

    this->filepath = filepath;
    this->file = file;
}
jsonloader :: ~jsonloader() {
    fclose(this->file);
}
bool jsonloader :: load() {
    ifstream ifs(this->filepath);
    if(!ifs.is_open()) return 0;

    Json::Value root;
    Json::CharReaderBuilder builder;
    string errs;

    if (!Json::parseFromStream(builder, ifs, &root, &errs)) return 0;

    this->value = root["test1"].asInt();
    this->value2 = root["test2"]["test3"].asString();

    return true;
}
int jsonloader :: test1() {
    return this->value;
}
string jsonloader :: test3() {
    return this->value2;
}