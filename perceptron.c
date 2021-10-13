#include <stdio.h>

#include <stdlib.h>

#include "math.h"



double step(double x);

double sigmoid(double x);



int main(int argc, char* argv[])

{



	int input[4][2] = { 0,0,0,1,1,0,1,1 }; //input vector 

  //setting initial weigts, 1) user setting, 2) random stting  

	double w[2] = { -0.2, 0.2 };

	double thold = 0.0; // error threshold

	int x[2]; // array for input value 

	double bias = 1, w0 = -0.5;



	double y = 0; // output value 

	const int xnum = 2;//dimension of input

	int cnt = 0;

	double error = 0; // error



	double alpa = 0.1; //learning rate



	int iteration = 0, i;

	double sum = 0; //linear combination

	double error_tot = 0.0;



	printf("Perceptron AND operation \n");

	//Iteration: 1) Assigne specific number for iteration

	 // 2) if the error is below the threahold, stop iteration 

	while (iteration < 100)

	{

		printf(" \n%d iteration(epoch)\n", iteration);

		printf("weight:w[0] : %lf , w[1] : %lf \n", w[0], w[1]);

		for (i = 0; i < 4; i++)

		{



			for (cnt = 0; cnt < xnum; cnt++)x[cnt] = input[i][cnt];



			for (cnt = 0; cnt < xnum; cnt++)  sum += (x[cnt] * w[cnt]);

			sum += (bias * w0);



			// y = step(sum);  //activation function

			if (sigmoid(sum) > 0.5) y = 1;

			else y = 0;





			//error estimation  

			//  error = (x[0] ^ x[1]) - y;

			error = (x[0] && x[1]) - y;

			error_tot += error;



			printf("%d  %d output value : %lf \n", x[0], x[1], y);

			//weight updatem,mini-batch =1 

			for (cnt = 0; cnt < xnum; cnt++)

				w[cnt] = w[cnt] + alpa * x[cnt] * error;



		}



		//가중치 보정 full batch

   //for (cnt = 0; cnt < xnum; cnt++)  w[cnt] = w[cnt] + alpa * x[cnt] * error_tot;



		if (error_tot <= thold) break;

		else error_tot = 0;

		iteration++;

		sum = 0.0;

	}



	system("PAUSE");

	return 0;

}



double step(double x)

{

	if (x >= 0) return 1;

	else return 0;

}



double sigmoid(double x)

{

	double sig = 1.0 / (1.0 + exp(-x));

	return sig;

}

