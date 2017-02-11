//
// Created by vishal on 2/10/17.
//

#include "NASA.h"

using std::cout;
using std::cin;
using std::endl;

using ritcs::NASA;

NASA::NASA() :
        active_spacecrafts_(0),
        total_distance_by_fleet(0) {}

NASA::~NASA() {}

const std::string NASA::CMD_COPY_ = "copy";
const std::string NASA::CMD_CREATE_ = "create";
const std::string NASA::CMD_DESTROY_ = "destroy";
const std::string NASA::CMD_DISTANCE_ = "distance";
const std::string NASA::CMD_FLY_ = "fly";
const std::string NASA::CMD_LIST_ = "list";
const std::string NASA::CMD_PRINT_ = "print";
const std::string NASA::CMD_QUIT_ = "quit";
const std::string NASA::CMD_WARP_ = "warp";

void NASA::main_loop() {
    std::string cmd;
    bool quit = false;
    while (!quit) {
        cin >> cmd;
        if (cmd.compare(NASA::CMD_CREATE_) == 0) {
            std::string spacecraft_name;
            cin >> spacecraft_name;
            if (active_spacecrafts_ < MAX_SHIPS) {
                NASA::fleet.push_back(new Spacecraft(spacecraft_name));
                NASA::active_spacecrafts_++;
            } else {
                cout << "Can't create any more ships!" << endl;
            }
        } else if (cmd.compare(NASA::CMD_DESTROY_) == 0) {
            unsigned int id;
            cin >> id;
            Spacecraft *ship = find(id);
            if (ship != NULL) {
                delete ship;
                fleet.remove(ship);
            }
        } else if (cmd.compare(NASA::CMD_COPY_) == 0) {
            unsigned int id;
            cin >> id;
            Spacecraft *ship = find(id);
            if (ship != NULL) {
                if (active_spacecrafts_ < MAX_SHIPS)
                    fleet.push_back(new Spacecraft(*ship));
                else
                    cout << "Can't create any more ships!" << endl;
            } else {
                cout << "Ship " << id << " not found!" << endl;
            }
        } else if (cmd.compare(NASA::CMD_FLY_) == 0) {
            unsigned int id, time;
            cin >> id >> time;
            Spacecraft *ship = find(id);
            if (ship != NULL) {
                double distance_travelled_now = ship->fly(time);
                total_distance_by_fleet += distance_travelled_now;
                cout << ship->get_name() << " flies " << time << " seconds for " << distance_travelled_now
                     << " light years" << endl;
            }
        } else if (cmd.compare(NASA::CMD_LIST_) == 0) {
            list<Spacecraft *>::iterator iter;
            for (iter = fleet.begin();
                 iter != fleet.end();
                 ++iter) {
                cout << **iter << endl;
            }
        } else if (cmd.compare(NASA::CMD_PRINT_) == 0) {
            unsigned int id;
            cin >> id;
            Spacecraft *ship = find(id);
            if (ship != NULL) {
                cout << *ship << endl;
            }
        } else if (cmd.compare(NASA::CMD_DISTANCE_) == 0) {
            unsigned int id;
            cin >> id;
            Spacecraft *ship = find(id);
            if (ship != NULL) {
                ship->get_light_years_travelled();
                cout << ship->get_name() << " has flown  " << ship->get_light_years_travelled() << " light years"
                     << endl;
            }
        } else if (cmd.compare(NASA::CMD_WARP_) == 0) {
            unsigned int id, warp;
            cin >> id >> warp;
            Spacecraft *ship = find(id);
            if (ship != NULL) {
                ship->punch_it_chewy(warp);
                cout << ship->get_name() << " set to warp speed " << ship->get_speed() << endl;
            }
        } else if (cmd.compare(NASA::CMD_QUIT_) == 0) {
            cout << "All ships have flown a total of " << total_distance_by_fleet << " light years" << endl;
            list<Spacecraft *>::iterator iter;
            for (iter = fleet.begin();
                 iter != fleet.end();
                 ++iter) {
                delete *iter;
            }
            quit = true;
        }
    }
}

Spacecraft *NASA::find(const unsigned int id) {
    list<Spacecraft *>::iterator iter;
    for (iter = fleet.begin();
         iter != fleet.end();
         ++iter) {
        if ((*iter)->get_id() == id) {
            return *iter;
        }
    }
    return NULL;
}

