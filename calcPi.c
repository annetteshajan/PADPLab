#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#define SEED 35791246

int main() {
	int n = 250000, i, count = 0;
	double z, pi, x,y;

	srand(SEED);

	double t=omp_get_wtime();
	#pragma omp parallel private(x, y, z) shared(count) num_threads(1)

	for ( i=0; i<n; i++) {
		x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;
		z = x*x+y*y;
		if (z<=1) count++;
	}
	pi=(double)count/n*4;

	printf("# of trials= %d , estimate of pi is %g, time=%g \n",n,pi,omp_get_wtime()-t);

	return 0;
}
