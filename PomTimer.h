//
// Created by ayal on 6.10.17.
//

#ifndef NOTIFICATIONTEST_POMTIMER_H
#define NOTIFICATIONTEST_POMTIMER_H

//#include <cstdint>
#include <ctime>
#include <cstdint>

class PomTimer {
private:
    static const uint8_t reminderTime = 1;
    uint8_t timerTime = 25;
    uint8_t shortRestTime = 5;
    uint8_t longRestTime = 15;
    uint32_t poms = 0;
    uint8_t unrestedPoms = 0;
    time_t pomTime = 0;
    double elapsedTime = 0;
public:
    static uint8_t getReminderTime();
    void startTimer();
    void stopTimer();
    void setPomTime(uint8_t min)
    {
        timerTime = min;
    }
    void setPomShortRestTime(uint8_t min)
    {
        shortRestTime = min;
    }
    void setPomLongRestTime(uint8_t min)
    {
        longRestTime = min;
    }
    uint32_t getPoms()
    {
        return poms;
    }
};


#endif //NOTIFICATIONTEST_POMTIMER_H
