// function_template_class.h
#ifndef FUNCTION_TEMPLATE_CLASS_H
#define FUNCTION_TEMPLATE_CLASS_H

#include <tuple>
#include <cstddef> // for size_t

// --- Exercise 1a ---

// FunctionTemplateClass accepts arbitrary functions as template parameters
// - can store information about function return type and function arguments
// R = the return type of the function
// Args... = a variadic template that represents any number of any type of arguments
template <typename R, typename... Args>
class FunctionTemplateClass
{
public:
    // Constructor
    // - accepts a pointer to a function whose return type is R and takes Args... arguments
    // - uses the sizeof... operator to calculate the number of arguments (arity)
    FunctionTemplateClass(R (*func)(Args...)) : func_{func}, arity_{sizeof...(Args)}
    {
    }

    // --- Exercise 1b ---
    // Getter function to return the arity (number of arguments)
    size_t get_arity() const
    {
        return arity_;
    }

    // Type aliases for function return type and argument types
    using ReturnType = R;
    using ArgumentTypes = std::tuple<Args...>;

private:
    // Pointer to the function
    R(*func_)
    (Args...); // VSCode formatter splits the line for some reason, should be: R (*func_)(Args...);
    // Arity of the function
    size_t arity_;
};

// Function to return an instance of FunctionTemplateClass
template <typename R, typename... Args>
FunctionTemplateClass<R, Args...> make_function(R (*func)(Args...))
{
    return FunctionTemplateClass<R, Args...>(func);
}

#endif
