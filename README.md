# C++ Solutions to LeetCode Problems

## Quickstart

Install [Bazel](https://bazel.build/) and then run the following command to build and test:

```bash
bazel test //...
```

To enable autocomplete for IDEs, run the following command:

```bash
bazel run @hedron_compile_commands//:refresh_all
```

Refer to [Hedron’s Compile Commands Extractor for Bazel](https://github.com/hedronvision/bazel-compile-commands-extractor
) for more information.

## Runtime Environment

According to the [documentation](https://support.leetcode.com/hc/en-us/articles/360011833974-What-are-the-environments-for-the-programming-languages-), LeetCode compiles the submitted C++ code with the C++17 standard.

> Compiled with Clang 11 using the latest C++ 17 standard.
>
> Your code is compiled with level two optimization (`-O2`).  [AddressSanitizer](https://github.com/google/sanitizers/wiki/AddressSanitizer) is also enabled to help detect out-of-bounds and use-after-free bugs.
>
> Most standard library headers are already included automatically for your convenience.

## Unit Testing

This repo uses parameterized tests to load test cases from external YAML files.  The reason of externalizing test data is to make it easy for projects written in different languages to share the test data.

## TODOs

- [x] Don't hard-code path to test cases files in test code so that we can run unit tests with either Bazel or CMake
- [ ] Extract `INSTANTIATE_TEST_SUITE_P()` calls to a common library under `src/common`
- [x] Add support for loading test cases from YAML files
- [ ] Share test fixtures among different solutions to the same problem
- [ ] Share test fixtures among different problems
- [ ] Try Gazelle to see if we can generate `BUILD` files automatically
- [ ] Improve CI performance by using
  - [x] [Bazel Remoe Caching](https://bazel.build/remote/caching) and
  - [ ] [Bazel Remote Execution](https://bazel.build/remote/rbe)
- [ ] Make repo work with CMake

## Related Projects

- [leetcode-java](https://github.com/luangong/leetcode-java)
- [leetcode-python](https://github.com/luangong/leetcode-python)
- [leetcode-ts](https://github.com/luangong/leetcode-ts)
