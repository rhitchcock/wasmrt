#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdint>

#include "wasm.hpp"

const std::uint32_t magic_number = 0x6D736100;

namespace wasm {
  module::module(const wasm::reader &reader) {
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

  reader::reader(const std::string &file_path) {
    std::ifstream file(file_path, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
      return;
    }
    std::streampos size = file.tellg();
    this->buffer = new char[size];
    this->index = 0;
    this->size = size;
    file.seekg(0, std::ios::beg);
    file.read(buffer, size);
    file.close(); 
  }

  reader::~reader() {
    delete[] this->buffer;
  }

  std::uint32_t reader::uint32_t() {
    if (this->index + 4 < this->size) {
      this->index += 4;
      return *reinterpret_cast<std::uint32_t *>(this->buffer[this->index - 4]);
    }
    return 0;
  }
}

