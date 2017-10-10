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
    uint8_t timerTime = 25;
    uint8_t reminderTime = 1;
    uint8_t shortRestTime = 5;
    uint8_t longRestTime = 15;
    uint32_t poms = 0;
    uint64_t elapsedTime;
public:
    //PomTimer();
    void startTimer();
    void stopTimer();
    void setPomTime(uint8_t min)
    {
        timerTime = min;
    }
    void setPomOverflowReminderTime(uint8_t min)
    {
        reminderTime = min;
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
