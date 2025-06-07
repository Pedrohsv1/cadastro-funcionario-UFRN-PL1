# Compiler and flags
G = g++
GFLAGS = -Wall

# Object files
OBJS = main.o estagiario.o gerente.o desenvolvedor.o funcionario.o gettype.o

# Build target
programa: $(OBJS)
	$(G) $(GFLAGS) -o programa $(OBJS)

main.o: main.cpp estagiario.h funcionario.h gerente.h desenvolvedor.h gettype.h
	$(G) $(GFLAGS) -c main.cpp

gettype.o: gettype.cpp gettype.h
	$(G) $(GFLAGS) -c gettype.cpp

estagiario.o: estagiario.cpp estagiario.h funcionario.h
	$(G) $(GFLAGS) -c estagiario.cpp

gerente.o: gerente.cpp gerente.h funcionario.h
	$(G) $(GFLAGS) -c gerente.cpp

desenvolvedor.o: desenvolvedor.cpp desenvolvedor.h funcionario.h
	$(G) $(GFLAGS) -c desenvolvedor.cpp

funcionario.o: funcionario.cpp funcionario.h
	$(G) $(GFLAGS) -c funcionario.cpp

.PHONY: clean
clean:
	rm -f *.o programa
