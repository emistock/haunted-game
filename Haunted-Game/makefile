
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = main.o inputValidation.o menu.o Game.o Bath.o Bedroom.o Dining.o displayImage.o Kitchen.o Living.o mainHall.o Patio.o Player.o Space.o Study.o

SRCS = main.cpp inputValidation.cpp menu.cpp Game.cpp Bath.cpp Bedroom.cpp Dining.cpp displayImage.cpp Kitchen.cpp Living.cpp mainHall.cpp Patio.cpp Player.cpp Space.cpp Study.cpp

HEADERS = inputValidation.hpp menu.hpp Game.hpp Bath.hpp Bedroom.hpp Dining.hpp displayImage.hpp Kitchen.hpp Living.hpp mainHall.hpp Patio.hpp Player.hpp Space.hpp Study.hpp

#target: dependencies
#	rule to build
#

prog: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o prog

clean:
	$(RM) *.o *a.out
