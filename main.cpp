#include "ip_pool.h"
#include <iostream>
#include <algorithm>

int
main()
{
    ip_pool pool(std::cin);

    pool.sort();

    for (const auto& element : pool)
    {
        std::cout << element << std::endl;
    }

    auto filteredPool = pool.getFilteredIP([]( const ip_pool::PoolRecordType& record) {return (record[0] == 1) ? true : false; });

    for (const auto& element : filteredPool)
    {
        std::cout << element << std::endl;
    }

    filteredPool = pool.getFilteredIP([](const ip_pool::PoolRecordType& record) {return  (record[0] == 46 && record[1] == 70) ? true : false; });

    for (const auto& element : filteredPool)
    {
        std::cout << element << std::endl;
    }

    filteredPool = pool.getFilteredIP([](const ip_pool::PoolRecordType& record) {return  std::any_of(record.begin(), record.end(), []( const auto v ){ return v == 46; }); });

    for (const auto& element : filteredPool)
    {
        std::cout << element << std::endl;
    }

    return 0;
}