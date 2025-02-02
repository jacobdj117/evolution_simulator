if not exist ./build (
    mkdir build
)

cmake -G "MinGW Makefiles" -S . -B ./build
cmake --build ./build