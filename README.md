# Symbolic Execution

## Build

After `git clone`, please initialize all submodules:
```
git submodule update --init --recursive
```

```
mkdir build
cd build
cmake ..
make
```

## Unit-tests

```
tests/tests
```

## Shortcuts
- Memory management. Right now it is the simplest, using `std::shared_ptr`. There are more optimal options.
- RTTI, using `dynamic_cast`. We can instead use approach from LLVM.
- ANLTR-generated parser code is inserted into the repository, it should be generated during build stage.
