MAIN_1    = main
CXX_SRCS  = Clube.cpp JogadorLivre.cpp JogadorContrato.cpp Jogador.cpp

CXX       = g++ 
CXX_OBJS  = ${CXX_SRCS:.cpp=.o}
MAIN_SRCS = $(wildcard main.cpp)
MAIN_OBJS = ${MAIN_SRCS:.cpp=.o}

all: $(MAIN_1) clean_obj

$(MAIN_1): $(MAIN_OBJS) $(CXX_OBJS)
	$(CXX) $(MAIN_1).o $(CXX_OBJS) -o $(MAIN_1)
	
clean: clean_obj
	@- $(RM) $(MAIN_1)
	
clean_obj:
	@- $(RM) $(MAIN_OBJS) $(CXX_OBJS)
