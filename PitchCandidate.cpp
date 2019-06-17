#include "D:\ecler\Documents\Cours\Ingenieur_4A\Stage\Jacode_III\Builds\VisualStudio2019\PitchCandidate.h"
#include <limits>
#include <Eigen/Dense>

void PitchCandidate(std::vector<int>& fretCandidate, std::vector<int>& stringCandidate, float observedPitch, std::vector<float> pitchReference, int nbString)
{
	double minVal(std::numeric_limits<double>::max());
	int  minIndex(0);

	for (int i = 0; i < pitchReference.size(); ++i)
	{
		if (minVal > abs(log(pitchReference[i]) - log(observedPitch)))
		{
			minVal = abs(log(pitchReference[i]) - log(observedPitch));
			minIndex = i;
		}
	}

	int fretFind(floor(minIndex / nbString));
	int stringFind(minIndex % nbString);
	Eigen::MatrixXd Candidate(3, 2);
	Candidate(0, 0) = stringFind;
	Candidate(0, 1) = fretFind;

	switch (stringFind)
	{
	case 0:
		if (fretFind < 10 && fretFind > 4)
		{
			Candidate(1, 0) = stringFind + 1.0;
			Candidate(1, 1) = fretFind - 5.0;
		}

		if (fretFind > 9)
		{
			Candidate(1, 0) = stringFind + 1.0;
			Candidate(1, 1) = fretFind - 5.0;
			Candidate(2, 0) = stringFind + 2.0;
			Candidate(2, 1) = fretFind - 10.0;
		}
		break;
	case 1:
		if (fretFind < 5)
		{
			Candidate(1, 0) = stringFind - 1.0;
			Candidate(1, 1) = fretFind + 5.0;
		}

		if (fretFind > 4 && fretFind < 8)
		{
			Candidate(1, 0) = stringFind + 1.0;
			Candidate(1, 1) = fretFind - 5.0;
			Candidate(2, 0) = stringFind - 1.0;
			Candidate(2, 1) = fretFind + 5.0;
		}

		if (fretFind > 7 && fretFind < 10)
		{
			Candidate(1, 0) = stringFind + 1.0;
			Candidate(1, 1) = fretFind - 5.0;
		}

		if (fretFind > 9)
		{
			Candidate(1, 0) = stringFind + 1.0;
			Candidate(1, 1) = fretFind - 5.0;
			Candidate(2, 0) = stringFind + 2.0;
			Candidate(2, 1) = fretFind - 10.0;
		}

		break;

	case 2:

		if (fretFind < 5)
		{
			Candidate(1, 0) = stringFind - 1.0;
			Candidate(1, 1) = fretFind + 5.0;
		}
		if (fretFind < 3)
		{
			Candidate(2, 0) = stringFind - 2.0;
			Candidate(2, 1) = fretFind + 10.0;
		}

		if (fretFind > 4 && fretFind < 8)
		{
			Candidate(1, 0) = stringFind + 1.0;
			Candidate(1, 1) = fretFind - 5.0;
			Candidate(2, 0) = stringFind - 1.0;
			Candidate(2, 1) = fretFind + 5.0;
		}

		if (fretFind > 7 && fretFind < 10)
		{
			Candidate(1, 0) = stringFind + 1.0;
			Candidate(1, 1) = fretFind - 5.0;
		}

		if (fretFind > 8)
		{
			Candidate(1, 0) = stringFind + 1.0;
			Candidate(1, 1) = fretFind - 5.0;
			Candidate(2, 0) = stringFind + 2.0;
			Candidate(2, 1) = fretFind - 9.0;
		}

		break;

	case 3:

		if (fretFind < 4)
		{
			Candidate(1, 0) = stringFind - 1.0;
			Candidate(1, 1) = fretFind + 5.0;
		}

		if (fretFind < 3)
		{
			Candidate(2, 0) = stringFind - 2.0;
			Candidate(2, 1) = fretFind + 10.0;
		}

		if (fretFind > 3 && fretFind < 8)
		{
			Candidate(1, 0) = stringFind + 1.0;
			Candidate(1, 1) = fretFind - 4.0;
			Candidate(2, 0) = stringFind - 1.0;
			Candidate(2, 1) = fretFind + 5.0;
		}

		if (fretFind > 7 && fretFind < 10)
		{
			Candidate(1, 0) = stringFind + 1.0;
			Candidate(1, 1) = fretFind - 4.0;
		}

		if (fretFind > 8)
		{
			Candidate(1, 0) = stringFind + 1.0;
			Candidate(1, 1) = fretFind - 4.0;
			Candidate(2, 0) = stringFind + 2.0;
			Candidate(2, 1) = fretFind - 9.0;
		}

		break;

	case 4:

		if (fretFind < 5)
		{
			Candidate(1, 0) = stringFind - 1.0;
			Candidate(1, 1) = fretFind + 4.0;
		}


		if (fretFind < 4)
		{
			Candidate(2, 0) = stringFind - 2.0;
			Candidate(2, 1) = fretFind + 9.0;
		}

		if (fretFind > 4 && fretFind < 9)
		{
			Candidate(1, 0) = stringFind + 1.0;
			Candidate(1, 1) = fretFind - 5.0;
			Candidate(2, 0) = stringFind - 1.0;
			Candidate(2, 1) = fretFind + 4.0;
		}

		if (fretFind > 8)
		{
			Candidate(1, 0) = stringFind + 1.0;
			Candidate(1, 1) = fretFind - 5.0;
		}

		break;

	case 5:

		if (fretFind < 4)
		{
			Candidate(1, 0) = stringFind - 1.0;
			Candidate(1, 1) = fretFind + 5.0;
			Candidate(2, 0) = stringFind - 2.0;
			Candidate(2, 1) = fretFind + 9.0;
		}

		if (fretFind > 3 && fretFind < 8)
		{
			Candidate(1, 0) = stringFind - 1.0;
			Candidate(1, 1) = fretFind + 5.0;
		}

		break;

	default:

		break;
	}

	fretCandidate.resize(3);
	stringCandidate.resize(3);

	for (int j = 0; j < 3; ++j)
	{
		stringCandidate[j] = Candidate(j, 0);
		fretCandidate[j] = Candidate(j, 1);
	}

}