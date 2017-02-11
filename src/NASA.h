//
// Created by vishal on 2/10/17.
//

#ifndef SPACECRAFT_NASA_H
#define SPACECRAFT_NASA_H

#include <string>
#include <list>
#include "spacecraft.h"

using ritcs::Spacecraft;
using std::list;

namespace ritcs {

    /**
     * A class that represents NASA, an organization that maintains a fleet of Spacecraft's
     * that can have various operations performed on them.
     */
    class NASA {
    public:
        /**
         * the maximum number of actively comissioned ships
         */
        static const unsigned int MAX_SHIPS = 10;

        /**
         * Create a new base for simulation
         */
        NASA();

        /**
         * Destroy the base and decomission all currently active spacecraft in the fleet.
         */
        ~NASA();

        /**
         * The main loop parses the commands and executes them in order, until the user either quits or
         * ends the standard input.
         */
        void main_loop();

    private:
        /**
         * List of all the valid commands
         */
        static const std::string CMD_COPY_;
        static const std::string CMD_CREATE_;
        static const std::string CMD_DESTROY_;
        static const std::string CMD_DISTANCE_;
        static const std::string CMD_FLY_;
        static const std::string CMD_LIST_;
        static const std::string CMD_PRINT_;
        static const std::string CMD_QUIT_;
        static const std::string CMD_WARP_;

        unsigned int active_spacecrafts_;
        /**
         * deck to store spacecrafts
         * cant have size more than MAX_FLEET_SIZE
         */
        list<ritcs::Spacecraft *> fleet;

        /**
         * Get the spacecraft from the fleet based on id
         * @param id of the spacecraft to find
         * @return spacecraft
         */
        Spacecraft *find(const unsigned int id);

        double total_distance_by_fleet;
    };
}


#endif //SPACECRAFT_NASA_H
