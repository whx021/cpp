project(thread_example)

add_executable(thread_example
    8_hardware_concurrency.cpp
)

target_link_libraries(thread_example
    pthread
)