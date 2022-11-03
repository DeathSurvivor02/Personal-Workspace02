#ifndef __ENVIRONMENT__H__
#define __ENVIRONMENT__H__

#include <random>
#include <iostream>

class Environment
{
public:
	int environment[9][9];

	// uh idkcollapse
	void grid_0();
	void random_gen();
	void iteration();
	void print();

	// cell mutation
	void increment();
	void cross_merge();
	void rotate();
	void reverse();
	void geneflip();
	void replace();
	void swap();
};

#endif
