#ifndef GAME_AABB_H
#define GAME_AABB_H

#include "Vec2f.h"

class AABB {
    public:

    Vec2f dim;
    Vec2f pos;

    AABB(const Vec2f& dim) : dim(dim), pos(Vec2f()) {};

    void update(const Vec2f& pos) {
        this->pos = pos;
    }

    Vec2f getVN(const Vec2f& normal)  const
    {
        Vec2f res = pos;

        if (normal.x < 0)
        {
            res.x += dim.x;
        }
        if (normal.y < 0)
        {
            res.y += dim.y;
        }

        return res;
    }

    Vec2f getVP(const Vec2f& normal) const
    {
        Vec2f res = pos;

        if (normal.x > 0)
        {
            res.x += dim.x;
        }
        if (normal.y > 0)
        {
            res.y += dim.y;
        }

        return res;
    }
};


#endif //GAME_AABB_H
