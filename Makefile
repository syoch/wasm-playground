# Configures
DIST	?= dist
SRC   ?= src
HTML  ?= html

TARGET := $(DIST)/index.js

# Phony Targets
.PHONY: all
all: clean enviroment build

.PHONY: build
build: $(TARGET)
	cp $(HTML)/* $(DIST)

.PHONY: enviroment
enviroment:
	@[ -f $(DIST) ] || mkdir -p $(DIST)

.PHONY: clean
clean:
	@echo "Cleaning"
	@rm -drf $(DIST)

# Targets
$(TARGET): src/main.cpp
	@echo "Building"
	@em++ $^ -o $@