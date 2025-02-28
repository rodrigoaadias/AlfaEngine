#pragma once
#include "Event.h"

namespace Alfa
{
    class MouseMovedEvent : public Event
    {
    private:
        float mMouseX{}, mMouseY{};

    public:
        MouseMovedEvent(float x, float y)
            : mMouseX(x), mMouseY(y)
        {}

        inline float GetX() const { return mMouseX; }
        inline float GetY() const { return mMouseY; }

        inline std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << mMouseX << ", " << mMouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };

    class MouseScrolledEvent : public Event
    {
    private:
        float mMouseOffsetX{}, mMouseOffsetY{};

    public:
        MouseMovedEvent(float x, float y)
            : mMouseOffsetX(x), mMouseOffsetY(y)
        {}

        inline float GetOffsetX() const { return mMouseOffsetX; }
        inline float GetOffsetY() const { return mMouseOffsetY; }

        inline std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << mMouseOffsetX << ", " << mMouseOffsetY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };

    class MouseButtonEvent : public Event
    {
    public:
        MouseButtonEvent(int button)
            :mButton(button)
        {}

        inline int GetButton() const { return mButton; }

        EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryInput)
    private:
        int mButton;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button)
            :MouseButtonEvent(button)
        {}

        EVENT_CLASS_TYPE(MouseButtonPreseed)

        inline std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << GetButton();
            return ss.str();
        }
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button)
            :MouseButtonEvent(button)
        {}

        EVENT_CLASS_TYPE(MouseButtonReleased)

        inline std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << GetButton();
            return ss.str();
        }
    };
}
