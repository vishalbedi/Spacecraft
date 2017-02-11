//
// Created by vishal on 2/10/17.
//

#include "spacecraft.h"
#include <cmath>

using std::cout;
using std::endl;
using std::ostream;

using ritcs::Spacecraft;

unsigned int Spacecraft::next_id = 1;

const double Spacecraft::LIGHT_YEAR = 9.4607e15;

Spacecraft::Spacecraft(const std::string &name) :
        id_(next_id++),
        name_(name),
        warp_(0),
        velocity_(0),
        distance_(0) {
    cout << "Creating: " << *this << endl;
}

Spacecraft::~Spacecraft() {
    cout << "Destroying: " << *this << endl;
}

Spacecraft::Spacecraft(const Spacecraft &other) :
        id_(next_id++),
        name_(other.get_name() + " copy"),
        warp_(0),
        velocity_(0),
        distance_(0) {
    cout << "Copying: " << *this << endl;
}


std::string Spacecraft::get_name() const {
    return name_;
}

int Spacecraft::get_id() const {
    return id_;
}


unsigned int Spacecraft::get_speed() const {
    return warp_;
}

double Spacecraft::get_light_years_travelled() const {
    return distance_;
}

void Spacecraft::punch_it_chewy(unsigned int warp_speed) {
    warp_ = warp_speed > Spacecraft::MAX_WARP_SPEED ? Spacecraft::MAX_WARP_SPEED : warp_speed;
}

double Spacecraft::fly(int time) {
    velocity_ = Spacecraft::SPEED_OF_LIGHT * (long) std::pow(warp_, 3.0);
    double distance_travelled_m = velocity_ * time;
    double distance_travelled_light_years = distance_travelled_m / Spacecraft::LIGHT_YEAR;
    distance_ += distance_travelled_light_years;
    return distance_travelled_light_years;
}

namespace ritcs {
    std::ostream &operator<<(std::ostream &os, const Spacecraft &s) {
        return os << "Spacecraft(" << s.id_ << "){" <<
                  "name=" << s.name_ <<
                  ", warp=" << s.warp_ <<
                  ", velocity=" << s.velocity_ <<
                  ", distance=" << s.distance_ <<
                  "}";
    }
}

