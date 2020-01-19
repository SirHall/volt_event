#pragma once
#ifndef observer_hpp
#define observer_hpp

#include "volt/event/global_event.hpp"
#include <functional>
#include <type_traits>

namespace volt::event
{
    /**
     * @brief The observer is the class that handles subscriptions to the
     * global_event template class of the same type. Any function handed to it
     * will be fired when the global_event callback is too.
     *
     * @tparam T The type of the callback to subscribe to
     */
    template <typename T>
    class observer
    {
      private:
        std::function<void(T const &)> event;

      public:
        /**
         * @brief Forbids observer copying
         *
         * @param other The instance of the other observer to copy
         */
        observer(observer const &other) = delete; // No copying allowed
        /**
         * @brief Construct a new observer object given a function and subscribe
         * to the corresponding global_event class template
         *
         * @param action The function to invoke when the event is fired
         */
        observer(std::function<void(T const &)> action)
        {
            // Subscribe to global_event
            event = action;
            global_event<T>::subscribe(&event);
        }
        /**
         * @brief Destroy the observer object and unsubscribe from the
         * corresponding global_event class template
         *
         */
        ~observer()
        {
            // Unsubscribe from global_event
            global_event<T>::unsubscribe(&event);
        }
    };
} // namespace volt::event

#endif
