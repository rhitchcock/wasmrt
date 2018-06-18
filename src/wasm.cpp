#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdint>

#include "wasm.hpp"

const std::uint32_t magic_number = 0x6D736100;

namespace wasm {
  module::module(const std::string &file_path) {
    std::ifstream file(file_path, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
      return;
    }
    std::streampos size = file.tellg();
    char *buffer = new char[size];
    file.seekg(0, std::ios::beg);
    file.read(buffer, size);
    file.close();
    // Ensure file begins with magic number '\0asm'.
    if (*reinterpret_cast<std::uint32_t *>(buffer) != magic_number) {
      return;
    }
    this->version = *(std::uint32_t *)(buffer + 4);
    //...
    delete[] buffer;
    this->loaded = true;
  }
  bool module::is_loaded() {
    return this->loaded;
  }
  module::~module() {
  }
}

