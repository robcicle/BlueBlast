# BlueBlast

**Level 4 Project**

BlueBlast, a 2D game developed with the SFML library, served as a foundational project during my first year at university. This basic game revolves around maneuvering through a grid, navigating to avoid wires while collecting discs. The core objective is to achieve the lowest time possible, with the option to save and view scores.

## Features

- 2D graphics rendering using SFML
- Custom game logic and mechanics

## Building the Project

### Prerequisites

- CMake 3.28 or higher
- A C++ compiler (e.g., GCC, Clang, MSVC)
- SFML library (fetched in CMake solution generation)

### Building with CMake

1. Clone the repository and initialize submodules:

    ```sh
    git clone https://github.com/robcicle/BlueBlast.git
    cd BlueBlast
    ```

2. Create a build directory and navigate to it:

    ```sh
    mkdir build
    cd build
    ```

3. Run CMake to configure the project:

    ```sh
    cmake ..
    ```

4. Build the project:

    ```sh
    cmake --build .
    ```

5. Run the executable:

    ```sh
    ./bin/Debug/BlueBlast.exe
    ```