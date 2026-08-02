#include <iostream>

namespace Helpers
{
    // thanks qbert220
    // https://stackoverflow.com/a/18822888
    class OStreamSaver
    {
    public:
        explicit OStreamSaver(std::ostream& out)
        :  m_out{ out }, m_flags{ out.flags() } {}

        ~OStreamSaver()
        {
            m_out.flags(m_flags);
        }

        OStreamSaver(const OStreamSaver& oss) = delete;

        OStreamSaver& operator=(const OStreamSaver& oss) = delete;

    private:
        std::ostream& m_out;
        std::ios::fmtflags m_flags;
    };

}
