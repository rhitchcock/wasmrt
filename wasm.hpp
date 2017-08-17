#ifndef WASM_HPP
#define WASM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdint>

namespace wasm {
  class module {
    bool loaded = false;
  public:
    module(const std::string &file_path);
    ~module();
    bool is_loaded();
    std::uint32_t version;
  };
}

#endif

