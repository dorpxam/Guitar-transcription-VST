#include "D:\ecler\Documents\Cours\Ingenieur_4A\Stage\Jacode_III\Builds\VisualStudio2019\AmplitudesEstimation.h"

#include <complex>
#include <cmath>
#include <iostream>


#define M_PI 3.141592653589793238460

using namespace std;

std::vector<double> AmplitudesEstimation(std::vector<std::complex<double>> const& segment, double f0Features, double betaFeatures, int lengthOfSegment, unsigned int sampleRate, unsigned int highNbOfHarmonics)
{

	std::cout << std::endl;
	std::cout <<" f : "<< f0Features << " // B : " << betaFeatures;
	std::cout << std::endl;

	Eigen::MatrixXcd Z(lengthOfSegment, highNbOfHarmonics);
	const complex<double> i(0.0, 1.0);

	for (double m = 1; m < highNbOfHarmonics+1.0; ++m)
	{
		for (double n = 0; n < lengthOfSegment; ++n)
		{
			Z(n, floor(m-1.0)) = std::exp((i * 2.0 * M_PI * f0Features * m * std::sqrt(1.0 + betaFeatures * pow(m, 2.0))) / double(sampleRate) * (n)); //I have delete a "-1"
		}
	}

	Eigen::VectorXcd alpha(highNbOfHarmonics);
	Eigen::VectorXcd x(lengthOfSegment);
	
	for (int c = 0; c < lengthOfSegment; ++c)
	{
		x(c) = segment[c];
	}

	Eigen::MatrixXcd ZT((Z.transpose()).conjugate());
	Eigen::MatrixXcd ZTINV((ZT * Z).inverse());

	alpha = ZTINV * ZT * x;

	std::vector<double> amplitudesAbs(highNbOfHarmonics);
	for (unsigned int c = 0; c < highNbOfHarmonics; ++c)
	{
		amplitudesAbs[c] = std::abs(alpha(c));
	}

	return(amplitudesAbs);
}
