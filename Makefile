all: debug_Q1 optimization_Q1 debug_Q2 optimization_Q2 debug_Q3 optimization_Q3 debug_Q4 optimization_Q4 
		

debug_Q1:
		g++ -g Q1.cpp -o Q1_debug

optimization_Q1:
		g++ -O Q1.cpp -o Q1_optimized

debug_Q2:
		g++ -g Q2.cpp -o Q2_debug

optimization_Q2:
		g++ -O Q2.cpp -o Q2_optimized

debug_Q3:
		g++ -g Q3.cpp -o Q3_debug

optimization_Q3:
		g++ -O Q3.cpp -o Q3_optimized

debug_Q4:
		g++ -g Q4.cpp -o Q4_debug

optimization_Q4:
		g++ -O Q4.cpp -o Q4_optimized