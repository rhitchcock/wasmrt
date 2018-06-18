#ifndef WASM_HPP
#define WASM_HPP

#include <string>
#include <cstdint>

namespace wasm {
  class module {
  public:
    module(const std::string &file_path);
    ~module();
    bool is_loaded();
    std::uint32_t version;
  private:
    bool loaded = false;
  };
}

#endif

