from conans import ConanFile, CMake

class MtrainConan(ConanFile):
    name = "mTrain"
    version = "0.1.1"
    url = "https://github.com/RoboJackets/mtrain-firmware"
    description = "mTrain description"
    settings = {"build_type": None, "compiler": None, "arch": ["armv7hf"]}
    generators = "cmake"
    exports_sources = ['CMakeLists.txt', 'API*', 'BSP*', 'external*', 'util/flash.py']

    def build(self):
        cmake = CMake(self)
        # cmake.verbose = True
        cmake.configure(args=['--no-warn-unused-cli'])
        cmake.build()

    # TODO: Clean up these crazy include paths
    def package(self):
        self.copy(pattern='*.a', dst='lib', src='lib')

        self.copy(pattern='*.h', dst='API', src='API')
        self.copy(pattern='*.hpp', dst='API', src='API')
        self.copy(pattern='*.h', dst='BSP', src='BSP')
        self.copy(pattern='*.h', dst='external', src='external')
        self.copy(pattern='flash.ld', dst='.', src='BSP')
        self.copy(pattern='flash.py', dst='.', src='util')

    def package_info(self):
        self.cpp_info.includedirs = ['API/c/Inc', 'API/cpp/Inc', 'BSP/config/hal', 'BSP/config/usb', 'BSP/Inc',
            'external/CMSIS/Device/STM32F7xx/Include', 'external/CMSIS/Include', 'external/middleware', 'external/STM32F7xx_HAL_Drivers/Inc']
        self.cpp_info.exelinkflags.append('-T %s/flash.ld' % self.package_folder)
        self.cpp_info.libs = ['STM32F7xx', 'STM32F7_API_CPP', 'STM32F7_API_C', 'STM32_USB_Device', 'STM32F7xx_HAL', 'DSP']

        self.env_info.FLASH_COPY_SCRIPT = '%s/flash.py' % self.package_folder

        #TODO: Make not needed
        self.cpp_info.defines = ['STM32F769xx']