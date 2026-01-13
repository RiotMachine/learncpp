// type deduction: pointers, references, and const
/// top-level const applies to the object itself
/// low-level const applies to the object being referenced or pointed to
//// low-level consts survive type deduction, top-level consts do not
//// pointers survive type deduction, refs do not

#include <string>
#include <string_view>

constexpr std::string_view hello{ "Hello" };

constexpr const std::string_view& getConstStr() 	// function is constexpr, returns const std::string_view&
{
    return hello;
}

std::string* getPtr()
{
    static std::string s{ "Hey" };
    return &s;
}

std::string s{ };
const std::string* const ptr{ &s }; 			// const pointer to const

int main()
{
    auto		ref1{ getConstStr() };		// std::string_view			ref drops, const becomes top-level then drops
    const auto		ref2{ getConstStr() };		// const std::string_view		ref drops, const drops, const is reapplied
    auto&		ref3{ getConstStr() };		// const std::string_view&		const stays since it is low-level
    const auto&		ref4{ getConstStr() };		// const std::string_view&		const stays anyway but is explicitly stated (best practice)
    constexpr auto 	ref5{ getConstStr() };		// constexpr std::string_view		ref drops, const drops, constexpr applied
    constexpr const auto& ref6{ getConstStr() };	// constexpr const std::string_view&	const stays but stated explicitly; constexpr ref to const
    /*
    "When applied to a reference, constexpr allows the reference to be used in a constant expression.
    "Constexpr references have a particular limitation: they can only be bound to objects with static duration (either globals or static locals).
    "This is because the compiler knows where static objects will be instantiated in memory, so it can treat that address as a compile-time constant."
    */

    auto		ptr1{ getPtr() };		// std::string*				unlike refs, type deduction does not drop pointers
    auto*		ptr2{ getPtr() };		// std::string*				same type as above but more explicit
    auto		str{ *getPtr() };		// std::string				dereferencing ptr then deducing auto
    //auto*		fail{ *getPtr() };		// wont compile				auto* needs to be initialized with a pointer
    auto const		ptr3{ getPtr() };		// std::string* const			pointer is const pointer
    const auto		ptr4{ getPtr() };		// std::string* const			pointer is const pointer (ie. 'const int' == 'int const')
    auto* const		ptr5{ getPtr() };		// std::string* const
    const auto*		ptr6{ getPtr() };		// const std::string*			pointer to const

    auto		ptr7{ ptr };			// const std::string*			type deduction does not drop pointers, low-level const survives
    auto*		ptr8{ ptr };			// const std::string*
    auto const		ptr9{ ptr };			// const std::string* const		top-level const is applied following deduction
    const auto		ptr10{ ptr };			// const std::string* const
    auto* const		ptr11{ ptr };			// const std::string* const		top-level const is applied
    const auto*		ptr12{ ptr };			// const std::string*			redundant application of surviving low-level const
    //const auto const	fail{ ptr };			// wont compile				syntax error (ie. 'const int const')
    const auto* const	ptr13{ ptr };			// const std::string* const		[best practice to be explicit with consts; good idea to use auto*]


    return 0;
}
