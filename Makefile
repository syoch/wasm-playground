# Configures
DIST	?= dist
SRC   ?= src
HTML  ?= html

TARGET := $(DIST)/wasm.js

# Phony Targets
.PHONY: all
all: enviroment $(TARGET)

.PHONY: enviroment
enviroment:
	@[ -f $(DIST) ] || mkdir -p $(DIST)

.PHONY: clean
clean:
	@echo "Cleaning"
	@rm -drf $(DIST)/wasm.js $(DIST)/wasm.wasm

.PHONY: server
server:
	@python3 -m http.server --directory dist 10000

# Targets
$(TARGET): src/main.cpp
	@echo "Building"
	@em++ $^ -o $@