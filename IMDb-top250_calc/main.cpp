#include <iostream>


int exec();
double bayesian_est(double R, int v);

int main()
{
	return exec();
}

int exec()
{
	double mean;
	int votes;

	while (true) //Yes, dumb; quick loop
	{
		std::cout << "Enter score: ";
		std::cin >> mean;

		std::cout << "Number of votes for the film: ";
		std::cin >> votes;

		if (mean > 0 && votes > 0)
			std::cout << "TOP250 SCORE BAYESIAN ESTIMATE: "
				<< bayesian_est(mean, votes) << std::endl;
		system("PAUSE"); //windows
	}

	return 0;
}

double bayesian_est(double R, int v)
//The formula for calculating the Top Rated 250 Titles gives a true Bayesian estimate:
//weighted rating(WR) = (v ÷(v + m)) × R + (m ÷(v + m)) × C
//R = average for the movie(mean) = (Rating)
//v = number of votes for the movie = (votes)
//m = minimum votes required to be listed in the Top 250 (currently 25000)
//C = the mean vote across the whole report(currently 7.0)
//For the IMDb Top 250, only votes from regular voters are considered.
{
	double WR;
	const float C = 7.0;
	const int m = 25000;
	
	WR = (double(v) / (v + m)) * R + (double(m) / (v + m)) * C;

	return WR;
}