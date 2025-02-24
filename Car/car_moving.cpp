#include <iostream>
#include <string>
#include <chrono>
#include <thread>

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void drawTank(int position, int width, bool movingRight) {
    std::string tankTop = movingRight ? "  __,____" : "____,__  ";
    std::string tankMid = movingRight ? " /|_||_\\`" : "`/_||_|\\ ";
    std::string tankBottom = movingRight ? "(o)____(O)" : "(O)____(o)";

    std::cout << std::string(width, ' ') << std::endl;

    std::cout << std::string(position, ' ') << tankTop << std::endl;
    std::cout << std::string(position, ' ') << tankMid << std::endl;
    std::cout << std::string(position, ' ') << tankBottom << std::endl;

    std::cout << std::string(width, '-') << std::endl;
}

int main() {
    const int width = 800;  
    const int tankWidth = 9;  
    const int maxPosition = width - tankWidth; 
    const int delayMs = 100;  

    bool movingRight = true;  

    while (true) {
        // Движение вправо
        for (int pos = 0; pos <= maxPosition; ++pos) {
            clearConsole();
            drawTank(pos, width, movingRight);
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
        }

        movingRight = false;  

        for (int pos = maxPosition; pos >= 0; --pos) {
            clearConsole();
            drawTank(pos, width, movingRight);
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
        }

        movingRight = true; 
    }

    return 0;
}