#include "RelayController.h"

int RelayController::enableRelayByIndex(unsigned int index)
{
        lastRelayMask |= (0x01 << index);
        updateRelaysFromMask();
        return 0;
}

int RelayController::disableRelayByIndex(unsigned int index)
{
        lastRelayMask &= ~(0x01 << index);
        updateRelaysFromMask();
        return 0;
}

void RelayController::updateRelaysFromMask()
{
        char buffer[] = {0x10, lastRelayMask};
        i2c.sendFile(buffer, 2);
}

bool RelayController::getLastKnownRelayStateByIndex(unsigned int index)
{
        return (bool)(lastRelayMask & (1 << (index % 4)));
}

RelayController::RelayController()
{
        lastRelayMask = 0;
        i2c.openFile(0x58);
}

RelayController::~RelayController()
{
        i2c.closeFile();
}