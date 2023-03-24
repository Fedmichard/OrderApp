#pragma once

class States{
public:
    virtual void initialize_state() = 0;
    virtual void handle_input() = 0;
    virtual void update(float) = 0;
    virtual void draw(float delta) = 0;
};