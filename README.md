# Tetris

Implementation of a simplified version of Tetris using **C++**, **CMake**, **Raylib** and an object oriented programming based style.

In work.

---

## Features

- Modern CMake-based build system
- raylib fetched automatically via CMake (`FetchContent`)

---

## Structure

<!-- STRUCTURE:START -->
```text
.
├── Assets
│   ├── Audio
│   │   └── .gitkeep
│   └── Images
│       └── .gitkeep
├── Core
│   ├── Inc
│   │   ├── Colors.h
│   │   ├── Config.h
│   │   ├── Game.h
│   │   ├── GameState.h
│   │   └── Shape.h
│   └── Src
│       ├── Config.cpp
│       ├── Game.cpp
│       ├── main.cpp
│       └── Shape.cpp
├── Scripts
│   └── update-structure.ps1
├── .gitignore
├── CMakeLists.txt
├── LICENSE
└── README.md
```
<!-- STRUCTURE:END -->

This section is generated automatically and reflects the current folder layout of the repository. You can update it by running `update-structure.ps1` in a PowerShell terminal:

```bash
.\Scripts\update-structure.ps1
```

---

## Dependencies

- **CMake** ≥ 3.16  
- **C++17 compatible compiler**
- **raylib 5.0** (downloaded automatically)

No manual installation of raylib is required.

---

## Building

### Using VS Code (recommended)

1. Open the repository root folder in VS Code
2. Install the **CMake Tools** extension
3. Select a compiler kit when prompted
4. Configure and build the project using the CMake UI

The project is designed to use out-of-source builds, keeping the repository clean.

---

### Command Line

```bash
cmake -S . -B build
cmake --build build
```

After building, the executable will be located in the build directory.
The Assets/ folder is copied next to the executable so relative asset paths work correctly.

---

## License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.
You are free to use, modify, and redistribute it for personal or commercial projects.

---

## Notes

Barely set up project repository.
