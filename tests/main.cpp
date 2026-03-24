//
// Created by chice on 3/23/2026.
//

#include<iostream>

void runVec2Tests();
void runVec3Tests();

void runTest(const char* name, void(*testFunc)()){
    std::cout << "Running" << name << "...";
    testFunc();
    std::cout << "OK\n";
}

int main(){
    runTest("Vec2 Tests", runVec2Tests);
    return 0;
}

