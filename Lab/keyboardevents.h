#ifndef KEYBOARDEVENTS_H
#define KEYBOARDEVENTS_H

#include <QObject>
#include <QDebug>

class KeyboardEvents: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString getFirstKeyEvent READ getFirstKeyEvent)
    Q_PROPERTY(QString getSecondKeyEvent READ getSecondKeyEvent)
    Q_PROPERTY(QString getThirdKeyEvent READ getThirdKeyEvent)
    Q_PROPERTY(QString getFourthKeyDEvent READ getFourthKeyDEvent)
    Q_PROPERTY(QString getFourthKeyPageUpEvent READ getFourthKeyPageUpEvent)
public:
    KeyboardEvents();
    QString getFirstKeyEvent();

    QString getSecondKeyEvent();

    QString getThirdKeyEvent();

    QString getFourthKeyDEvent();
    QString getFourthKeyPageUpEvent();
private:
    bool getCapsStatus();
    bool getNumLockStatus();
    bool getScrollLockStatus();

};

#endif // KEYBOARDEVENTS_H
