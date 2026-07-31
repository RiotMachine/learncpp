#ifndef RANDOM_H
#define RANDOM_H

#include <chrono>
#include <random>

// This namespace implements a self-seeding Mersenne Twister.
// Requires C++17
namespace Random
{
    // Create a std::mt19937, seed it, then return the std::mt19937
    // Returns a seeded Mersenne Twister
    inline std::mt19937 generate()
    {
 	std::random_device rd{};

	// Create seed_seq with clock and 7 random numbers
	std::seed_seq ss{
	static_cast<std::seed_seq::result_type>(
            std::chrono::steady_clock::now().time_since_epoch().count()
            ), rd(), rd(), rd(), rd(), rd(), rd(), rd() };

	return std::mt19937{ ss };
    }

    // Copies a seeded std::mt19937 into our global object
    inline std::mt19937 mt{ generate() };

    // Generate a random int between [min, max] (inclusive)
    inline int get(int min, int max)
    {
        return std::uniform_int_distribution{min, max}(mt);
    }


    // Function templates to generate random numbers

    // Generate a random value between [min, max] (inclusive)
    // * min and max must have the same type
    // Sample call: Random::get(1L, 6L);             // returns long
    template <typename T>
    T get(T min, T max)
    {
	return std::uniform_int_distribution<T>{min, max}(mt);
    }

    // Generate a random value between [min, max] (inclusive)
    // * min and max can have different types
    // * return type must be explicitly specified as a template argument
    // Sample call: Random::get<std::int>(0, 6u);    // returns int
    template <typename R, typename S, typename T>
    R get(S min, T max)
    {
	return get<R>(static_cast<R>(min), static_cast<R>(max));
    }
}

#endif
