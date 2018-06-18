#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>

#include "wasm.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " file" << std::endl;
    return EXIT_FAILURE;
  }
  wasm::module module(argv[1]);
  if (!module.is_loaded()) {
    std::cout << "Not a wasm file." << std::endl;
    return EXIT_FAILURE;
  }
  std::cout << "WebAssembly version " << module.version << std::endl;
  //module.run();
  return EXIT_SUCCESS;
}

