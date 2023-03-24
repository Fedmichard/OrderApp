#include "statemachine.h"
#include <iostream>

void StateMachine::add_state(state_reference latest_state, bool is_replacing_state) {
    // implementing add state method
    this->is_adding = true;
    this->is_replacing = is_replacing_state;
    this->new_states = std::move(new_states);
}

void StateMachine::remove_state() {
    // implementing remove state method
    this->is_removing = true;
}

void StateMachine::process_state_changes() {
    // processing our state changes method when removing
    if (this->is_removing && !this->current_states.empty()) {
        this->current_states.pop();

        if (!current_states.empty()) {
            // this->current_states.top()->start();
            std::cout << "Will replace with main menu" << std::endl;
        }
        this->is_removing = false;
    }

    if (this->is_adding) {
        if (!this->current_states.empty()) {
            if (this->is_replacing) {
                this->current_states.pop();
            } else {
                // this->current_states.top()->options();
                std::cout << "Will replace with options menu" << std::endl;
            }
        }
        this->current_states.push(std::move(this->new_states));
        this->current_states.top()->initialize_state();
        this->is_adding = false;
    }
}

state_reference &StateMachine::get_active_state() {
    // only interested in top state because it's the active state
    return this->current_states.top();
}