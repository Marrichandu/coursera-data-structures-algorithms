CC = gcc
CXX = g++
CFLAGS = -pipe -O2 -std=c11 -lm
CXXFLAGS = -pipe -O2 -std=c++0x -lm

WEEK1_DIR = week1_programming_challenges
WEEK2_DIR = week2_algorithmic_warmup
WEEK3_DIR = week3_greedy_algorithms
WEEK4_DIR = week4_divide_and_conquer
WEEK5_DIR = week5_dynamic_programming1
WEEK6_DIR = week6_dynamic_programming2

ALL = \
		week1_a_plus_b \
		week1_max_pairwise_product \
		week2_fibonacci \
		week2_fibonacci_last_digit \
		week2_fibonacci_partial_sum \
		week2_fibonacci_sum \
		week2_gcd \
		week2_huge_fibonacci \
		week2_lcm \
		week3_change \
		week3_covering_segments \
		week3_different_summands \
		week3_dot_product \
		week3_fractional_knapsack \
		week3_largest_number

all: $(ALL)

week1_a_plus_b: $(WEEK1_DIR)/a_plus_b.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

week1_max_pairwise_product: $(WEEK1_DIR)/max_pairwise_product.cpp
	$(CXX) $(CXXFLAGS) $? -o $@


week2_fibonacci: $(WEEK2_DIR)/fibonacci.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

week2_fibonacci_last_digit: $(WEEK2_DIR)/fibonacci_last_digit.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

week2_fibonacci_partial_sum: $(WEEK2_DIR)/fibonacci_partial_sum.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

week2_fibonacci_sum: $(WEEK2_DIR)/fibonacci_sum.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

week2_gcd: $(WEEK2_DIR)/gcd.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

week2_huge_fibonacci: $(WEEK2_DIR)/huge_fibonacci.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

week2_lcm: $(WEEK2_DIR)/lcm.cpp
	$(CXX) $(CXXFLAGS) $? -o $@


week3_change: $(WEEK3_DIR)/change.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

week3_covering_segments: $(WEEK3_DIR)/covering_segments.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

week3_dot_product: $(WEEK3_DIR)/dot_product.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

week3_fractional_knapsack: $(WEEK3_DIR)/fractional_knapsack.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

week3_largest_number: $(WEEK3_DIR)/largest_number.cpp
	$(CXX) $(CXXFLAGS) $? -o $@


.PHONY: clean

clean:
	rm -f $(ALL)
