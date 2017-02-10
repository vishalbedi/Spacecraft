//
// Created by vishal on 2/10/17.
//

#ifndef SPACECRAFT_SPACECRAFT_H
#define SPACECRAFT_SPACECRAFT_H

#include <string>
#include <iostream>

/**
 * A class to represent Spacecrafts
 */

namespace ritcs {


    class Spacecraft {
    public:
        /**
         * Maximum warp factor the ship can go
         */
        static const unsigned int MAX_WARP_SPEED = 10;

        /**
         * Speed at which light travels in m/s
         */
        static const long SPEED_OF_LIGHT = 299792458L;

        /**
         * One light year is 9.4607×10^15 meters
         */
        static const double LIGHT_YEAR = 9.4607e15;

        /**
         * Create a new Spacecraft
         * @param name the name of the Spacecraft
         */
        Spacecraft(const std::string &name);

        /**
         * Destroy the spacecraft
         */
        ~Spacecraft();


        /**
         * Copy constructor
         * @param other Spacecraft instance to copy
         */
        Spacecraft(const Spacecraft &other);

        /**
         * Get the name of the ship.
         * @return the ship name
         */
        std::string get_name() const;


        /**
         * Gets the id of the spacecraft
         * @return spacecraft id
         */
        int get_id() const;

        /**
         * gets the ships current speed
         * @return current spacecraft speed
         */
        unsigned int get_speed() const;


        /**
         * gets the total light years travelled by the ship
         * @return total light years travelled
         */
        double get_light_years_travelled() const;

        /**
         * Set the warp speed to desired factor not greater than MAX_WARP_SPEED
         * @param warp_speed
         */
        void punch_it_chewy(unsigned int warp_speed);

        /**
         * Have the spacecraft fly at current speed for ann amount of time (in seconds)
         * According to the original Star Trek, the formula for computing the ships velocity, V (m/s),
         * given the speed of light, C (m/s), and the warp speed, W, is:
         *
         * V = C * W^3
         *
         * The distance travelled, D (m), given velocity, V (m/s) and time, T (s) is (this is grossly simplified here):
         *
         * D = V * T
         * @param time
         * @return distance travelled for this call in light years
         */
        double fly(int time);

        /**
         * Output the ship in the format:
         *
         * Spacecraft({id}){name={name}, warp={speed}, velocity={velocity}, distance={distance}}
         * @param os
         * @param s
         * @return the ostream (for chaining)
         */
        std::ostream &operator<<(std::ostream &os, const Spacecraft &s);
    };
}


#endif //SPACECRAFT_SPACECRAFT_H
