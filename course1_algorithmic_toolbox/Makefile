CXX = g++
CXXFLAGS = -g -pipe -O2 -std=c++0x -lm

WEEK1_DIR = week1_programming_challenges
WEEK2_DIR = week2_algorithmic_warmup
WEEK3_DIR = week3_greedy_algorithms
WEEK4_DIR = week4_divide_and_conquer
WEEK5_DIR = week5_dynamic_programming1
WEEK6_DIR = week6_dynamic_programming2
OUT_DIR = bin

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
		week3_largest_number \
		week4_binary_search \
		week4_closest \
		week4_inversions \
		week4_majority_element \
		week4_points_and_segments \
		week4_sorting \
		week5_change_dp \
		week5_edit_distance \
		week5_lcs2 \
		week5_lcs3 \
		week5_primitive_calculator


all: init $(ALL)

init:
	mkdir -p $(OUT_DIR)

$(WEEK1_DIR)/%.o: $(WEEK1_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(WEEK2_DIR)/%.o: $(WEEK2_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(WEEK3_DIR)/%.o: $(WEEK3_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(WEEK4_DIR)/%.o: $(WEEK4_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(WEEK5_DIR)/%.o: $(WEEK5_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(WEEK6_DIR)/%.o: $(WEEK6_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@


week1_a_plus_b: $(WEEK1_DIR)/a_plus_b.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week1_max_pairwise_product: $(WEEK1_DIR)/max_pairwise_product.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@


week2_fibonacci: $(WEEK2_DIR)/fibonacci.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week2_fibonacci_last_digit: $(WEEK2_DIR)/fibonacci_last_digit.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week2_fibonacci_partial_sum: $(WEEK2_DIR)/fibonacci_partial_sum.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week2_fibonacci_sum: $(WEEK2_DIR)/fibonacci_sum.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week2_gcd: $(WEEK2_DIR)/gcd.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week2_huge_fibonacci: $(WEEK2_DIR)/huge_fibonacci.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week2_lcm: $(WEEK2_DIR)/lcm.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@


week3_change: $(WEEK3_DIR)/change.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week3_covering_segments: $(WEEK3_DIR)/covering_segments.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week3_different_summands: $(WEEK3_DIR)/different_summands.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week3_dot_product: $(WEEK3_DIR)/dot_product.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week3_fractional_knapsack: $(WEEK3_DIR)/fractional_knapsack.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week3_largest_number: $(WEEK3_DIR)/largest_number.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@


week4_binary_search: $(WEEK4_DIR)/binary_search.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week4_closest: $(WEEK4_DIR)/closest.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week4_inversions: $(WEEK4_DIR)/inversions.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week4_majority_element: $(WEEK4_DIR)/majority_element.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week4_points_and_segments: $(WEEK4_DIR)/points_and_segments.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week4_sorting: $(WEEK4_DIR)/sorting.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@


week5_change_dp: $(WEEK5_DIR)/change_dp.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week5_edit_distance: $(WEEK5_DIR)/edit_distance.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week5_lcs2: $(WEEK5_DIR)/lcs2.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week5_lcs3: $(WEEK5_DIR)/lcs3.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@

week5_primitive_calculator: $(WEEK5_DIR)/primitive_calculator.o
	$(CXX) $(CXXFLAGS) $? -o $(OUT_DIR)/$@


.PHONY: clean

clean:
	rm -f $(WEEK1_DIR)/*.o $(WEEK2_DIR)/*.o $(WEEK3_DIR)/*.o
	rm -f $(WEEK4_DIR)/*.o $(WEEK5_DIR)/*.o $(WEEK6_DIR)/*.o
	rm -rf $(OUT_DIR)
