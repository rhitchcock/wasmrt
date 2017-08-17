# wasmrt

## Overview

(In very early development)

wasmrt is a runtime built for native execution of WebAssembly modules (virtualized at first, eventually JIT). It will be composed of high-level wasm modules (for commonly-used algorithms such as sorting and GPGPU) and a base layer written in Rust or C++ (unsure yet) for interfacing with the kernel.

Later plans include adding package manager (called wasmpm maybe?).

## Planned design

```
load modules
  abstract file reading -> wasm byte stream -> read sections -> create memory structures
run
```

## Usage

Using base kernel interface (basically just a few system calls):
```
wasmrt <wasm file(s)>
```

Using default module set:
```
wasmrt -d <wasm file(s)>
``` 

Including custom module set:
```
wasmrt -i modules_folder <wasm file(s)>
```

