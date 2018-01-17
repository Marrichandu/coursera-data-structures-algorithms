CC = gcc
CXX = g++
CFLAGS = -pipe -O2 -std=c11 -lm
CXXFLAGS = -pipe -O2 -std=c++0x -lm

WEEK1 = week1_programming_challenges
WEEK2 = week2_algorithmic_warmup
WEEK3 = week3_greedy_algorithms
WEEK4 = week4_divide_and_conquer
WEEK5 = week5_dynamic_programming1
WEEK6 = week6_dynamic_programming2

ALL = \
		week1_a_plus_b \
		week1_max_pairwise_product

all: $(ALL)

week1_a_plus_b: $(WEEK1)/a_plus_b.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

week1_max_pairwise_product: $(WEEK1)/max_pairwise_product.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

.PHONY: clean

clean:
	rm -f $(ALL)
