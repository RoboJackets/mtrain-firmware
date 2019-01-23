
define cmake_build_target
	mkdir -p build
	cd build && cmake -DCMAKE_TOOLCHAIN_FILE=arm_toolchain.cmake --target $1 .. && make $1
endef

all:
	$(call cmake_build_target, all)

FIRMWARE_TESTS = blink flash usb_serial gpio gpio2 blink2
$(FIRMWARE_TESTS:%=test-%):
	$(call cmake_build_target, $(@F))
$(CPP_FIRMWARE_TESTS:%=test-%-prog):
	$(call cmake_build_target, $(@F))

clean:
	rm -rf build
