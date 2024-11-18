# bazel-playground
bazel project to learn bazel ecosystem

## QuickStart

### Dependencies
- [Bazel](#install-bazel)
- lcov
  ```
  sudo apt install lcov
  ```

### Define Tasks
Go to [tasks.yaml](./tasks.yaml) and add new tasks.

### Run Tasks
Use the CLI tool `/run` to run predefined tasks:
```bash
Usage: ./run <task-name>
Options:
    --list    List all available tasks.
    --help    Print this help message.

```

## Install Bazel
- Install through [Bazelisk](https://github.com/bazelbuild/bazelisk/releases).
  ```
    sudo dpkg -i bazelisk-amd64.deb
    which bazelisk
  ```
- Add `.bazeliskrc` to choose Bazel version
  ```
    BAZELISK_HOME=.bazelisk
    USE_BAZEL_VERSION=6.5.0
  ```
- Check Bazel version
  ```
  bazel version
  bazelisk version
  ```

## Set up Bazel Workspace
- Create WORKSPACE.bazel
- Import common used functions
  ```
    load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
    load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
  ```
- Import needed dependencies of Bazel project, eg. bazel python rules:
  ```
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
- Create `BUILD.bazel` to mark the repo as a bazel pkg
- Create `.bazelrc` to specify the bazel operation configurations

## Set up Bazel Python Environment
- Import python dependencies into bazel [workspace](#set-up-bazel-workspace)
- Create `requirements.txt` to specify needed python packages
- Create `requiremens_lock.txt` and add Bazel rule to update python requirements
  ```
    load("@rules_python//python:pip.bzl", "compile_pip_requirements")
    compile_pip_requirements(
        name = "py-deps",
        timeout = "moderate",
        requirements_in = "//:requirements.txt",
        requirements_txt = "//:requirements_lock.txt",
    )
  ```
- Generate contents into `requirements_lock.txt`
  ```
    ./run py-deps
  ```

