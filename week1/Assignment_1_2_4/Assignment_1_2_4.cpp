#include <iostream>

struct Time
{
    int hours{};
    int minutes{};
    int seconds{};
};

Time getTimeInput()
{
    std::cout << "Enter the start time (hours minutes seconds): ";
    int hours{}, minutes{}, seconds{};
    std::cin >> hours >> minutes >> seconds;
    return {hours, minutes, seconds};
}

Time calculateTimeDifference(const Time &start, const Time &end)
{
    int totalStartSeconds{start.hours * 3600 + start.minutes * 60 + start.seconds};
    int totalEndSeconds{end.hours * 3600 + end.minutes * 60 + end.seconds};

    int diffSeconds{totalEndSeconds - totalStartSeconds};
    if (diffSeconds < 0)
    {
        diffSeconds += 24 * 3600;
    }

    return {
        diffSeconds / 3600,
        (diffSeconds % 3600) / 60,
        diffSeconds % 60};
}

void displayTime(const Time &time)
{
    std::cout << (time.hours < 10 ? "0" : "") << time.hours << ":"
              << (time.minutes < 10 ? "0" : "") << time.minutes << ":"
              << (time.seconds < 10 ? "0" : "") << time.seconds << "\n";
}

int main()
{
    std::cout << "Time Difference Calculator\n";

    Time startTime{getTimeInput()};
    Time endTime{getTimeInput()};

    std::cout << "Time difference: ";
    displayTime(calculateTimeDifference(startTime, endTime));

    return 0;
}
