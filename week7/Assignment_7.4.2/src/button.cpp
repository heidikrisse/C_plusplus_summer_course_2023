// button.cpp
#include "../include/button.h"

#include <iostream>
#include <algorithm>

void Button::on_click()
{
    std::cout << "Button clicked!\n";
}

void Button::on_focus()
{
    std::cout << "Button in focus!\n";
}

void Button::move(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Button::get_position() const
{
    std::cout << "Button position: (" << x << ", " << y << ")\n";
}

void Button::add_child(UIElement *child)
{
    children.push_back(child);
}

void Button::remove_child(UIElement *child)
{
    children.erase(std::remove(children.begin(), children.end(), child), children.end());
}

std::vector<UIElement *> Button::list_children() const
{
    return children;
}
