# test-cadexchanger-2
Test assigment. I added 3d graphic render and tests as a bonus.

## Structure 
`curves` - core functionality.

`tests` - catch2 tests.

`visual` - 3d visualization with raylib.

## Executables
`curves_app` - main application with ability to render 3d.

`curves_tests` - tests.

## Dependencies
This project depends on catch2 tests framework
and raylib 3d visualization library

## Building
Process of building is straightforward use cmake as usual.
This project rely on cmake auto-fetching libraries so
building process may be slow.
Build was checked with Visual Studio 2026 (insiders).

```
cd testForCadexch
mkdir out
cmake -S . -B out
cd out
make # Or use VS to build
```

## Console parameters
Use parameter `--no-visual` to disable output of 3d graphic.
