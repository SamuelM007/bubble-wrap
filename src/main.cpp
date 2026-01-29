#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>
#include <bn_vector.h>
#include <bn_math.h>


int main() {

    bn::core::init();

    bn::backdrop::set_color(bn::color(0, 0, 0));

    bn::vector<bn::sprite_ptr, 100> circles = {};


    for(int y = -40; y <=40; y += 10){

        for(int x = -40; x <= 40; x += 10) {
            circles.push_back(bn::sprite_items::dot.create_sprite(x, y));
        }
    }

   
    
    
    
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

        if(bn::keypad::down_held()){
            for(int i = 0; i < 20; i++){
                circles[i].set_vertical_scale(2);
            }
        } else {
            for(int i = 0; i < 20; i++){
                circles[i].set_vertical_scale(1);
            }
        }

        // if(bn::keypad::left_held()){
        //     for(int i = 0; i < 100; i+=10){
        //         circles[i].set_horizontal_scale(2);
        //     }
        // } else {
        //     for(int i = 0; i < 100; i+=10){
        //         circles[i].set_horizontal_scale(1);
        //     }
        // }




        bn::core::update();
    }


    

}
