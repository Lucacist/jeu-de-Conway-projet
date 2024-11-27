CXX = g++
CXXFLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -g -Wall -Werror

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

all: main

main: $(SRCS) $(HEADERS)
    $(CXX) $(CXXFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS) $(HEADERS)
    $(CXX) $(CXXFLAGS) -U_FORTIFY_SOURCE -O0 $(SRCS) -o "$@"

clean:
    rm -f main main-debug
