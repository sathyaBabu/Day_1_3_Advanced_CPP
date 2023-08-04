//
//  main.cpp
//  2_21_ObserverLambda..
//
//  Created by Sathya Babu on 02/08/23.
//

// observer rValue

/*
 In this implementation, we define a LiveData class template that holds the value of type T and a vector of observer functions.
 The Copyable concept is used to ensure that the T type is copy-constructible.

 The LiveData class provides two constructors to set the initial value of the data holder.
 It also provides two overloads of the setValue function to set the value of the data holder, and notify the observers if the new value is different
 from the current value.

 The observe function takes an observer function as a parameter and adds it to the vector of observers.
 The observer function is called immediately with the current value of the data holder.
 */
#include <functional>
#include <vector>


template <typename T>
class LiveData {
public:
    LiveData() = default;

    LiveData(const T& value)
        : mValue(value)
    {
    }

    LiveData(T&& value)
        : mValue( std::move(value) ) // std::move just an obsession! works without
    {
    }

    LiveData& operator = (const T& value)
    {
        setValue(value);
        return *this;
    }

    LiveData& operator = (T&& value)
    {
        setValue( std::move(value) ); // std::move just an obsession! works without
        return *this;
    }

    template <typename Observer>
    void observe(Observer&& observer)
    {
        mObservers.emplace_back( std::forward< Observer >( observer) );
        observer( mValue );
    }

    void setValue(const T& value)
    {
        if (value != mValue) {
            mValue = value;
            
            notifyObservers();
        }
    }

    void setValue(T&& value)
    {
        if (value != mValue) {
            mValue = std::move(value); // std::move just an obsession! works without
            notifyObservers();
        }
    }

private:
    void notifyObservers()
    {
        for (auto& observer : mObservers) {
            observer(mValue);
        }
    }

private:
    T mValue;
    std::vector< std::function<void(const T&) >> mObservers; // light weight compared to an object
};
#include <iostream>

int main()
{
    LiveData<int> data{42}; // data : T type is copy-constructible.

    data.observe( [](const auto& value) {
        std::cout << "Observer 1: " << value << std::endl;
    });

    data.observe( [](const auto& value) {
        std::cout << "Observer 2: " << value << std::endl;
    });

    data.setValue(43);
    data.setValue(44);

    return 0;
}
/*
 Observer 1: 43
 Observer 2: 43
 Observer 1: 44
 Observer 2: 44
 Program ended with exit code: 0
 */
