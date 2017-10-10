//
// Created by undo on 10.10.17.
//

#include <csignal>
#include <unistd.h>
#include "PomTimer.h"
#include "MyNotifier.h"

void handler (int signal)
{
    char title [100];
    char text [100];

    sprintf(title, "Alarm Notification");
    sprintf(text, "%d seconds have passed.", 25);
    
    sendNotification(title, text);
}

void PomTimer::startTimer() {
    signal(SIGALRM, &handler);
    alarm(25);
}
