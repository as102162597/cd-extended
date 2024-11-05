CXX         = g++
CXXFLAGS    = -Wall -std=c++20 -O2 -Iserv -Iexec -Iconv
MAINSRCS    = main.cpp
CONVSRCS    = parser.cpp
EXECSRCS    = clearbehavior.cpp displayusagebehavior.cpp editfilebehavior.cpp footprint.cpp \
              inputbehavior.cpp listbehavior.cpp outputbehavior.cpp
SERVSRCS    = debugprinter.cpp docprinter.cpp errorprinter.cpp infoprinter.cpp printer.cpp \
              service.cpp setting.cpp
SOURCES     = $(MAINSRCS) $(patsubst %,conv/%,$(CONVSRCS)) \
              $(patsubst %,exec/%,$(EXECSRCS)) $(patsubst %,serv/%,$(SERVSRCS))
OBJECTS     = $(patsubst %.cpp,%.o,$(SOURCES))
TARGET      = dirctl

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
