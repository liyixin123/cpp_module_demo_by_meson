# CPP_MODULE_DEMO_BYMESON

## 项目介绍

使用 Meson 在 MSVC 下编译 C++ 项目。

* 使用了 `c++23` 的一些特性。
* 使用了 `c++` 的 `std::format` 进行格式化输出。
* 使用第三方库 `fmt::print` 和 `std::print` 进行格式化输出。

## 构建运行

> 以Windows环境为例

### 前提条件

1. 下载本项目。
1. 安装 `MSVC` 编译工具，建议版本 `VS2022`。
1. 配置好 `Meson` 环境。

### 构建步骤

1. 打开 `Developer Command(或Powershell) Prompt for VS 2022`。
1. 进入根目录下，创建 `subprojects` 子目录。
1. 将 `fmt` 库作为一个子工程引入，`meson wrap install fmt`。
1. 进入项目根目录，配置项目：`meson setup builddir`。(此时可以同时生成vs的工程文件，`meson setup builddir --backend vs2022 --wipe`)
1. 上面两步可能因为网络不好而失败，可以多试两次。
1. 编译项目：`meson compile -C builddir`。
1. 运行软件: `.\builddir\main`。
