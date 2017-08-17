#include "wasm.hpp"

namespace wasm {
  module::module (const std::string &file_path) {
    std::ifstream file(file_path, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
      return;
    }
    std::streampos size = file.tellg();
    char *buffer = new char[size];
    file.seekg(0, std::ios::beg);
    file.read(buffer, size);
    file.close();
    if (*(std::uint32_t *)buffer != 0x6D736100) {
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

