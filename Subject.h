//
// Created by Riccardo Becciolini on 19/02/23.
//
#ifndef PROJECTLAB_SUBJECT_H
#define PROJECTLAB_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() {};
    virtual void subscribe(Observer* o) = 0;
    virtual void unsubscribe(Observer* o) = 0;
    virtual void notify() = 0;
};

#endif //PROJECTLAB_SUBJECT_H
