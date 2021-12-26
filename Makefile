# Configures
DIST	?= dist
SRC   ?= src

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
$(TARGET): $(wildcard $(SRC)/*)
	@echo "Building"
	@em++ src/main.cpp -o $@ --std=c++20 \
		-s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' \
		-s EXPORTED_FUNCTIONS='["_main", "_tick"]' \