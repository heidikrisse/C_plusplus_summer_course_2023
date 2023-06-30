// device.h
#ifndef DEVICE_H
#define DEVICE_H

#include <map>

/* A Device struct has an ID and a status indicating whether it's a master
 * (true) or a slave (false).
 * For slave devices, registers are specified which holds a register address
 * as a key and a register value as a value. */
struct Device
{
    int id{};
    bool is_master{};
    std::map<int, int> registers{};
};

#endif
