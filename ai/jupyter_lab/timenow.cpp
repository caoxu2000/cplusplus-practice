#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

int main() {
    // Get current time point
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    // Convert to time_t
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    // Convert to tm struct
    std::tm* now_tm = std::localtime(&now_c);

    // Create a stringstream to format the output
    std::stringstream ss;

    // Format the string using put_time
    ss << std::put_time(now_tm, "%Y-%m-%d %H:%M:%S");

    // Get the string from the stringstream
    std::string timeString = ss.str();

    std::cout << timeString << std::endl;

    return 0;
}