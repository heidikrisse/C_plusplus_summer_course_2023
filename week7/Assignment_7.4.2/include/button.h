/* button.h
 *
 * Button inherits from UIElement.*/
#ifndef BUTTON_H
#define BUTTON_H

#include "ui_element.h"

#include <iostream>

// Button class (mock class) that inherits the UIElement interface
class Button : public UIElement
{
private:
    int x{};
    int y{};
    // Vector of pointers to UIElement
    std::vector<UIElement *> children;

public:
    void on_click() override;
    void on_focus() override;
    void move(int x, int y) override;
    void get_position() const override;
    void add_child(UIElement *child) override;
    void remove_child(UIElement *child) override;
    std::vector<UIElement *> list_children() const override;
};

#endif
