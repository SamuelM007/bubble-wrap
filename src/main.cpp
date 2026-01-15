#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>


int main() {

    bn::core::init();

    bn::backdrop::set_color(bn::color(0, 0, 0));
    
    
    
    while(true) {
        
        int red = 0, green = 0, blue = 0;
        if (bn::keypad::l_held()) {
            red = 31;
            bn::backdrop::set_color(bn::color(red, green, blue));
        } else {
            red = 0;
            bn::backdrop::set_color(bn::color(red, green, blue));
        }

        if (bn::keypad::r_held()) {
            green = 31;
            bn::backdrop::set_color(bn::color(red, green, blue));
        }else {
            green = 0;
            bn::backdrop::set_color(bn::color(red, green, blue));
        }

        if (bn::keypad::up_held()) {
            blue = 31;
            bn::backdrop::set_color(bn::color(red, green, blue));
        }else {
            blue = 0;
            bn::backdrop::set_color(bn::color(red, green, blue));
        }


        bn::core::update();
    }

}
