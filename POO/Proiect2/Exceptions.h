#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>

class Exceptions : public std::exception
{
    const char* arg;
public:
    Exceptions(const char* arg) noexcept
    {
        this->arg = arg;
    }
    ~Exceptions()noexcept {}
    const char* what() const noexcept
    {
        return this->arg;
    }
};

#endif // EXCEPTIONS_H
