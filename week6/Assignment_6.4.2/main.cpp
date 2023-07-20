// main.cpp
#include "tagged_union.h"
#include "text_file.h"

#include <iostream>
#include <vector>

// EXERCISES 3 and 4:

int main()
{
    TextFile file("text_file.txt", "r");
    std::vector<TaggedUnion> tagged_unions_vector;

    std::string line{};
    while (!(line = file.read_next_line()).empty())
    {
        TaggedUnion tagged_union = TextFile::create_object_from_string(line);
        tagged_unions_vector.push_back(tagged_union);
    }

    for (const auto &tagged_union : tagged_unions_vector)
    {
        std::cout << tagged_union << '\n';
    }

    return 0;
}
