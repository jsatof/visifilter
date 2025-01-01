#pragma once

#include <memory_resource>

template<typename T>
class RingBuffer {
public:
    RingBuffer();

private:
    std::array<T, 2048> buffer;
    std::pmr::monotonic_buffer_resource mbr;
    std::pmr::polymorphic_allocator<std::pmr::vector<T>> allocator;
    std::pmr::vector<T> *data;

    size_t read_head, write_head;
};
