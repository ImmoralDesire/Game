#ifndef GAME_VEC2F_H
#define GAME_VEC2F_H


class Vec2f {
    public:

    float x;
    float y;

    Vec2f() {};
    Vec2f(float x, float y) : x(x), y(y) {};
    virtual ~Vec2f();
};


#endif //GAME_VEC2F_H
