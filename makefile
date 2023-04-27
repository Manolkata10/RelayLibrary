all: remote

OUTPUT_NAME=relay
COMPILER=g++
CONFIG=
BUILD=$(COMPILER) $^ $(CONFIG) -o $(OUTPUT_NAME)

local: RelayController.cpp main.cpp ../I2CLib/i2c.cpp
		make clean
		$(BUILD)

remote: RelayController.cpp main.cpp ../I2CLib/i2c.cpp
		make clean
		git pull
		$(BUILD)

clean:
	rm -f $(OUTPUT_NAME)