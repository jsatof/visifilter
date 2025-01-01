#include <util/ring_buffer.h>


template<typename T>
RingBuffer::RingBuffer()
    : mbr(buffer.data(), buffer.size())
    , allocator(&mbr)
    , data(allocator.new_object<std::pmr::vector<T>>(buffer.begin(), buffer.end()))
{
}
