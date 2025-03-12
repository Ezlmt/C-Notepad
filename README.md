# C++-Notepad
This is just a practice project for c++!

## Install

### ncurses

```bash
# Ubuntu / WSL
sudo apt install libncurses-dev

# macOS (Homebrew)
brew install ncurses
```

## Build & Run

### Clone

```bash
git clone https://github.com/Ezlmt/C-Notepad.git
cd cpp-notepad
```

### Compile

```bash
mkdir build
cd build
cmake ..
make
```

```bash
./notepad test.txt
```

## How to use

|Key|Action|
|---|---|
|`ESC`|exit|
|`Enter`|new line|
|`Backspace`|delete char|
|normal key input|input txt|
