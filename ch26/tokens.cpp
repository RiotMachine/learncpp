#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <vector>

class TokenBox
{
public:
    TokenBox(const std::string& text)
      : m_tokens{ TokenBox::tokenize(text) } {}

    std::size_t size() const { return m_tokens.size(); }

    std::string_view longest() const
    {
        std::string_view maxToken;
        for (const auto& token : m_tokens)
        {
            if (token.size() > maxToken.size())
                maxToken = token;
        }
        return maxToken;
    }

    friend std::ostream& operator<<(std::ostream& out, const TokenBox& tb)
    {
        for (std::size_t i{ }; i < tb.size(); ++i)
            out << "Token " << i+1 << " (" << tb.m_tokens[i] << ") has idx "
                << i << " and len " << tb.m_tokens[i].size() << '\n';
        return out;
    }

private:
    using Box = std::vector<std::string>;

    static Box tokenize(const std::string& text)
    {
        std::stringstream ss{ text };
        std::string token;
        Box tokens;
        while (ss >> token)
            tokens.push_back(token);
        return tokens;
    }

    Box m_tokens{ };
};

int main()
{
    TokenBox tokens{
        "The quick brown fox jumps over the lazy dog."
    };

    std::cout << tokens << '\n'
              << "The longest token is " << tokens.longest()
              << ".\nThe total number of tokens is " << tokens.size() << ".\n";

    return 0;
}
