# Configures
DIST	?= dist
SRC   ?= src
HTML  ?= html

TARGET := $(DIST)/index.js

# Phony Targets
.PHONY: all
all: enviroment build

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

.PHONY: server
server:
	@python3 -m http.server --directory dist 10000

# Targets
$(TARGET): src/main.cpp
	@echo "Building"
	@em++ $^ -o $@