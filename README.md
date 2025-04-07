# cpp20_modules_example

* Based on:
  * <https://learn.microsoft.com/en-us/cpp/cpp/tutorial-named-modules-cpp?view=msvc-170>; and
  * <https://www.kitware.com/import-cmake-the-experiment-is-over/>
* It seems like partitions are not properly supported yet (TBC)

## macos

* Version: 15.4

```bash
cmake -S . -B build -DCMAKE_CXX_COMPILER=/opt/homebrew/Cellar/llvm/20.1.1/bin/clang++ -DCMAKE_INSTALL_PREFIX=out -DCMAKE_BUILD_TYPE=Debug -G "Ninja"
cmake --build build --config Debug --target install -j
./out/ModulesTutorial/ModulesTutorial
```
