CXX = clang++
SDL = -framework SDL
# If your compiler is a bit older you may need to change -std=c++11 to -std=c++0x
CXXFLAGS = -Wall -c -std=c++11 -Iemulate -Ilibraries -include emulate/emulate.h
LDFLAGS = $(SDL) -framework Cocoa -lstdc++
# default sketch to compile
SKETCH = test1
EXE = $(SKETCH)
SKETCH_SOURCES := $(shell find sketches/$(SKETCH)/ -name '*.c' -name '*.cpp')
LIB_SOURCES := $(shell find libraries -name '*.cpp')
EMULATE_SOURCES := $(shell find emulate -name '*.cpp')
SKETCH_SOURCES = $(shell find ./sketches/$(SKETCH)/ -name *.cpp -o -name *.c)
SKETCH_OBJECTS=$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SKETCH_SOURCES)))
SOURCES=$(shell find . \( -name *.cpp -o -name *.c \) -not -path \"./sketches/*\")
OBJECTS=$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCES)))

all: $(EXE)

$(EXE): $(SKETCH_OBJECTS) $(OBJECTS) SDLMain.o
	$(CXX) $(LDFLAGS) $^ -o $@

VPATH = libraries:emulate:sketches/$(SKETCH)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -DGAMENAME=\"$(SKETCH)\" -DSKETCH=\"../sketches/$(SKETCH)/$(SKETCH).ino\" $< -o $@
	
%.o: %.c
	$(CXX) $(CXXFLAGS) -DGAMENAME=\"$(SKETCH)\" -DSKETCH=\"../sketches/$(SKETCH)/$(SKETCH).ino\" $< -o $@
	
SDLMain.o: emulate/SDLMain.m
	$(CXX) -c -I/Library/Frameworks/SDL.framework/Headers emulate/SDLMain.m -framework SDL -framework Cocoa -o SDLMain.o
	
clean:
	find . -name *.o -delete; rm $(EXE)

