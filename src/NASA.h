//
// Created by vishal on 2/10/17.
//

#ifndef SPACECRAFT_NASA_H
#define SPACECRAFT_NASA_H

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
    };
}


#endif //SPACECRAFT_NASA_H
