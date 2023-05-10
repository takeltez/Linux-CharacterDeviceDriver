TARGET := char_dev

SRC_DIR := src/
BUILD_DIR := build/
OBJ_DIR := obj/
MOD_DIR := modules/

MOD_EXT := .ko

KDIR := /lib/modules/$(shell uname -r)/build

obj-m := $(OBJ_DIR)$(TARGET).o
$(OBJ_DIR)$(TARGET)-objs := $(SRC_DIR)$(TARGET).o

.PHONY: all clean install dir rdir

all: dir $(TARGET) install

$(TARGET):
	make -C $(KDIR) M=$(PWD)/$(BUILD_DIR) src=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD)/$(BUILD_DIR) src=$(PWD) clean
	rm -f $(MOD_DIR)$(TARGET)$(MOD_EXT)
	rm -rf $(BUILD_DIR)*

install:
	install $(BUILD_DIR)$(OBJ_DIR)$(TARGET)$(MOD_EXT) $(MOD_DIR)
	rm -f $(BUILD_DIR)$(OBJ_DIR)$(TARGET)$(MOD_EXT)

dir:
	mkdir -p $(MOD_DIR)
	mkdir -p $(BUILD_DIR)

rdir:
	rm -rf $(MOD_DIR)
	rm -rf $(BUILD_DIR)
