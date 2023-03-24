#pragma once

#include <memory> // using function from memory library
#include <stack> // states will be based on a stack so that the top state will be running and we can pop it off
#include "states.h" // Includes our state

typedef std::unique_ptr<States> state_reference;

// Handle all of our states, will basically be the backbone of our app
class StateMachine {
public:
    // state machine constructor
    StateMachine() {}
    // state machine destructor
    ~StateMachine() {}

    // Adds a state onto the stack or manually removes one
    void add_state(state_reference latest_state, bool is_replacing_state = true);
    void remove_state();

    //runs at the start of each loop to process whatever state changes there maybe
    void process_state_changes();

    // gets a reference to the current active state
    state_reference &get_active_state();

private:
    // creates a stack of unique pointers from our states header file
    std::stack<state_reference> current_states;
    state_reference new_states;

    // will track if we are removing, adding, or replacing a state, and we know what we're doing when we process states
    bool is_adding;
    bool is_removing;
    bool is_replacing;
};