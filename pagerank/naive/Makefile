KERN=pagerank
ALG=naive

CFLAGS?=-O3 -Wall -Wno-unused-label

CC = gcc

SRCS=$(KERN).c local_support.c ../../common/support.c
FILES=$(SRCS) $(KERN).h ../../common/support.h

$(KERN): $(FILES) ../../common/harness.c
	$(CC) $(CFLAGS) -I../../common -o $(KERN) $(SRCS) ../../common/harness.c

run: $(KERN) input.data check.data
	./$(KERN) input.data check.data

generate: $(FILES) generate.c
	$(CC) $(CFLAGS) -I../../common -o generate $(SRCS) generate.c
	./generate

hls: hls.tcl
	vivado_hls hls.tcl

syn: syn.tcl
	vivado -mode tcl -source syn.tcl -log ./syn.log

clean:
	rm -f $(KERN) generate output.data
