//
//  main.cpp
//  CoroutineVSThread1
//
//  Created by Sathya Babu on 06/08/23.
//
#include <iostream>
#include <thread>
#include <vector>
#include <string>

void fetchDataFromAPI(const std::string& url) {
    // Simulate fetching data from API by sleeping for a short duration
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "\n Data fetched from  : " << url << std::endl;
}

int main() {
    std::vector<std::string> apiUrls = {
        "https://api.example.com/data1",
        "https://api.example.com/data2"
    };

    std::vector<std::thread> threads;

    // Fetch data from each API in separate threads
    for (const auto& url : apiUrls) {
        threads.emplace_back(fetchDataFromAPI, url);
    }

    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }

    // Process the fetched data here...

    return 0;
}
/*
 Data fetched from Data fetched from https://api.example.com/data1
 https://api.example.com/data2
 Program ended with exit code: 0
 */
