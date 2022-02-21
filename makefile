.PHONY: all mtrain tests docs clean $(CPP_FIRMWARE_TESTS)

CPP_FIRMWARE_TESTS = blink gpio spi usb_serial i2c i2c_bus_recovery

all : mtrain

mtrain:
	mkdir -p build && cd build && \
cmake .. && make -j

$(CPP_FIRMWARE_TESTS): tests
	mkdir -p build && cd build && \
cmake .. && make -j $(@F)

clean:
	rm -rf build
	rm -rf generated-docs

docs:
	cd doc && doxygen Doxyfile
	@echo "\n=> Open up 'generated-docs/index.html' in a browser to view a local copy of the documentation"
