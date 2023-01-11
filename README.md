# C++ Solutions to LeetCode Problems

## Quickstart

Install [Bazel](https://bazel.build/) and then run the following command to build and test:

```bash
bazel test //...
```

## Runtime Environment

> Compiled with Clang 11 using the latest C++ 17 standard.
>
> Your code is compiled with level two optimization (`-O2`).  [AddressSanitizer](https://github.com/google/sanitizers/wiki/AddressSanitizer) is also enabled to help detect out-of-bounds and use-after-free bugs.
>
> Most standard library headers are already included automatically for your convenience.

## TODOs

- [x] Don't hard-code path to test cases files in test code so that unit tests can be ran under both Bazel and CMake
- [ ] Extract `INSTANTIATE_TEST_SUITE_P()` calls to a common library under `src/common`
- [ ] Add support for loading test cases from YAML files
- [ ] Try Gazelle to see if we can generate `BUILD` files automatically
- [ ] Make CMake work

## References

- [What are the environments for the programming languages?](https://support.leetcode.com/hc/en-us/articles/360011833974-What-are-the-environments-for-the-programming-languages-)
