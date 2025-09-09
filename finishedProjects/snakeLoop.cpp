#include <iostream>
#include <string>
#include <thread>
#include <chrono> 

int main() {
    const std::string snake = "===>";  // the snake body
    const int width = 10;              // how far sideways it goes

    for (int pos = 0; pos < width; ++pos) {
        // Move cursor to beginning of line and clear it
        std::cout << "\r" << std::string(width + snake.size(), ' ') << "\r";

        // Build spaces + snake
        std::string spaces(pos, ' ');
        std::cout << spaces << snake << std::flush;

        // Delay so you can see movement
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }

    std::cout << std::endl; // move to next line cleanly at the end
    return 0;
}
