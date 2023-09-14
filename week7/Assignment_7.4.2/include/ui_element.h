#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include <vector>

// Interface for UI Element
class UIElement
{
public:
    /* Pure virtual functions (= 0 means a pure virtual)
     * - UIElement class becomes abstract (cannot create instance objects)
     * - derived classes (like Button) must have definitions (implementations)
     *   for pure virtual functions */
    // Function to click
    virtual void on_click() = 0;
    // Function to focus
    virtual void on_focus() = 0;
    // Function to move UIElement to position x, y
    virtual void move(int x, int y) = 0; // Move UI Element to x, y
    // Function to get current position of UIElement
    virtual void get_position() const = 0;

    /*To add elements
     * - child is a pointer to UIElement*/
    virtual void add_child(UIElement *child) = 0;
    /*To remove elements
     * - child is a pointer to UIElement*/
    virtual void remove_child(UIElement *child) = 0;
    /*To list elements
     * - returns a vector of pointers to UIElement*/
    virtual std::vector<UIElement *> list_children() const = 0;

    virtual ~UIElement() = default;
};

#endif
