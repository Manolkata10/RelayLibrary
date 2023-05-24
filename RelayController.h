#include "../I2CLib/i2c.h"

class RelayController
{
        private:
                I2C i2c;
                char lastRelayMask;

                void updateRelaysFromMask();

        public:
                int enableRelayByIndex(unsigned int index);
                int disableRelayByIndex(unsigned int index);
                bool getLastKnownRelayStateByIndex(unsigned int index);

                RelayController();
                ~RelayController();
};
