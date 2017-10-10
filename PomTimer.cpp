//
// Created by undo on 10.10.17.
//

#include <csignal>
#include <unistd.h>
#include "PomTimer.h"
#include "MyNotifier.h"

void startAlarm(uint8_t time)
{
    alarm(time * 60); // time is in minutes, but alarm wants seconds
}

void alarmInterruptHandler(int signal)
{
    sendNotification(
            "Pom",
            "Pom time completed. :)"
    );
    startAlarm(PomTimer::getReminderTime());

}

void PomTimer::startTimer()
{
    pomTime = time(NULL);
    signal(SIGALRM, &alarmInterruptHandler);
    startAlarm(timerTime);
}

void PomTimer::stopTimer()
{
    elapsedTime = (pomTime - time(NULL)) / 60;
    alarm(0); // Stop the Alarm Timer.

    uint8_t completedPoms = elapsedTime / pomTime;
    unrestedPoms += completedPoms;
    uint8_t restTime = completedPoms * 5;
    restTime += unrestedPoms / 3 * 10;
    unrestedPoms = unrestedPoms % 3;

    char notificationText[20];
    sprintf(notificationText,
            "Timer Stopped. %d poms completed.\n"
            "Break for %d minutes.",
            completedPoms,
            restTime
    );
}

uint8_t PomTimer::getReminderTime() {
    return reminderTime;
}

