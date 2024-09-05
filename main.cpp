/*
RANKING SYSTEM:
-----------------------------------------------------------------------------
The goal of this project is to construct a Ranking system formula inspired by the
Sonic Heroes result screen when you finish a level.

This simple ranking system calculates your results based on a precentage of a combination
of different points (similar to how you would get graded on a module at school/Uni, 40% exam
and 60% coursework).

reprecentations:
fish     = 40% |
distance = 60% | Total = 40% + 60% = 100%

Note: 
This code was constructed back in 2017 to test the ranking system I was 
working on for a cancelled game at the time, more info regarding this:
https://alexp1049.wixsite.com/alexphillipscelllx/Project_CopterCar
------------------------------------------------------------------------------
 Copyright (c) 2017 R. Alex. W. Phillips
*/
#include <iostream>

// RANKING SYSTEM ///////////////////////////////////////////////////////////////////////////////////////
float fishPoints   = 13.3f;
float TimeScore,
	   TimeTotal,
       fishQuantity = 0.0f;

//calculate both totals
void CalculateScore(float _fishPoints, float _fishQuantity, float _timeScore, float _timeTotal)
{

	// key
	// RP = rank procentage 
	//work out the total score for the fish //////
	float TotalScoreForFish = 0.0f;
	float FS_divideBy_RP, //dividing the amount of score for the fish by rank percentage (RP)
	      devidFishScore,
	      FishPercentage = 0.0f;

	//multipliy the points based on the fish quantity obtained by player  [equation]
	/*
		In the case of the player obtaining all 3 fishs they will get 40 in
		score, which we would later want to convert into percentage to make
		it the equvilant of 100% for the fish point total, so i do this:

		TotalScoreFish = 13.3 * 3 + 0.1 = 40
		FishPercentage = 100;

		this gives us 0.4 aka 2/5 in percentage:
		FS_divideBy_RP = (40 / FishPercentage)

		our goal is to make getting 40 in score repercent getting 100% in score.
		So we do this:
		FS_divideBy_RP = (40 / FishPercentage);
		devidFishScore = (40 / FS_divideBy_RP);

		I also made a variation of different percent levels since theres
		only 3 fish to collect:

		FishPercentage = 50 // aka 50%, when you get 2 fish
		FishPercentage = 10 // aka 10%, when you get 1 fish
	*/
	TotalScoreForFish = _fishPoints * _fishQuantity;

	std::cout << "----------Calcul------------" << std::endl;

	if (_fishQuantity == 0)
	{
		std::cout << " F " << std::endl;
	}

	//Average out
	else if (_fishQuantity == 3)
	{
		TotalScoreForFish = (_fishPoints * _fishQuantity) + 0.1; //max total is 40%
		FishPercentage = 100;
		std::cout << " A " << std::endl;
	}

	else if (_fishQuantity == 2)
	{
		FishPercentage = 50;
		std::cout << " B " << std::endl;
	}

	else if (_fishQuantity == 1)
	{
		FishPercentage = 10;
		std::cout << " C " << std::endl;
	}

	FS_divideBy_RP = (TotalScoreForFish / FishPercentage);
	devidFishScore = (TotalScoreForFish / FS_divideBy_RP);





	if (_fishQuantity == 0)
	{
		std::cout << "Fish: " << "0%" << " :Collected" << "   //" << "40%" << " out of 100%" << std::endl;
	}
	else
	{
		std::cout << "Fish: " << devidFishScore << "%" << " :Collected" << "   //" << "40%" << " out of 100%" << std::endl;
	}

	std::cout << std::endl;
	//////////////////////////////////////////////


	//work out the total score for the time //////
	/*
		In this section I use the percentage equation to
		work out the players time and the total time
		duration:

		TotalScoreForTime = (_timeScore / _timeTotal);//max total is 60%
		PercentageToValue_TSRT = (TotalScoreForTime * 100);

		Then I set TimeScorePoints variable between 0-60 depending on the time
		score and max time amount, depending on will give the precentage rank
		for the total time score.
	*/
	float TotalScoreForTime,
		  PercentageToValue_TSRT,
	      TimeScorePoints,
	      devidTimeScore = 0;

	TotalScoreForTime = (_timeScore / _timeTotal);//max total is 60%
	PercentageToValue_TSRT = (TotalScoreForTime * 100);



	if (TimeTotal >= 0 && TimeTotal <= 5 || _timeScore >= 0 && _timeScore <= 5)
	{
		std::cout << " F " << std::endl;
	}


	else if (PercentageToValue_TSRT >= 5 && PercentageToValue_TSRT <= 39)
	{
		TimeScorePoints = 20;
		std::cout << " D " << std::endl;
	}

	else if (PercentageToValue_TSRT >= 40 && PercentageToValue_TSRT <= 59)
	{
		TimeScorePoints = 30;
		std::cout << " C " << std::endl;
	}

	else if (PercentageToValue_TSRT >= 60 && PercentageToValue_TSRT <= 79)
	{
		TimeScorePoints = 40;
		std::cout << " B " << std::endl;
	}

	else if (PercentageToValue_TSRT >= 80 && PercentageToValue_TSRT <= 89)
	{
		TimeScorePoints = 50;
		std::cout << " A " << std::endl;
	}

	else if (PercentageToValue_TSRT >= 90 && PercentageToValue_TSRT <= 100)
	{
		TimeScorePoints = 60;
		std::cout << " S " << std::endl;
	}

	if (PercentageToValue_TSRT >= 1 && PercentageToValue_TSRT <= 100)
	{
		std::cout << "Time: " << PercentageToValue_TSRT << "%" << " :Collected" << "   //" << "60%" << " out of 100%" << std::endl;
	}






	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;
	//////////////////////////////////////////////
	float Total = 0.0f;


	std::cout << "----TOTAL SCORE----" << std::endl;

	Total = (TotalScoreForFish + TimeScorePoints);

	if (Total >= 0 && Total <= 19)
	{
		std::cout << " F " << std::endl;
	}

	else if (Total >= 20 && Total <= 39)
	{
		std::cout << " D " << std::endl;
	}

	else if (Total >= 40 && Total <= 59)
	{
		std::cout << " C " << std::endl;
	}

	else if (Total >= 60 && Total <= 79)
	{
		std::cout << " B " << std::endl;
	}

	else if (Total >= 80 && Total <= 90)
	{
		std::cout << " A " << std::endl;
	}

	else if (Total >= 91 && Total <= 100)
	{
		std::cout << " S " << std::endl;
	}





	//std::cout << "time: " << TimeScore << std::endl;
	std::cout << Total << std::endl;
	std::cout << "-------------------" << std::endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	std::cout << "how many fish did you collect (max is 3)" << std::endl;
	std::cin >> fishQuantity;
	std::cout << std::endl;
	std::cout << "Amount of time set on the clock? (int value)" << std::endl;
	std::cin >> TimeTotal;
	std::cout << std::endl;
	std::cout << "what time did you clear the lvl in? (0 being the least and " << TimeTotal << " being the max)" << std::endl;
	std::cin >> TimeScore;
	std::cout << std::endl;


	CalculateScore(fishPoints, fishQuantity, TimeScore, TimeTotal);
	return 0;
}