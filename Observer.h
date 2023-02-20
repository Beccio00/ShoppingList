//
// Created by Riccardo Becciolini on 19/02/23.
//

#ifndef PROJECTLAB_OBSERVER_H
#define PROJECTLAB_OBSERVER_H

class Subject;

class Observer {
public:
    virtual ~Observer() {};
    virtual void update(Subject* list) = 0;
    virtual void attach(Subject* list) = 0;
    virtual void detach(Subject* list) = 0;
};

#endif //PROJECTLAB_OBSERVER_H
