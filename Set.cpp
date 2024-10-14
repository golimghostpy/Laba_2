#include "Set.h"

int Set::contains(const string& value){
    return data.find_value(value);
}

void Set::add(const string& value){
    if (contains(value) == -1){
        data.push_back(value);
        return;
    }
}

void Set::remove(const string& value){
    data.delete_value(value);
}
