//
//  main.cpp
//  CoroutineVSThread3
//
//  Created by Sathya Babu on 06/08/23.
//

#include <iostream>
#include <coroutine>
#include <vector>
#include <string>
#include <thread>

struct FetchDataCoroutine {
    std::string url;

    struct promise_type {
        FetchDataCoroutine get_return_object() {
            return {};
        }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };

    bool await_ready() const noexcept { return false; }

    void await_suspend(std::coroutine_handle<promise_type> coro) {
        // Simulate fetching data from API by sleeping for a short duration
        std::cout << "Fetching data from " << url << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        coro.resume();
    }

    void await_resume() {
        std::cout << "Data fetched from " << url << std::endl;
    }
};

FetchDataCoroutine fetchDataFromAPI(const std::string& url) {
    co_await FetchDataCoroutine{url};
}

struct FetchDataConcurrently {
    std::vector<std::string> urls;

    struct iterator {
        using difference_type = std::ptrdiff_t;
        using value_type = std::string;
        using pointer = const std::string*;
        using reference = const std::string&;
        using iterator_category = std::input_iterator_tag;

        FetchDataConcurrently& container;
        size_t index;

        iterator(FetchDataConcurrently& container, size_t index) : container(container), index(index) {}

        bool operator!=(const iterator& other) const {
            return index != other.index;
        }

        void operator++() {
            ++index;
        }

        reference operator*() const {
            return container.urls[index];
        }
    };

    iterator begin() {
        return iterator(*this, 0);
    }

    iterator end() {
        return iterator(*this, urls.size());
    }
};

int main() {
    FetchDataConcurrently fetcher{ {"https://api.example.com/data1", "https://api.example.com/data2"} };

    // Create a vector to store jthreads for each coroutine
   // std::vector<std::jthread> threads;

    std::vector<std::thread> threads;

    // Fetch data from each API concurrently using coroutines
    for (const auto& url : fetcher) {
        threads.emplace_back(fetchDataFromAPI, url);
    }

    // Wait for all jthreads to complete (all coroutines finish)
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
