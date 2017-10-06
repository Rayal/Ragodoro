//
// Created by undo on 6.10.17.
//

#include <libnotify/notify.h>
#include "MyNotifier.h"
#include "common.h"

bool sendNotification(std::string title, std::string text, int timeout)
{
    if (!notify_is_initted())
    {
        notify_init(appName);
    }

    NotifyNotification* notification = notify_notification_new(title.c_str(), text.c_str(), 0);
    notify_notification_set_timeout(notification, timeout);
    notify_notification_show(notification, 0);
}