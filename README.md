# bazel-playground

bazel project to learn bazel ecosystem

## QuickStart

### Dependencies

- [Bazel](#install-bazel)
- lcov
  
  ```bash
  sudo apt install lcov
  ```

- python 3.7+
- cmake 3.16.0+

### Define Tasks

Go to [`tasks.yaml`](./tasks.yaml) and add new tasks.

### Run Tasks

Use the CLI tool [`run`](run) to run predefined tasks:

```bash
Usage: ./run <task-name>
Options:
    --list    List all available tasks.
    --help    Print this help message.

```

## Install Bazel

- Install through [Bazelisk](https://github.com/bazelbuild/bazelisk/releases).
  
  ```bash
    wget https://github.com/bazelbuild/bazelisk/releases/download/v1.23.0/bazelisk-amd64.deb
    sudo dpkg -i bazelisk-amd64.deb
    which bazelisk
  ```

- Add [`.bazeliskrc`](.bazeliskrc) to choose Bazel version

  ```bash
    BAZELISK_HOME=.bazelisk
    USE_BAZEL_VERSION=6.5.0
  ```

- Check Bazel version
  
  ```bash
  bazel version
  bazelisk version
  ```

## Set up Bazel Workspace

- Create WORKSPACE.bazel
- Import common used functions
  
  ```bash
    load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
    load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
  ```

- Import needed dependencies of Bazel project, eg. bazel python rules:
  
  ```bash
    http_archive(
        name = "rules_python",
        sha256 = "9d04041ac92a0985e344235f5d946f71ac543f1b1565f2cdbc9a2aaee8adf55b",
        strip_prefix = "rules_python-0.26.0",
        url = "https://github.com/bazelbuild/rules_python/releases/download/0.26.0/rules_python-0.26.0.tar.gz",
    )

    load("@rules_python//python:repositories.bzl", "py_repositories", "python_register_toolchains")

    py_repositories()

    python_register_toolchains(
        name = "python_3_10",
        python_version = "3.10",
        register_coverage_tool = True,
    )

    load("@python_3_10//:defs.bzl", _python_interpreter = "interpreter")
    load("@rules_python//python:pip.bzl", "pip_parse")

    pip_parse(
        name = "python_deps",
        python_interpreter_target = _python_interpreter,
        requirements_lock = "//:requirements_lock.txt",
    )

    load("@python_deps//:requirements.bzl", "install_deps")

    install_deps()
  ```

- Create [`BUILD.bazel`](BUILD.bazel) to mark the repo as a bazel pkg
- Create [`.bazelrc`](.bazelrc) to specify the bazel operation configurations

## Set up Bazel Python Environment

- Import python dependencies into bazel [`WORKSPACE`](#set-up-bazel-workspace)
- Create [`requirements.txt`](requirements.txt) to specify needed python packages
  
  Unlike C/C++, all Python dependencies cannot be import into WORKSPACE directly, instead, they need to be imported through `requirements.txt`

- Create an empty `requiremens_lock.txt` and add Bazel rule to update python requirements

  ```bash
    load("@rules_python//python:pip.bzl", "compile_pip_requirements")
    compile_pip_requirements(
        name = "py-deps",
        timeout = "moderate",
        requirements_in = "//:requirements.txt",
        requirements_txt = "//:requirements_lock.txt",
    )
  ```

- Generate contents into [`requiremens_lock.txt`](requirements_lock.txt)
  
  ```bash
    ./run py-deps
  ```

## Import External Packages

Take cyclonedds for example:

- Add external package into [`WORKSPACE`](WORKSPACE.bazel):
  
  ```bazel
  http_archive(
    name = "cyclonedds",
    sha256 = "495ace40b51025d1465bd10a8c6c0f36a1a3a03a97f8e6d4582a06086644c3b8",
    strip_prefix = "cyclonedds-0.11.0",
    build_file = "//external_bazel_templates:BUILD.bazel.cyclonedds",
    url = "https://github.com/allenwang-git/cyclonedds/archive/refs/tags/0.11.0.tar.gz",
  )
  ```

- Add customized [`BUILD`](external_bazel_templates/BUILD.bazel.cyclonedds) file for external package

- Refer to it when define bazel target:

  ```bazel
  cc_library(
    name = "c_idl",
    srcs = [
        "idl/HelloWorldData.h",
        "idl/HelloWorldData.c",
    ],
    deps = ["@cyclonedds"],
    visibility = ["//visibility:public"],
  )
  ```

## Run Test and Coverage in Bazel

For cc codes, defined `cc_test` targets, while for python codes, define `py_test` targets.

To run all tests in this repo, use `bazelisk test //... <options>`.

NOTES: If use `py_test` to do integration test for cc codes, the tests cannot be used to calculate coverage for cc codes, unless use native `pytest` command. In other words, `cc_binary` targets cannot be test directly.

To calculate unit test coverage, use `bazelisk coverage //python/... <options>` or `bazelisk coverage //cc/... <options>`

To generate coverage report, use `genhtml` command.

