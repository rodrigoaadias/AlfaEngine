#pragma once
#include "Event.h"

namespace Alfa
{
    class KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return mKeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        int mKeyCode {};

        KeyEvent(int keyCode)
            : mKeyCode(keyCode)
        {}
    };

    class KeyEventPressed: public KeyEvent
    {
    public:
        KeyEventPressed(int keyCode, int repeatCount)
            :KeyEvent(keyCode), mRepeatCount{repeatCount}
        {}

        inline int GetRepeatCount() { return mRepeatCount; }

        inline std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << mKeyCode << " (" << mRepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        int mRepeatCount;
    };

    class KeyEventReleased : public KeyEvent
    {
    public:
        KeyEventReleased(int keyCode)
            :KeyEvent(keyCode)
        {}

        inline std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << mKeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
}
