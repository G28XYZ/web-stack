### Компиляция в WebAssembly:

```note
⚠️ перед компиляцией запустить окружение описанное в /webAssembly/README.md
```

```bash
# создать factorial.c в ../src/factorial
# в директории emsdk запустить 
emcc ../src/factorial/factorial.c -s WASM=1 -s EXPORTED_FUNCTIONS='["_factorial"]' -o ../src/factorial/factorial.js  
```