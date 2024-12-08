### Компиляция в WebAssembly:

```note
⚠️ перед компиляцией запустить окружение описанное в /webAssembly/README.md
```

```bash
# создать calculator.c в ../src/calculator
# в директории emsdk запустить 
emcc ../src/calculator.c -s WASM=1 -s EXPORTED_FUNCTIONS='["_add"]' -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' -o ../src/calculator.js
```