#include <iostream>

// gets tower height from user and returns it
double getTowerHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double towerHeight{};
	std::cin >> towerHeight;
	return towerHeight;
}

// Returns ball height from ground after "seconds" seconds
constexpr double calculateBallHeight(double towerHeight, int seconds)
{
	constexpr double gravity{ 9.8 };

	// Using formula: [ s = u * t + (a * t^2) / 2 ], here u(initial velocity) = 0
	const double distanceFallen{ (gravity * (seconds * seconds)) / 2.0 };
	const double currentHeight{ towerHeight - distanceFallen };

	return currentHeight;
}

// Prints ball height above ground
/// Should not be constexpr since output is a runtime operation
void printBallHeight(double ballHeight, int seconds)
{
	if (ballHeight > 0.0)
		std::cout << "At " << seconds << " seconds, the ball is at height: " << ballHeight << " meters\n";
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

// Calculates the current ball height and then prints it
/// Should not be constexpr since output is a runtime operation
double displayBallHeight(double towerHeight, int seconds)
{
	const double ballHeight{ calculateBallHeight(towerHeight, seconds) };
	printBallHeight(ballHeight, seconds);
	return ballHeight;
}

int main()
{
	const double towerHeight{ getTowerHeight() };
	double ballHeight{ towerHeight };
	do
	{
		static int seconds{ 0 };
		ballHeight = displayBallHeight(towerHeight, seconds);
		++seconds;
	} while (ballHeight > 0);

	return 0;
}