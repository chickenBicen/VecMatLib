//
// Created by chice on 3/23/2026.
//

#include <iostream>

void runVec2Tests();
void runVec3Tests();
void runMat2Tests();
void runTransform2Tests();
void runMat3Tests();
void runTransform3Tests();

int main() {
  runVec2Tests();
  runVec3Tests();
  runMat2Tests();
  runTransform2Tests();
  runMat3Tests();
  runTransform3Tests();

  std::cout << "All tests passed!! HOOOOORRRRAAAAYYYYY\n\n";

  return 0;
}
