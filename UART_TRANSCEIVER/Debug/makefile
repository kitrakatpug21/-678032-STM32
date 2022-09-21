################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := UART_TRANSCEIVER
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
UART_TRANSCEIVER.elf \

MAP_FILES += \
UART_TRANSCEIVER.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
UART_TRANSCEIVER.list \

OBJCOPY_HEX += \
UART_TRANSCEIVER.hex \


# All Target
all: main-build

# Main-build Target
main-build: UART_TRANSCEIVER.elf secondary-outputs

# Tool invocations
UART_TRANSCEIVER.elf UART_TRANSCEIVER.map: $(OBJS) $(USER_OBJS) F:\STM_06-09-22\UART_TRANSCEIVER\STM32F401RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "UART_TRANSCEIVER.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"F:\STM_06-09-22\UART_TRANSCEIVER\STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="UART_TRANSCEIVER.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

UART_TRANSCEIVER.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "UART_TRANSCEIVER.list"
	@echo 'Finished building: $@'
	@echo ' '

UART_TRANSCEIVER.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "UART_TRANSCEIVER.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) UART_TRANSCEIVER.elf UART_TRANSCEIVER.hex UART_TRANSCEIVER.list UART_TRANSCEIVER.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
